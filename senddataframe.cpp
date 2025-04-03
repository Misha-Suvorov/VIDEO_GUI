#include "senddataframe.h"
#include <QHostAddress>
#include <iostream>
#include <cstring>

SendDataFrame::SendDataFrame() {}

// void SendDataFrame::Send(uint16_t can_id, const std::vector<uint8_t>& payload) {
//     std::vector<uint8_t> data;

//     // Структура CAN кадру
//     struct can_frame {
//         uint32_t can_id;  // CAN ID (4 байти)
//         uint8_t can_dlc;  // Data Length Code (скільки байтів в payload)
//         uint8_t data[8];  // Дані повідомлення (макс. 8 байт)
//     };

//     struct can_frame frame;
//     frame.can_id = can_id;  // Установка CAN ID
//     frame.can_dlc = payload.size() > 8 ? 8 : payload.size();  // Обмеження на 8 байт
//     std::memcpy(frame.data, payload.data(), frame.can_dlc);  // Копіюємо payload в кадр

//     // Конвертуємо структуру в QByteArray для UDP
//     QByteArray byteArray(reinterpret_cast<const char*>(&frame), sizeof(frame));

//     // Відправляємо через UDP на IP 192.168.144.10, порт 14500
//     udpSocket.writeDatagram(byteArray, QHostAddress("192.168.144.10"), 14500);

//     std::cout << "Відправлено через UDP: ID=" << std::hex << can_id << " [";
//     for (int i = 0; i < frame.can_dlc; i++) {
//         printf(" %02X", frame.data[i]);
//     }
//     std::cout << " ]" << std::endl;
// }



void SendDataFrame::Send(uint16_t can_id, const std::vector<uint8_t>& payload) {
    std::vector<uint8_t> data;

    // Додаємо Header: 0x02 0x00 0x6E 0x00 0x01
    data.push_back(0x02);
    data.push_back(0x00);
    data.push_back(0x6E);
    data.push_back(0x00);
    data.push_back(0x01);

    // Додаємо адресу CAN кадру: 0x00 0x00 0x02 0x38
    data.push_back(0x00);
    data.push_back(0x00);
    data.push_back(0x02);
    data.push_back(0x38);

    // Додаємо Count byte: 0x08 (8 байт в повідомленні)
    data.push_back(0x08);

    // Додаємо payload
    data.insert(data.end(), payload.begin(), payload.end());

    // Конвертуємо в QByteArray для UDP
    QByteArray byteArray(reinterpret_cast<const char*>(data.data()), static_cast<int>(data.size()));

    // Відправляємо дані через UDP на IP 192.168.144.10, порт 14500
    udpSocket.writeDatagram(byteArray, QHostAddress("192.168.144.10"), 14500);

    std::cout << "Відправлено через UDP: ID=" << std::hex << can_id << " [";
    for (size_t i = 0; i < data.size(); i++) {
        printf(" %02X", data[i]);
    }
    std::cout << " ]" << std::endl;
}
