// canparserworker.cpp
#include "canparserworker.h"
#include <QDebug>
#include "canmessagegeneric.h"
#include "lpsparameters.h"

CANParserWorker::CANParserWorker(QObject *parent)
    : QObject(parent)
{}

void CANParserWorker::enqueueMessage(const std::vector<uint8_t> &message)
{
    QMutexLocker locker(&mutex);
    queue.enqueue(message);
}

void CANParserWorker::process()
{

    while (running)
    {
        mutex.lock();
        if (queue.isEmpty()) {
            mutex.unlock();
            QThread::msleep(10);  // Щоб не грузити CPU
            continue;
        }

        std::vector<uint8_t> message = queue.dequeue();
        mutex.unlock();

        // Тут розбір повідомлення:
        try {
            // 🎯 Actual message processing:
             CanMessageGeneric canMessage(message);
            switch (canMessage.Message.TYPE) {
            case ParamType::NoneType:
                //LpsParameters::GetInstance().SetLaserError(canMessage.GetByteFromPayload());
                break;
            case ParamType::Float:
                canMessage.ParseFloat();
                break;
            case ParamType::ULong:
                canMessage.ParseULong();
                break;
            default:
                break;
            }

            //qDebug() << "Parsing CAN message in thread. Size:" << message.size();
            emit messageParsed();
        } catch (const std::exception &e) {
            emit parseError(QString("Parser error: %1").arg(e.what()));
        }
    }
}
