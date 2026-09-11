#include "biascalibration.h"
#include "qthread.h"
#include "scriptcommands.h"
#include "senddataframe.h"
#include "ui_biascalibration.h"
#include "lpsparameters.h"

#include <QElapsedTimer>
#include <QIntValidator>
#include <QMessageBox>
#include <QTimer>
#include <QEventLoop>

BiasCalibration::BiasCalibration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BiasCalibration)
{
    ui->setupUi(this);
    ui->lineEditTime->setValidator(new QIntValidator(this));
    ui->lineEditOffset1->setValidator(new QIntValidator(this));
    ui->lineEditOffset2->setValidator(new QIntValidator(this));
}

BiasCalibration::~BiasCalibration()
{
    delete ui;
}


void BiasCalibration::on_startButton_clicked()
{
    bool okTime, okOffset1, okOffset2;

    int time = ui->lineEditTime->text().trimmed().toInt(&okTime);
    int offset1 = ui->lineEditOffset1->text().trimmed().toInt(&okOffset1);
    int offset2 = ui->lineEditOffset2->text().trimmed().toInt(&okOffset2);

    if (okTime && okOffset1 && okOffset2) {
        startCalibration(time, offset1, offset2);

    } else {
        // Повідомлення про помилки
        QString errorMsg = "Error in fields:\n";
        if (!okTime) errorMsg += "- time\n";
        if (!okOffset1) errorMsg += "- offset1\n";
        if (!okOffset2) errorMsg += "- offset2\n";

        QMessageBox::warning(this, "Incorrect input", errorMsg);
    }
}

/**
 * @brief Виконує калібрування для компенсації дрейфу
 *
 * Функція виконує покроково заміри BiasH i BiasV і встановлює їх для
 * компенсації дрейфу
 *
 * @param timeSec  заданий час для замірів в сек
 * @param offset1  зміщення для BiasH
 * @param offset2  зміщення для BiasV
 */
void BiasCalibration::startCalibration(int timeSec, int offset1, int offset2)
{
    int timeForRecordMsec = timeSec * 1000;
     ui->labelComment->clear();

     // 1. Set platform to zero
     ScriptCommands::GetInstance().SetMode(BODY);
     QThread::msleep(10); // Затримка 10 мс
     ScriptCommands::GetInstance().SetAngleEncoder(0, 0);

     ui->labelComment->setText("Set platform to ZERO. Wait 10 sec");

     waitAndProgress(10000); //10000 очікування 10 сек з прогресбаром

     // 2. Set offset Δ1
     ScriptCommands::GetInstance().SetMode(INERT);
     QThread::msleep(10); // Затримка 10 мс
     sendCommandCalibration(offset1, offset1, 0);

     // 3. Wait timeForRecordMsec and record data to array
     ui->labelComment->setText(
         QString("Record data with Δ1=%1. Wait %2 s")
             .arg(offset1)
             .arg(timeSec)
         );
     MonitorResult result1 = startMonitoring(timeForRecordMsec);

     // 4. Set offset Δ2
     sendCommandCalibration(offset2, offset2, 0);

     // 5. Wait timeForRecordMsec and record data to array
     ui->labelComment->setText(
         QString("Record data with Δ2=%1. Wait %2 s")
             .arg(offset2)
             .arg(timeSec)
         );
     MonitorResult result2 = startMonitoring(timeForRecordMsec);

     // 6. Calculate Delta for H channel
     int biasH, biasV;
     Result resultBiasH = computeDelta(biasH, result1.valuesH, result2.valuesH, offset1, offset2);

     // 7. Calculate Delta for V channel
     Result resultBiasV = computeDelta(biasV, result1.valuesV, result2.valuesV, offset1, offset2);

     ui->lineEditBiasH->setText(QString::number(biasH));
     ui->lineEditBiasV->setText(QString::number(biasV));

     // 8. Error checking
     switch(resultBiasH)
     {
     case S_FAIL: ui->labelComment->setText("Error in H channel (b1=b2)"); return;
     case S_FAIL_OFFSET: ui->labelComment->setText("Error in H channel. Increase range (Δ1..Δ2) "); return;
         break;

     case S_OK:
         break;
     }

     switch(resultBiasV)
     {
     case S_FAIL: ui->labelComment->setText("Error in V channel (b1=b2)"); return;
     case S_FAIL_OFFSET: ui->labelComment->setText("Error in V channel. Increase range (Δ1..Δ2) "); return;
         break;

     case S_OK:
         break;
     }

     // 9. Apply
     sendCommandCalibration(biasH, biasV, 0);
     ui->labelComment->setText(
         QString("Apply calibration. Wait %1 s to compare")
             .arg(timeSec)
         );

     // 10. Compare
     compareMonitorValues(timeForRecordMsec);
     ui->labelComment->setText("Done");
}

/**
 * @brief Відображає процес у вигляді прогрес бару
 *
 * Функція запускає процес очікування і отображає цей процес у прогрес барі
 *
 * @param durationMs  час очікування в мс
 */
void BiasCalibration::waitAndProgress(int durationMs)
{
    const int steps = 100;
    int interval = durationMs / steps;

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(steps);
    ui->progressBar->setValue(0);

    QEventLoop loop;
    QTimer timer;
    int count = 0;

    QObject::connect(&timer, &QTimer::timeout, [&]() {
        count++;
        ui->progressBar->setValue(count);
        if (count >= steps) {
            loop.quit();
        }
    });

    timer.start(interval);
    loop.exec();  // блокуючий цикл, якого чекає до завершення 100 кроків
}

/**
 * @brief Передає команди для калібровки
 *
 * Функція передає значення на які відхилятися за заданий час
 *
 * @param dx, dy  зміщення по Х та Y
 * @param cmd     дія з параметром: 0 - встановити, 1 - зчитати
 */
void BiasCalibration::sendCommandCalibration(int dx, int dy, unsigned char cmd)
{
    int valX = 131071 + dx;
    int valY = 131071 + dy;

    std::vector<uint8_t> byteArray(4);

    // Отримуємо сінглтон
    SendDataFrame &sendDataFrame = SendDataFrame::getInstance();

    // ValX
    std::memcpy(byteArray.data(), &valX, sizeof(int)); // перетворення int в масив байтів
    std::vector<uint8_t> payload = {0x00, 0x11, 0xFF, cmd};
    payload.insert(payload.end(), byteArray.begin(), byteArray.end());
    sendDataFrame.AddCanFrame(0x519, 0x08, payload);

    // ValY
    std::memcpy(byteArray.data(), &valY, sizeof(int)); // перетворення int в масив байтів
    payload = {0x00, 0x31, 0xFF, cmd};
    payload.insert(payload.end(), byteArray.begin(), byteArray.end());
    sendDataFrame.AddCanFrame(0x519, 0x08, payload);
}

/**
 * @brief Запускає процес моніторингу даних з таймером для визначення дрейфу.
 *
 * Функція ініціалізує результат моніторингу, запускає QTimer з інтервалом 10 мс
 * і записує значення з AngleManager (X та Y) у масиви.
 * Прогрес відображається на progressBar.
 *
 * @param durationMs Тривалість моніторингу у мілісекундах.
 * @return MonitorResult Структура з накопиченими значеннями кутів по горизонталі (H) та вертикалі (V).
 */
BiasCalibration::MonitorResult BiasCalibration::startMonitoring(int durationMs)
{
    const int interval = 10; // milliseconds
    int stepCount = durationMs / interval; // кількість кроків
    int currentStep = 0; // поточний крок
    result.valuesH.clear();
    result.valuesV.clear();

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(stepCount);
    ui->progressBar->setValue(0);

    // // запуск таймера і моніторингу
    // elapsed.start();
    // qint64 startTime = elapsed.elapsed();

    // for (int i = 0; i < stepCount; ++i)
    // {
    //     // Зчитуємо поточні кути
    //     result.valuesH.append(LpsParameters::GetInstance().GetAngleX());
    //     result.valuesV.append(LpsParameters::GetInstance().GetAngleY());

    //     // Оновлюємо прогрес-бар, якщо є вікно
    //     QMetaObject::invokeMethod(ui->progressBar, [this, i, stepCount]() {
    //         ui->progressBar->setMinimum(0);
    //         ui->progressBar->setMaximum(stepCount);
    //         if (ui->progressBar->value() < ui->progressBar->maximum())
    //             ui->progressBar->setValue(i + 1);
    //     }, Qt::QueuedConnection);

    //     // Обчислюємо час затримки до наступного кроку
    //     qint64 nextTargetTime = startTime + ((i + 1) * interval);
    //     qint64 sleepTime = nextTargetTime - elapsed.elapsed();
    //     if (sleepTime > 0)
    //         QThread::msleep(static_cast<unsigned long>(sleepTime));

    //     // Щоб інтерфейс залишався чуйним
    //     QCoreApplication::processEvents();
    // }

    QEventLoop loop;
    QElapsedTimer timer;
    timer.start();

    std::function<void()> stepFunc;

    stepFunc = [&]() {
        // Зчитуємо кути
        result.valuesH.append(LpsParameters::GetInstance().GetAngleX());
        result.valuesV.append(LpsParameters::GetInstance().GetAngleY());

        // Оновлюємо прогрес-бар
        ui->progressBar->setValue(currentStep + 1);
        currentStep++;

        if (currentStep >= stepCount) {
            loop.quit();
            return;
        }

        // Обчислюємо точну затримку до наступного кроку
        qint64 expectedElapsed = currentStep * interval;
        qint64 actualElapsed = timer.elapsed();
        qint64 delay = expectedElapsed - actualElapsed;
        if (delay < 0) delay = 0;

        QTimer::singleShot(delay, stepFunc);
    };

    QTimer::singleShot(0, stepFunc); // початковий запуск
    loop.exec();

    return result;
}

 void BiasCalibration::startMonitoringAsync(int durationMs)
 {
//     const int interval = 10;
//     int stepCount = durationMs / interval;
//     int currentStep = 0;
//     result.valuesH.clear();
//     result.valuesV.clear();

//     ui->progressBar->setMinimum(0);
//     ui->progressBar->setMaximum(stepCount);
//     ui->progressBar->setValue(0);

//     monitorTimer = new QTimer(this); // створіть у конструкторі або тут
//     monitorTimer->setInterval(interval);

//     connect(monitorTimer, &QTimer::timeout, this, [=]() {
//         result.valuesH.append(LpsParameters::GetInstance().GetAngleX());
//         result.valuesV.append(LpsParameters::GetInstance().GetAngleY());

//         ui->progressBar->setValue(currentStep + 1);
//         currentStep++;

//         if (currentStep >= stepCount) {
//             monitorTimer->stop();
//             monitorTimer->deleteLater();
//             emit monitoringFinished(result); // передаємо результат
//         }
//     });

//     monitorTimer->start();
 }

/**
 * @brief Моніторінг кутів
 *
 * Функція накопичує в структуру result кути X i Y поки відраховує таймер
 *
 * @return MonitorResult Структура з накопиченими значеннями кутів по горизонталі (H) та вертикалі (V).
 */
Result BiasCalibration::computeDelta(int & bias, QVector<float> A1, QVector<float> A2, int offset1, int offset2)
{
    float delta = 0;
    float b1 = computeCoefficientB(A1);
    float b2 = computeCoefficientB(A2);
    float k = computeCoefficientB(QList<float>{ b1, b2 });

    if (k == 0) bias = 0;
    else bias = (int)(offset1 - b1 * (offset2 - offset1) / k);


    if(b1 == b2) return S_FAIL;
    else if(bias<offset1 || bias>offset2) return S_FAIL_OFFSET;
    else return S_OK;
}

float BiasCalibration::computeCoefficientB(QVector<float> A)
{
    float Sxy = 0, Sy = 0, Sx2 = 0;
    int n = A.count();
    float Sx = n * (n - 1) / 2;
    for (int i = 0; i < n; i++)
    {
        Sxy += i * A[i];
        Sy += A[i];
        Sx2 += i * i;
    }
    float b = (Sxy - Sx * Sy / n) / (Sx2 - Sx * Sx / n);
    return b;
}

/**
 * @brief Порівняти застосовані значення bias
 *
 * Функція накопичує в структуру result кути X i Y поки відраховує таймер
 * Вираховує коефіцієнти, які повинні бути близькими до нуля.
 *
 */
void BiasCalibration::compareMonitorValues(int durationInMsec)
{
    MonitorResult result3 = startMonitoring(durationInMsec);
    float b3_H = computeCoefficientB(result3.valuesH);
    float b3_V = computeCoefficientB(result3.valuesV);
    ui->lineEditBiasHVerify->setText(QString::number(b3_H, 'f', 4));
    ui->lineEditBiasVVerify->setText(QString::number(b3_V, 'f', 4));

}


/**
 * @brief Зберегти значення bias в пам'ять
 *
 * Функція зчитує з полів biasH i biasV значення і зберігає їх в пам'ять
 *
 */
void BiasCalibration::on_saveButton_clicked()
{
    bool okBiasH, okBiasV;
    int biasH = ui->lineEditBiasH->text().trimmed().toInt(&okBiasH);
    int biasV = ui->lineEditBiasV->text().trimmed().toInt(&okBiasV);

    if (okBiasH && okBiasV) {
        sendCommandCalibration(biasH, biasV, 0x02); // Save

    } else {
        // Повідомлення про помилки
        QString errorMsg = "Error in fields:\n";
        if (!okBiasH) errorMsg += "- biasH\n";
        if (!okBiasV) errorMsg += "- biasV\n";

        QMessageBox::warning(this, "Incorrect input", errorMsg);
    }

}

/**
 * @brief Застосувати значення bias без збереження в пам'ять
 *
 * Функція зчитує з полів biasH i biasV значення і застосовує їх
 *
 */
void BiasCalibration::on_setBiasButton_clicked()
{
    bool okBiasH, okBiasV;
    int biasH = ui->lineEditBiasH->text().trimmed().toInt(&okBiasH);
    int biasV = ui->lineEditBiasV->text().trimmed().toInt(&okBiasV);

    if (okBiasH && okBiasV) {
        sendCommandCalibration(biasH, biasV, 0x0); // Apply

    } else {
        // Повідомлення про помилки
        QString errorMsg = "Error in fields:\n";
        if (!okBiasH) errorMsg += "- biasH\n";
        if (!okBiasV) errorMsg += "- biasV\n";

        QMessageBox::warning(this, "Incorrect input", errorMsg);
    }
}


void BiasCalibration::on_checkButton_clicked()
{
    bool okTime;

    int time = ui->lineEditTime->text().trimmed().toInt(&okTime);
    if (okTime) {
        ui->labelComment->setText("Check in progress");
        compareMonitorValues(time*1000);
        ui->labelComment->setText("Done");

    } else {
        // Повідомлення про помилки
        QString errorMsg = "Error in fields:\n";
        if (!okTime) errorMsg += "- time\n";

        QMessageBox::warning(this, "Incorrect input", errorMsg);
    }
}

