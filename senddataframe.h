#ifndef SENDDATAFRAME_H
#define SENDDATAFRAME_H

#include <QObject>
#include <QUdpSocket>
#include <vector>

class SendDataFrame {
public:
    SendDataFrame();        // Конструктор
    void Send(uint16_t can_id, uint8_t can_len, const std::vector<uint8_t>& payload);  // Метод відправки CAN повідомлення'void SendDataFrame::CreateHeaderCannelloni(){
    //void CreateHeaderCannelloni(uint8_t lastByte);
    void AddCanFrame(uint16_t can_id, uint8_t can_len, const std::vector<uint8_t>& payload);
    void SendAllFrames(int countPacks);




private:
    QUdpSocket udpSocket;  // Сокет для UDP відправки
    std::vector<uint8_t> dataCanFrames;
    std::vector<uint8_t> CreateHeaderCannelloni(uint8_t countPacks);
    void ClearCanFrame();

};

#endif // SENDDATAFRAME_H
