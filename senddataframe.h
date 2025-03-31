#ifndef SENDDATAFRAME_H
#define SENDDATAFRAME_H

#include <QObject>
#include <QUdpSocket>
#include <vector>

class SendDataFrame : public QObject {
    Q_OBJECT

public:
    explicit SendDataFrame(QObject *parent = nullptr);
    void Send(uint16_t id, const std::vector<uint8_t>& pld);

private:
    QUdpSocket *udpSocket;
};

#endif // SENDDATAFRAME_H
