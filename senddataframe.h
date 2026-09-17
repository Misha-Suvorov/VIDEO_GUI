#ifndef SENDDATAFRAME_H
#define SENDDATAFRAME_H

#include <QUdpSocket>

#include <cstdint>
#include <vector>

class SendDataFrame
{
public:
    static SendDataFrame &getInstance();

    /*
     * Відправлення одного CAN-повідомлення.
     *
     * Порт визначається автоматично:
     *
     * tracking-пакети CAN ID 0x198:
     *   parameter 0x00, 0x02, 0x03, 0x04
     *   -> UDP 14502
     *
     * усі інші пакети:
     *   -> UDP 14500
     */
    void Send(
        uint16_t can_id,
        uint8_t can_len,
        const std::vector<uint8_t> &payload
        );

    /*
     * Додати CAN-повідомлення до черги.
     *
     * Tracking і звичайні повідомлення автоматично
     * потрапляють у різні черги.
     */
    void AddCanFrame(
        uint16_t can_id,
        uint8_t can_len,
        const std::vector<uint8_t> &payload
        );

    /*
     * Відправити накопичені повідомлення:
     *
     * звичайна черга -> UDP 14500;
     * tracking-черга -> UDP 14502.
     */
    void SendAllFrames();

    /*
     * Загальна кількість пакетів в обох чергах.
     */
    int GetDataFrameLen();

private:
    SendDataFrame();

    SendDataFrame(
        const SendDataFrame &
        ) = delete;

    SendDataFrame &operator=(
        const SendDataFrame &
        ) = delete;

    /*
     * Формування заголовка Cannelloni:
     *
     * byte 0: version
     * byte 1: opcode
     * byte 2: sequence number
     * byte 3: count MSB
     * byte 4: count LSB
     */
    std::vector<uint8_t> CreateHeaderCannelloni(
        uint8_t countPacks
        );

    /*
     * Визначення, чи належить повідомлення
     * до FOV, ROI або координат tracking.
     */
    bool isTrackingFrame(
        uint16_t can_id,
        const std::vector<uint8_t> &payload
        ) const;

    /*
     * Додати один CAN-кадр у заданий буфер.
     */
    void appendCanFrame(
        std::vector<uint8_t> &frames,
        uint16_t &frameCount,
        uint16_t can_id,
        uint8_t can_len,
        const std::vector<uint8_t> &payload
        );

    /*
     * Відправити один CAN-кадр у форматі Cannelloni.
     */
    void sendSingleFrame(
        uint16_t can_id,
        uint8_t can_len,
        const std::vector<uint8_t> &payload,
        quint16 udpPort
        );

    /*
     * Відправити накопичену групу CAN-кадрів.
     */
    void sendFrameBatch(
        std::vector<uint8_t> &frames,
        uint16_t &frameCount,
        quint16 udpPort
        );

    /*
     * Очистити обидві черги.
     */
    void ClearCanFrame();

private:
    static constexpr quint16 kCannelloniPort = 14500;
    static constexpr quint16 kTrackingPort = 14502;

    static constexpr uint16_t kTrackingCanId = 0x198;

    QUdpSocket udpSocket;

    /*
     * Звичайні CAN-пакети:
     * платформа, лазер, далекомір тощо.
     */
    std::vector<uint8_t> dataCanFrames;
    uint16_t countPacks = 0;

    /*
     * Тільки:
     * координати, ROI, FOV H, FOV V.
     */
    std::vector<uint8_t> trackingCanFrames;
    uint16_t trackingCountPacks = 0;

    uint8_t seqNumber = 0x01;
};

#endif // SENDDATAFRAME_H