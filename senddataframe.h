#ifndef SENDDATAFRAME_H
#define SENDDATAFRAME_H

#include <QObject>
#include <QUdpSocket>
#include <vector>

class SendDataFrame {
public:
    SendDataFrame();        // Конструктор
    void Send(uint16_t can_id, uint8_t can_len, const std::vector<uint8_t>& payload);  // Метод відправки CAN повідомлення

private:
    QUdpSocket udpSocket;  // Сокет для UDP відправки
};

#endif // SENDDATAFRAME_H
