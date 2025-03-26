#ifndef CANTHREAD_H
#define CANTHREAD_H
#include <QThread>
class CANThread : public QThread
{
public:
    CANThread();
    void run() override;
    void stop();
    const std::queue<std::vector<uint8_t>>& messageQueue;

private:
    bool running;
    void PrintMessageQueue(const std::queue<std::vector<uint8_t>>& messageQueue);

};

#endif // CANTHREAD_H
