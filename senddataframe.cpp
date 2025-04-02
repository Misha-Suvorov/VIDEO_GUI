#include "senddataframe.h"
#include <QUdpSocket>
#include <QHostAddress>

SendDataFrame::SendDataFrame(QObject *parent)
    : QObject(parent), udpSocket(new QUdpSocket(this)) {}

void SendDataFrame::Send(uint16_t id, const std::vector<uint8_t>& pld) {
    std::vector<uint8_t> data;

    // Додаємо перші 4 байти: 02 10 08 00
    data.push_back(0x02);
    data.push_back(0x10);
    data.push_back(0x08);
    data.push_back(0x00);

    // ID (2 байти, MSB перший, LSB другий)
    data.push_back(static_cast<uint8_t>(id >> 8));  // ID MSB
    data.push_back(static_cast<uint8_t>(id & 0xFF)); // ID LSB

    // Довжина повідомлення (8 байт)
    data.push_back(0x08);

    // Заповнюємо залишкові байти (CAN повинен мати рівно 8 байтів)
    std::vector<uint8_t> payload = pld;
    while (payload.size() < 8) {
        payload.push_back(0x00);
    }

    // Додаємо payload
    data.insert(data.end(), payload.begin(), payload.end());

    // Конвертуємо в QByteArray для передачі через UDP
    QByteArray byteArray(reinterpret_cast<const char*>(data.data()), static_cast<int>(data.size()));

    // Надсилаємо дані через UDP
    udpSocket->writeDatagram(byteArray, QHostAddress("192.68.144.10"), 14500);
}

