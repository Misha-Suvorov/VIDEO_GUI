#ifndef CANBUS_H
#define CANBUS_H

#include <QObject>
#include <QUdpSocket>

class CanBus : public QObject {
    Q_OBJECT

public:
    explicit CanBus(QObject *parent = nullptr);
    ~CanBus();

private:
    QUdpSocket *socket;
    void setupSocket();

private slots:
    void readPacket();
};

#endif // CANBUS_H
