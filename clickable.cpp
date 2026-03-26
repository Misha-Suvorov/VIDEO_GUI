// ClickableLabel.cpp
// 1) Натиснув → запустився holdTimer.
// 2) Якщо відпустив до 500 мс → спрацював короткий клік (clicked + processClick).
// 3) Якщо тримаєш ≥ 500 мс → запускається repeatTimer, який викликає mouseHeld() кожні 50 мс.
// 4) Відпустив → обидва таймери стоп, енкодер скидається в 0.

#include "clickable.h"
#include "lpsparameters.h"
#include "pixeltoangleconverter.h"
#include "scriptcommands.h"

#include <QThread>
#include <QTimer>
#include <algorithm>
#include "qdebug.h"

ClickableLabel::ClickableLabel(QWidget *parent)
    : QLabel(parent)
      //converter(cv::Size2f(1,1), cv::Size2f(1,1), cv::Point(0,0), 1.0f)
{
    // Таймер для визначення "довгого натискання"
    holdTimer = new QTimer(this);
    holdTimer->setInterval(500); // 500 мс до події hold
    holdTimer->setSingleShot(true); // виконується лише один раз
    connect(holdTimer, &QTimer::timeout, this, &ClickableLabel::startRepeating);

    // Таймер для періодичних подій під час утримання
    repeatTimer = new QTimer(this);
    repeatTimer->setInterval(50); // плавне оновлення (20 Гц)
    connect(repeatTimer, &QTimer::timeout, this,  &ClickableLabel::mouseHeld);

    setFocusPolicy(Qt::StrongFocus); // дозвіл на отримання подій QKeyEvent

}



void ClickableLabel::setDebugLabel(QLabel *label)
{
    labelDebug = label;
}

// Викликається при натисканні кнопки миші
void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {

        emit pressed();              // ← одразу шлемо сигнал для перемикання Switch video

        mousePressed = true;

        lastClickPos = event->pos();   // зберігаємо координати кліку

        if(settings!=nullptr)
        {
            videoPos = settings->mapToVideoCoordinates(
                lastClickPos,            // клік у QLabel
                this->size(),            // розмір QLabel
                &settings->getConfig() // структура VideoConfig із VideoSettings
                );



            lastDeltaAngle = settings->getConverter().pixelToAngle(videoPos);  //mapClickToAngle(event->pos());

            if (!lastDeltaAngle.isNull()) {
                holdTimer->start(); // запускаємо відлік до події hold
            }

            QLabel::mousePressEvent(event);
        }
    }
}

// Викликається при відпусканні кнопки миші
void ClickableLabel::mouseReleaseEvent(QMouseEvent *event)
{
    if (mousePressed) {
        // Якщо користувач відпустив мишку ДО завершення holdTimer → короткий клік
        if (holdTimer->isActive()) {

            holdTimer->stop();


            emit clicked(lastDeltaAngle); // коротке натискання


            processClick();

        }

        repeatTimer->stop(); // зупиняємо повторюваний таймер
        //ScriptCommands::GetInstance().SetVoltageEncoder(0.0f, 0.0f); // при відпусканні — обнуляємо керування

        mousePressed = false;
    }
    QLabel::mouseReleaseEvent(event);
}

// Функція викликається один раз після 500 мс,
// запускає періодичний repeatTimer
void ClickableLabel::startRepeating()
{
    if (mousePressed) {
        repeatTimer->start();
    }
}

// Оновлюємо позицію кліку при натиснутій клавіші миші
void ClickableLabel::mouseMoveEvent(QMouseEvent *event)
{
    if (mousePressed) {
        lastClickPos = event->pos();

        if(settings!=nullptr){
            videoPos = settings->mapToVideoCoordinates(
                lastClickPos,            // клік у QLabel
                this->size(),            // розмір QLabel
                &settings->getConfig() // структура VideoConfig із VideoSettings
                );
        }

    }
    QLabel::mouseMoveEvent(event);
}



// Викликається кожні 50 мс, поки тримається кнопка миші
void ClickableLabel::mouseHeld()
{
    auto [voltageH, voltageV] = settings->getConverter().calculateVoltageNonlinear(videoPos, maxVoltage, isRotated);

    ScriptCommands::GetInstance().SetVoltageEncoder(voltageH, voltageV);
}


void ClickableLabel::processClick()
{
    if (lastDeltaAngle.isNull())
    {
        qDebug() << "Click outside video area";
        return;
    }

    switch(LpsParameters::GetInstance().GetModePlatform()){

    case INERT:{

        // В режимі INERT відбувається одиночний рух на крок, заданий в полі Step, при кліку мишкою в будь-якому місці на фреймі
        auto [voltageH, voltageV] = settings->getConverter().movePlatformInInertModeByStep(videoPos, isRotated, stepSize);

        ScriptCommands::GetInstance().SetVoltageEncoder(voltageH, voltageV);

        break;
    }

    case BODY:{

        // Рух в режимі BODY на новий кут = поточний кут + дельта відхилення від центру
        float currentAngleX = LpsParameters::GetInstance().GetAngleX();
        float newAngleX = (isRotated)? currentAngleX + lastDeltaAngle.x() :
                              currentAngleX - lastDeltaAngle.x();

        float currentAngleY = LpsParameters::GetInstance().GetAngleY();
        float newAngleY = (isRotated)? currentAngleY - lastDeltaAngle.y() :
                              currentAngleY + lastDeltaAngle.y();

        ScriptCommands::GetInstance().SetAngleEncoder(newAngleX, newAngleY);
        QThread::msleep(200);
        ScriptCommands::GetInstance().SetAngleEncoder(newAngleX, newAngleY);
        break;
    }

    case EARTH:
    {
        break;
    }

//     case TRACKING:{
//         // Передати позицію на відео фреймі програмі-трекінгу
//         lastRoiCenter = videoPos; //QPoint(x_original, y_original);

//         ScriptCommands::GetInstance().SetTrackingDot(videoPos.x(), videoPos.y());
// /*
//         int frameW = settings->getConfig().roi.width;
//         int frameH = settings->getConfig().roi.height;
//         int x0 = std::clamp((int)(videoPos.x() - roiTrackingSize / 2), 0, frameW - roiTrackingSize);
//         int y0 = std::clamp((int)(videoPos.y() - roiTrackingSize / 2), 0, frameH - roiTrackingSize);

//         cv::Rect newRoi(x0, y0, roiTrackingSize, roiTrackingSize);

//         trackingWorker->setTrackingROI(newRoi);
//         qDebug("Click processed, ROI sent to TrackingWorker: x=%d y=%d w=%d h=%d",
//                newRoi.x,
//                newRoi.y,
//                newRoi.width,
//                newRoi.height);
// */
//         break;
//     }
    case TRACKING:{
        // Позиція кліку в координатах відеокадру
        lastRoiCenter = videoPos;

        const int frameW = settings->getConfig().roi.width;
        const int frameH = settings->getConfig().roi.height;

        if (frameW <= 0 || frameH <= 0) {
            qDebug() << "Invalid frame size for normalized tracking:" << frameW << frameH;
            break;
        }

        const float nx = std::clamp(float(videoPos.x()) / float(frameW), 0.0f, 1.0f);
        const float ny = std::clamp(float(videoPos.y()) / float(frameH), 0.0f, 1.0f);


        qDebug() << "[TRACK dbg]"
                 << "videoPos =" << videoPos
                 << "cfg roi =" << settings->getConfig().roi.width << settings->getConfig().roi.height
                 << "normalized =" << nx << ny;

        ScriptCommands::GetInstance().SetTrackingDotNormalized(nx, ny);
        break;
    }

    }

    //QString msg = QString("newAngleY = %1").arg(newAngleY);
    //labelDebug->setText(msg);
}


void ClickableLabel::keyPressEvent(QKeyEvent *event)
{
    if (settings == nullptr)
        return QLabel::keyPressEvent(event);

    if (event->key() == Qt::Key_Up) {
        roiTrackingSize = std::min(roiTrackingSize + 10, 200);
        qDebug() << "ROI size increased to" << roiTrackingSize;

        if (!lastRoiCenter.isNull()) {
            int x0 = std::clamp(int(lastRoiCenter.x()) - roiTrackingSize / 2,
                                0,
                                settings->getConfig().roi.width - roiTrackingSize);
            int y0 = std::clamp(int(lastRoiCenter.y()) - roiTrackingSize / 2,
                                0,
                                settings->getConfig().roi.height - roiTrackingSize);
            cv::Rect newRoi(x0, y0, roiTrackingSize, roiTrackingSize);
            trackingWorker->setTrackingROI(newRoi);
            qDebug() << "Updated ROI sent due to size increase";
        }
        return; // обробили
    }

    if (event->key() == Qt::Key_Down) {
        roiTrackingSize = std::max(roiTrackingSize - 10, 10);
        qDebug() << "ROI size decreased to" << roiTrackingSize;

        if (!lastRoiCenter.isNull()) {
            int x0 = std::clamp(int(lastRoiCenter.x()) - roiTrackingSize / 2,
                                0,
                                settings->getConfig().roi.width - roiTrackingSize);
            int y0 = std::clamp(int(lastRoiCenter.y()) - roiTrackingSize / 2,
                                0,
                                settings->getConfig().roi.height - roiTrackingSize);
            cv::Rect newRoi(x0, y0, roiTrackingSize, roiTrackingSize);
            trackingWorker->setTrackingROI(newRoi);
            qDebug() << "Updated ROI sent due to size decrease";
        }
        return; // обробили
    }

    QLabel::keyPressEvent(event); // якщо це інша клавіша
}

