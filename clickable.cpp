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

ClickableLabel::ClickableLabel(QWidget *parent)
    : QLabel(parent),
      converter(cv::Size2f(1,1), cv::Size2f(1,1), cv::Point(0,0), 1.0f)
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

    //connect(repeatTimer, &QTimer::timeout, this, [this]() {
    //     if (mousePressed) {
    //         auto [voltageH, voltageV] = calculateVoltage(lastClickPos);
    //         emit voltageChanged(voltageH, voltageV);
    //     }
    //});
}

void ClickableLabel::setVideoConfig(VideoConfig videoConfig)
{
    this->videoConfig = videoConfig;

    roiSize = cv::Size2f(videoConfig.roi.width, videoConfig.roi.height);

    fov = cv::Size2f(FOVWidth, FOVHeight);

    opticalCenter = cv::Point(roiSize.width/2, roiSize.height/2);
    if(!isRotated) opticalCenter = videoConfig.opticalCenter;
    else { //Перевертаємо центр якщо зображення перевернуто
        float cx = roiSize.width  / 2.0;
        float cy = roiSize.height / 2.0;
        opticalCenter.x = 2*cx - videoConfig.opticalCenter.x;
        opticalCenter.y = 2*cy - videoConfig.opticalCenter.y;
    }

    converter = PixelToAngleConverter(roiSize, fov, opticalCenter, nonlinearFactor);
}

void ClickableLabel::setVideoFrameSize(int width, int height)
{
    videoFrameWidth = width;
    videoFrameHeight = height;
}

void ClickableLabel::setFOV(bool isSwitched, bool isRotated)
{
    this->isSwitched = isSwitched;
    this->isRotated = isRotated;
    if(isSwitched)
    {
        FOVWidth = videoConfig.fovVideo2.width; //0.56f; //34`
        FOVHeight = videoConfig.fovVideo2.height; // 0.416f; //25`
        nonlinearFactor = videoConfig.nonlinearFactor2;
    }
    else
    {
        FOVWidth = videoConfig.fovVideo1.width; // 8;
        FOVHeight = videoConfig.fovVideo1.height; //6;
        nonlinearFactor = videoConfig.nonlinearFactor1;
    }
}

void ClickableLabel::setDebugLabel(QLabel *label)
{
    labelDebug = label;
}

// Викликається при натисканні кнопки миші
void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {

        emit pressed();              // ← одразу шлемо сигнал для перемикання

        mousePressed = true;

        lastClickPos = event->pos();   // зберігаємо координати кліку
        lastDeltaAngle = mapClickToAngle(event->pos());

        if (!lastDeltaAngle.isNull()) {
            holdTimer->start(); // запускаємо відлік до події hold
        }

        QLabel::mousePressEvent(event);

        // if (lastDeltaAngle.isNull())
        // {
        //     qDebug() << "Click outside video area";
        //     return;
        // }

        // float currentAngleX = LpsParameters::GetInstance().GetAngleX();
        // float newAngleX = (isRotated)? currentAngleX + deltaAngle.x() : currentAngleX - deltaAngle.x();

        // float currentAngleY = LpsParameters::GetInstance().GetAngleY();
        // float newAngleY = (isRotated)? currentAngleY - deltaAngle.y() : currentAngleY + deltaAngle.y();

        // ScriptCommands::GetInstance().SetAngleEncoder(newAngleX, newAngleY);
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
    }
    QLabel::mouseMoveEvent(event);
}



// Викликається кожні 50 мс, поки тримається кнопка миші
void ClickableLabel::mouseHeld()
{
    //PixelToAngleConverter converter(roiSize, fov, opticalCenter, nonlinearFactor);
    QPointF videoPos = scaleClick(lastClickPos);
    auto [voltageH, voltageV] = converter.calculateVoltageNonlinear(videoPos, maxVoltage, isRotated);

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

        auto [voltageH, voltageV] = converter.movePlatformInInertModeByStep(lastClickPos, isRotated, stepSize);

        ScriptCommands::GetInstance().SetVoltageEncoder(voltageH, voltageV);

        break;
    }
    case BODY:{

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
    case TRACKING:
        break;
    }

    //QString msg = QString("newAngleY = %1").arg(newAngleY);
    //labelDebug->setText(msg);
}



QPointF ClickableLabel::mapClickToAngle(const QPoint &clickPos)
{
    if (videoFrameWidth <= 0 || videoFrameHeight <= 0)
        return QPointF();

    auto[videoX, videoY] = scaleClick(clickPos);


    //PixelToAngleConverter converter(roiSize, fov, opticalCenter, nonlinearFactor);

    QPointF deltaAngle = converter.pixelToAngle(QPoint(videoX, videoY));  //clickPos);
    //QPointF deltaAngle = converter.pixelToAngle(QPoint(alignedX, alignedY));

    QString msg = QString("fy = %1, fz = %2; frame: w = %3, h = %4; X = %5 px, Y = %6 px")
                      .arg(deltaAngle.x())
                      .arg(deltaAngle.y())
                      .arg(videoFrameWidth) //videoWidthOnLabel)
                      .arg(videoFrameHeight) //videoHeightOnLabel)
                      .arg(videoX) //clickPos.x())
                      .arg(videoY) //clickPos.y())
        ;
    labelDebug->setText(msg);

    return deltaAngle;
}

QPointF ClickableLabel::scaleClick(const QPoint &clickPos)
{
    double frameW = videoConfig.roi.width;   // 702
    double frameH = videoConfig.roi.height;  // 566

    int labelW = this->width();
    int labelH = this->height();

    double labelAspect = static_cast<double>(labelW) / labelH;
    double frameAspect = frameW / frameH;

    double scale;

    if (labelAspect > frameAspect)
    {
        // QLabel ширший — зображення вписане по висоті
        scale = static_cast<double>(labelH) / frameH;
        //double displayedW = frameW * scale;
    }
    else
    {
        // QLabel вищий — зображення вписане по ширині
        scale = static_cast<double>(labelW) / frameW;
        //double displayedH = frameH * scale;
    }

    // Конвертація у координати відео
    double videoX = (clickPos.x()) / scale;
    double videoY = (clickPos.y()) / scale;
    return { videoX, videoY };
}




