#pragma once

#include <vector>
#include <cstring>
#include <cstdint>
#include <queue>

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
        //uint8_t flags;
        std::vector<uint8_t> raw_data;
    };

    std::vector<CANMessage> messages;
    std::queue<std::vector<uint8_t>> messageQueue; // Define the message queue

    CannelloniFrame(const std::vector<uint8_t>& bytes);
    void PrintCANMessages() const;
    void PrintMessageQueue() const;

    // Getter for messageQueue
    const std::queue<std::vector<uint8_t>>& GetMessageQueue() const {
        return messageQueue;
    }

protected:
    void ParseCANMessages(const std::vector<uint8_t>& bytes);
};

