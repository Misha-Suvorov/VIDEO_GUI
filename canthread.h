#ifndef CANTHREAD_H
#define CANTHREAD_H
#include <QThread>
#include <QMutex>
class CANThread : public QThread
{
public:
    CANThread(QMutex *mutex, std::queue<std::vector<uint8_t>> *queue, QObject *parent = nullptr)
        : QThread(parent), queueMutex(mutex), messageQueue(queue), running(false) {}
    void run() override;
    void stop();
    //const std::queue<std::vector<uint8_t>>& messageQueue;

private:
    QMutex *queueMutex;
    std::queue<std::vector<uint8_t>> *messageQueue;
    bool running;
    void PrintMessageQueue(const std::queue<std::vector<uint8_t>>& messageQueue);
    void ProcessMessage(const std::queue<std::vector<uint8_t>>& messageQueue);


};

#endif // CANTHREAD_H
