#pragma once

#include <vector>
#include <cstring>
#include <cstdint>
#include <queue>
#include <QByteArray>

class CannelloniFrame
{
public:
    uint8_t Version;
    uint8_t OPCode;
    uint8_t SeqNo;
    uint16_t Count;

    struct CANMessage {
        uint32_t can_id;
        uint8_t len;
        std::vector<uint8_t> raw_data;
    };

    std::vector<CANMessage> messages;

    CannelloniFrame(const QByteArray& data); // Тепер приймає QByteArray
    void PrintCANMessages() const;
    void PrintMessageQueue() const;

    const std::queue<std::vector<uint8_t>>& GetMessageQueue() const {
        return messageQueue;
    }

protected:
    void ParseCANMessages(const std::vector<uint8_t>& bytes);
    std::queue<std::vector<uint8_t>> messageQueue;

};
