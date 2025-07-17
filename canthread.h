#ifndef CANTHREAD_H
#define CANTHREAD_H
#include <QMutex>
#include <QThread>
#include <cstdint>
#include <queue>
#include <vector>
class CANThread : public QThread
{
public:
    CANThread(QMutex *mutex, std::queue<std::vector<uint8_t>> *queue, QObject *parent = nullptr)
        : QThread(parent)
        , queueMutex(mutex)
        , messageQueue(queue)
        , running(false)
    {}
    void run() override;
    void stop();
    //const std::queue<std::vector<uint8_t>>& messageQueue;

private:
    QMutex *queueMutex;
    std::queue<std::vector<uint8_t>> *messageQueue;
    bool running;
    void ProcessMessage(const std::queue<std::vector<uint8_t>> &messageQueue);
};

#endif // CANTHREAD_H
