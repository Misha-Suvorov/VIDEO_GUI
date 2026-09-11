#include "senddataframe.h"

#include <QByteArray>
#include <QDebug>
#include <QHostAddress>

#include <cstdio>
#include <iostream>

SendDataFrame::SendDataFrame()
{
}

SendDataFrame &SendDataFrame::getInstance()
{
    static SendDataFrame instance;
    return instance;
}

std::vector<uint8_t>
SendDataFrame::CreateHeaderCannelloni(
    uint8_t countPacks)
{
    std::vector<uint8_t> header;

    /*
     * Заголовок Cannelloni:
     *
     * 02       version
     * 00       DATA frame
     * XX       sequence number
     * 00 XX    number of CAN frames
     */

    header.push_back(0x02);
    header.push_back(0x00);
    header.push_back(seqNumber);
    header.push_back(0x00);
    header.push_back(countPacks);

    /*
     * Збільшення sequence number
     * з переходом FF -> 01.
     */
    seqNumber =
        (seqNumber == 0xFF)
            ? 0x01
            : static_cast<uint8_t>(
                  seqNumber + 1
                  );

    return header;
}

bool SendDataFrame::isTrackingFrame(
    uint16_t can_id,
    const std::vector<uint8_t> &payload) const
{
    /*
     * Усі потрібні tracking-команди
     * мають CAN ID 0x198.
     */
    if (can_id != kTrackingCanId) {
        return false;
    }

    /*
     * У payload:
     *
     * byte 0 = CNT/PART;
     * byte 1 = ID параметра.
     */
    if (payload.size() < 2) {
        return false;
    }

    const uint8_t parameterId = payload[1];

    switch (parameterId) {
    case 0x00:
        /*
         * Координати точки:
         * 00 00 0D 00 XX XX YY YY
         */
        return true;

    case 0x01:
        /*
         * Скидання захоплення:
         * 00 01 00 00 00 00 00 00
         */
        return true;

    case 0x02:
        /*
         * Розмір ROI:
         * 00 02 00 00 XX XX 00 00
         */
        return true;

    case 0x03:
        /*
         * FOV горизонтальне:
         * 00 03 02 00 XX XX XX XX
         */
        return true;

    case 0x04:
        /*
         * FOV вертикальне:
         * 00 04 02 00 XX XX XX XX
         */
        return true;

    default:

        return false;
    }
}

void SendDataFrame::appendCanFrame(
    std::vector<uint8_t> &frames,
    uint16_t &frameCount,
    uint16_t can_id,
    uint8_t can_len,
    const std::vector<uint8_t> &payload)
{
    const uint8_t can_id_high =
        static_cast<uint8_t>(
            (can_id >> 8) & 0xFF
            );

    const uint8_t can_id_low =
        static_cast<uint8_t>(
            can_id & 0xFF
            );

    /*
     * CAN frame у форматі Cannelloni:
     *
     * byte 0..3: CAN ID
     * byte 4:    DLC
     * byte 5..:  CAN payload
     */

    frames.push_back(0x00);
    frames.push_back(0x00);
    frames.push_back(can_id_high);
    frames.push_back(can_id_low);

    frames.push_back(can_len);

    frames.insert(
        frames.end(),
        payload.begin(),
        payload.end()
        );

    ++frameCount;
}

void SendDataFrame::AddCanFrame(
    uint16_t can_id,
    uint8_t can_len,
    const std::vector<uint8_t> &payload)
{
    /*
     * Формат пакета не змінюється.
     * Змінюється тільки вибір черги.
     */
    if (isTrackingFrame(can_id, payload)) {
        appendCanFrame(
            trackingCanFrames,
            trackingCountPacks,
            can_id,
            can_len,
            payload
            );

        qDebug()
            << "[CAN queue]"
            << "tracking packet"
            << "CAN ID = 0x"
            << Qt::hex
            << can_id
            << "parameter = 0x"
            << payload[1]
            << "UDP port ="
            << Qt::dec
            << kTrackingPort;

        return;
    }

    appendCanFrame(
        dataCanFrames,
        countPacks,
        can_id,
        can_len,
        payload
        );
}

void SendDataFrame::ClearCanFrame()
{
    dataCanFrames.clear();
    countPacks = 0;

    trackingCanFrames.clear();
    trackingCountPacks = 0;
}

int SendDataFrame::GetDataFrameLen()
{
    return static_cast<int>(
        countPacks +
        trackingCountPacks
        );
}

void SendDataFrame::sendFrameBatch(
    std::vector<uint8_t> &frames,
    uint16_t &frameCount,
    quint16 udpPort)
{
    if (frameCount == 0 ||
        frames.empty()) {

        return;
    }

    /*
     * У поточній архітектурі кількість
     * пакетів зберігається одним байтом.
     */
    const uint8_t packetCount =
        static_cast<uint8_t>(
            frameCount
            );

    const std::vector<uint8_t> header =
        CreateHeaderCannelloni(
            packetCount
            );

    /*
     * Формуємо окремий пакет, щоб не додавати
     * заголовок безпосередньо у постійний буфер.
     */
    std::vector<uint8_t> packet;

    packet.reserve(
        header.size() +
        frames.size()
        );

    packet.insert(
        packet.end(),
        header.begin(),
        header.end()
        );

    packet.insert(
        packet.end(),
        frames.begin(),
        frames.end()
        );

    const QByteArray byteArray(
        reinterpret_cast<const char *>(
            packet.data()
            ),
        static_cast<int>(
            packet.size()
            )
        );

    const qint64 sent =
        udpSocket.writeDatagram(
            byteArray,
            QHostAddress(
                QStringLiteral(
                    "192.168.144.10"
                    )
                ),
            udpPort
            );

    if (sent != byteArray.size()) {
        qWarning()
        << "[UDP TX ERROR]"
        << "port ="
        << udpPort
        << "sent ="
        << sent
        << "expected ="
        << byteArray.size()
        << "error ="
        << udpSocket.errorString();
    }
    else {
        qDebug().noquote()
        << QString(
               "[UDP TX OK] "
               "port=%1 frames=%2 bytes=%3 data=[%4]"
               )
                .arg(udpPort)
                .arg(frameCount)
                .arg(sent)
                .arg(
                    QString::fromLatin1(
                        byteArray
                            .toHex(' ')
                            .toUpper()
                        )
                    );
    }

    std::cout
        << "Send by UDP port="
        << udpPort
        << " Count="
        << frameCount
        << " [";

    for (const uint8_t byte : packet) {
        std::printf(
            " %02X",
            byte
            );
    }

    std::cout << " ]" << std::endl;

    frames.clear();
    frameCount = 0;
}

void SendDataFrame::SendAllFrames()
{
    /*
     * Звичайні повідомлення:
     * Cannelloni service, UDP 14500.
     */
    sendFrameBatch(
        dataCanFrames,
        countPacks,
        kCannelloniPort
        );

    /*
     * Координати, ROI, FOV:
     * gimbal_click, UDP 14502.
     */
    sendFrameBatch(
        trackingCanFrames,
        trackingCountPacks,
        kTrackingPort
        );
}

void SendDataFrame::sendSingleFrame(
    uint16_t can_id,
    uint8_t can_len,
    const std::vector<uint8_t> &payload,
    quint16 udpPort)
{
    std::vector<uint8_t> data;

    const std::vector<uint8_t> header =
        CreateHeaderCannelloni(1);

    data.insert(
        data.end(),
        header.begin(),
        header.end()
        );

    const uint8_t can_id_high =
        static_cast<uint8_t>(
            (can_id >> 8) & 0xFF
            );

    const uint8_t can_id_low =
        static_cast<uint8_t>(
            can_id & 0xFF
            );

    /*
     * CAN ID у форматі Cannelloni.
     */
    data.push_back(0x00);
    data.push_back(0x00);
    data.push_back(can_id_high);
    data.push_back(can_id_low);

    /*
     * DLC.
     */
    data.push_back(can_len);

    /*
     * Payload додається без жодної зміни.
     */
    data.insert(
        data.end(),
        payload.begin(),
        payload.end()
        );

    const QByteArray byteArray(
        reinterpret_cast<const char *>(
            data.data()
            ),
        static_cast<int>(
            data.size()
            )
        );

    const qint64 sent =
        udpSocket.writeDatagram(
            byteArray,
            QHostAddress(
                QStringLiteral(
                    "192.168.144.10"
                    )
                ),
            udpPort
            );

    if (sent != byteArray.size()) {
        qWarning()
        << "[UDP TX ERROR]"
        << "CAN ID = 0x"
        << Qt::hex
        << can_id
        << "port ="
        << Qt::dec
        << udpPort
        << "sent ="
        << sent
        << "expected ="
        << byteArray.size()
        << "error ="
        << udpSocket.errorString();

        return;
    }

    qDebug().noquote()
        << QString(
               "[UDP TX OK] "
               "CAN_ID=0x%1 port=%2 bytes=%3 data=[%4]"
               )
               .arg(
                   can_id,
                   3,
                   16,
                   QLatin1Char('0')
                   )
               .arg(udpPort)
               .arg(sent)
               .arg(
                   QString::fromLatin1(
                       byteArray
                           .toHex(' ')
                           .toUpper()
                       )
                   );

    std::cout
        << "Send by UDP port="
        << udpPort
        << " ID="
        << std::hex
        << can_id
        << " [";

    for (const uint8_t byte : data) {
        std::printf(
            " %02X",
            byte
            );
    }

    std::cout << " ]" << std::endl;
}

void SendDataFrame::Send(
    uint16_t can_id,
    uint8_t can_len,
    const std::vector<uint8_t> &payload)
{
    /*
     * Автоматична маршрутизація.
     *
     * Жоден виклик у ClickableLabel
     * або ScriptCommands змінювати не потрібно.
     */
    const quint16 udpPort =
        isTrackingFrame(
            can_id,
            payload
            )
            ? kTrackingPort
            : kCannelloniPort;

    sendSingleFrame(
        can_id,
        can_len,
        payload,
        udpPort
        );
}