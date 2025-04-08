#include "senddataframe.h"
#include <QHostAddress>
#include <iostream>
#include <cstring>

SendDataFrame::SendDataFrame() {}





void SendDataFrame::Send(uint16_t can_id, uint8_t can_len, const std::vector<uint8_t>& payload) {
    std::vector<uint8_t> data;

    uint8_t can_id_high = (can_id >> 8) & 0xFF;
    uint8_t can_id_low  = can_id & 0xFF;

    // Додаємо Header: 0x02 0x00 0x6E 0x00 0x01
    data.push_back(0x02);
    data.push_back(0x00);
    data.push_back(0x6E);
    data.push_back(0x00);
    data.push_back(0x01);



    // Додаємо адресу CAN кадру: 0x00 0x00 0x02 0x38
    data.push_back(0x00);
    data.push_back(0x00);
    data.push_back(can_id_high);
    data.push_back(can_id_low);

    // Додаємо Count byte: 0x08 (8 байт в повідомленні)
    data.push_back(can_len);

    data.insert(data.end(), payload.begin(), payload.end());

    QByteArray byteArray(reinterpret_cast<const char*>(data.data()), static_cast<int>(data.size()));

    udpSocket.writeDatagram(byteArray, QHostAddress("192.168.144.10"), 14500);

    std::cout << "Відправлено через UDP: ID=" << std::hex << can_id << " [";
    for (size_t i = 0; i < data.size(); i++) {
        printf(" %02X", data[i]);
    }
    std::cout << " ]" << std::endl;
}


