#include "senddataframe.h"
#include <QUdpSocket>
#include <QHostAddress>

SendDataFrame::SendDataFrame(QObject *parent)
    : QObject(parent), udpSocket(new QUdpSocket(this)) {}

void SendDataFrame::Send(uint16_t id, const std::vector<uint8_t>& pld) {
    std::vector<uint8_t> data;

    data.push_back(0); // ID 0 byte
    data.push_back(0); // ID 1 byte
    uint8_t id_lsb = static_cast<uint8_t>(id & 0xFF);
    uint8_t id_msb = static_cast<uint8_t>(id >> 8);
    data.push_back(id_lsb); // ID LSB 2 byte
    data.push_back(id_msb); // ID MSB 3 byte

    data.push_back(0x8); // Завжди 8 байтів у payload

    // Додаємо payload
    data.insert(data.end(), pld.begin(), pld.end());

    // Конвертуємо в QByteArray для передачі через UDP
    QByteArray byteArray(reinterpret_cast<const char*>(data.data()), static_cast<int>(data.size()));

    // Надсилаємо дані через UDP
    udpSocket->writeDatagram(byteArray, QHostAddress("192.68.144.10"), 14500);
}
