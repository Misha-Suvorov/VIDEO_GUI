#include "cannelloniframe.h"

//CannelloniFrame::CannelloniFrame() {}
#include <iostream>
#include <cstring>

CannelloniFrame::CannelloniFrame(const std::vector<uint8_t>& bytes) {
    if (bytes.size() < 5) {
        throw std::invalid_argument("Invalid CannelloniFrame: Too short");
    }

    Version = bytes[0];
    OPCode = bytes[1];
    SeqNo = bytes[2];
    Count = ((bytes[3] << 8) | bytes[4]);

    ParseCANMessages(bytes);
}

void CannelloniFrame::ParseCANMessages(const std::vector<uint8_t>& bytes)
{
    size_t offset = 5; // Start after the Cannelloni frame header

    for (int i = 0; i < Count && offset + 6 <= bytes.size(); i++)
    {
        CANMessage msg;

        // Ensure we have enough bytes for at least the CAN header (5 bytes)
        size_t messageSize = 5; // CAN header (4-byte can_id + 1-byte len)
        if (offset + messageSize > bytes.size()) {
            throw std::runtime_error("Invalid CAN message header");
        }

        msg.can_id = (bytes[offset + 2] << 8) | (bytes[offset + 3] << 8);  //bytes[offset] | (bytes[offset + 1] << 8) | (bytes[offset + 2] << 16) | (bytes[offset + 3] << 24);
        msg.len = bytes[offset + 4];
        messageSize += msg.len; // Total size includes the data payload

        if (offset + messageSize > bytes.size()) {
            throw std::runtime_error("Invalid CAN message length");
        }

        // Store the full CAN message as a raw byte sequence
        msg.raw_data.insert(msg.raw_data.end(), bytes.begin() + offset, bytes.begin() + offset + messageSize);
        offset += messageSize;

        // Enqueue the message
        messageQueue.push(msg.raw_data);

        // Store the message in the list
        messages.push_back(msg);
    }
}

void CannelloniFrame::PrintCANMessages() const {
    std::cout << "Extracted CAN Messages:\n";
    for (const auto& msg : messages) {
        for (size_t i = 0; i < msg.raw_data.size(); ++i) {
            std::cout << std::hex  << static_cast<int>(msg.raw_data[i]) << " ";
        }
        std::cout << std::endl;
    }
}
