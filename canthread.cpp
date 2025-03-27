#include "canthread.h"
#include "mainwindow.h"

//CANThread::CANThread() {}

void CANThread::run(){
    running = true;
    while (running) {
        QMutexLocker locker(queueMutex); // Lock the mutex to safely access the queue
        if (!messageQueue->empty()) {
            PrintMessageQueue(*messageQueue);  // Display the messages in the queue
        }
        QThread::msleep(100);
    }
}

void CANThread::PrintMessageQueue(const std::queue<std::vector<uint8_t>>& messageQueue) {
    int messageCount = 0;
    std::queue<std::vector<uint8_t>> queueCopy = messageQueue; // Copy the queue to iterate
    while (!queueCopy.empty()) {
        std::vector<uint8_t> message = queueCopy.front();
        queueCopy.pop();

        // std::cout << "Message CANTHREAD" << ++messageCount << " (" << message.size() << " bytes): ";
        // for (uint8_t byte : message) {
        //     std::cout << "0x" << std::hex << (int)byte << " ";
        // }
        // std::cout << std::dec << "\n"; // Reset to decimal format
        qDebug() << "Message CANTHREAD" << ++messageCount << " (" << message.size() << " bytes): " ;
        QString hexString;
        for (uint8_t byte : message) {
            hexString += QString::asprintf("0x%02X ", byte); // Форматування байта у hex
        }
        qDebug() << hexString.trimmed(); // Виводимо результат в один рядок


    }
}

void CANThread::stop(){
    running = false;
    wait();
}
