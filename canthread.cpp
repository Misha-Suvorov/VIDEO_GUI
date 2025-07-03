#include "canthread.h"
#include "canmessagegeneric.h"
#include "mainwindow.h"

//CANThread::CANThread() {}

// void CANThread::run(){
//     running = true;
//     while (running) {
//         QMutexLocker locker(queueMutex); // Lock the mutex to safely access the queue
//         if (!messageQueue->empty()) {
//             //PrintMessageQueue(*messageQueue);  // Display the messages in the queue
//             ProcessMessage(*messageQueue);
//         }
//         //QThread::msleep(100);
//     }
// }

void CANThread::run()
{
    running = true;
    while (running) {
        std::queue<std::vector<uint8_t>> localQueue;

        {
            QMutexLocker locker(queueMutex);
            if (!messageQueue->empty()) {
                std::swap(localQueue, *messageQueue);
            }
        }

        if (!localQueue.empty()) {
            ProcessMessage(localQueue);
        }

        msleep(10); // важливо, щоб дати іншим потокам виконатись
    }
}

// void CANThread::ProcessMessage(const std::queue<std::vector<uint8_t>>& messageQueue){

//     //QMutexLocker locker(queueMutex);// Lock the mutex for thread-safe access

//     std::queue<std::vector<uint8_t>> queueCopy = messageQueue;

//     while (!queueCopy.empty()) {
//         std::vector<uint8_t> message = queueCopy.front();
//         queueCopy.pop();

//         CanMessageGeneric canMessage(message);
//         switch (canMessage.Message.TYPE) {
//         case ParamType::NoneType:
//             LpsParameters::GetInstance().SetLaserError(canMessage.GetByteFromPayload());
//             break;
//         case ParamType::Float:
//             canMessage.ParseFloat();
//             break;
//         case ParamType::ULong:
//             canMessage.ParseULong();
//             break;
//         default:
//             break;
//         }
//     }
// }

void CANThread::ProcessMessage(const std::queue<std::vector<uint8_t>> &queueCopy)
{
    std::queue<std::vector<uint8_t>> localCopy = queueCopy;

    while (!localCopy.empty()) {
        std::vector<uint8_t> message = localCopy.front();
        localCopy.pop();

        CanMessageGeneric canMessage(message);
        switch (canMessage.Message.TYPE) {
        case ParamType::NoneType:
            LpsParameters::GetInstance().SetLaserError(canMessage.GetByteFromPayload());
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
    }
}

void CANThread::stop()
{
    running = false;
    wait();
}
