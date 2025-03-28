#include "canmessagegeneric.h"
#include "lpsparameters.h"

#include <iostream>
#include <cstring>


CanMessageGeneric::MESSAGE_t::MESSAGE_t(const std::vector<uint8_t>& message) {
    PART_NUM = (message[5] & 0xF0) >> 4;
    PART_CNT = message[5] & 0x0F;
    ID = message[6];
    TYPE = static_cast<ParamType>(message[7]);
    ACTION = message[8];
    std::memcpy(PL, &message[9], 4);
}

CanMessageGeneric::CanMessageGeneric(const std::vector<uint8_t>& bytes)
    : BaseCanMessage(bytes), Message(bytes)  {
}



float CanMessageGeneric::GetFloatFromPayload() {
    float floatValue;
    std::memcpy(&floatValue, Message.PL, sizeof(float));
    return floatValue;
}

uint32_t CanMessageGeneric::GetULongFromPayload() {
    uint32_t ulongValue;
    std::memcpy(&ulongValue, Message.PL, sizeof(uint32_t));
    return ulongValue;
}

int32_t CanMessageGeneric::GetLongFromPayload() {
    int32_t longValue;
    std::memcpy(&longValue, Message.PL, sizeof(int32_t));
    return longValue;
}

uint16_t CanMessageGeneric::GetUShortFromPayload() {
    uint16_t ushortValue;
    std::memcpy(&ushortValue, Message.PL, sizeof(uint16_t));
    return ushortValue;
}

int16_t CanMessageGeneric::GetShortFromPayload() {
    int16_t shortValue;
    std::memcpy(&shortValue, Message.PL, sizeof(int16_t));
    return shortValue;
}

float CanMessageGeneric::ParseFloat() {
    float floatValue = GetFloatFromPayload();
    LpsParameters& manager = LpsParameters::GetInstance();

    // Process the float based on Node and Priority
    if (Node == static_cast<uint8_t>(NodeId::PLATFORM) && Priority == 2) {
        switch (Message.ID) {
        case static_cast<uint8_t>(IdNode1::ANGLE_HORIZONTAL_CHANNEL):
            manager.SetAngleX(floatValue);
            break;
        case static_cast<uint8_t>(IdNode1::ANGLE_VERTICAL_CHANNEL):
            manager.SetAngleY(floatValue);
            break;
        case static_cast<uint8_t>(IdNode1::SET_HORIZONTAL_CHANNEL):
            manager.SetSpeedX(floatValue);
            break;
        case static_cast<uint8_t>(IdNode1::SET_VERTICAL_CHANNEL):
            manager.SetSpeedY(floatValue);
            break;
        }
    }

    if (Node == static_cast<uint8_t>(NodeId::RANGE_FINDER)) {
        if (Message.ID == static_cast<uint8_t>(IdNode3::MEASURED_RANGES_1)) {
            manager.SetRange(floatValue);
        }
    }

    return floatValue;
}

void CanMessageGeneric::PrintParsedValue() {
    std::cout << "Extracted Value: ";
    switch (Message.TYPE) {
    case ParamType::Float:
        std::cout << GetFloatFromPayload() << " (Float)";
        break;
    case ParamType::ULong:
        std::cout << GetULongFromPayload() << " (Unsigned Long)";
        break;
    case ParamType::Long:
        std::cout << GetLongFromPayload() << " (Long)";
        break;
    case ParamType::UShort:
        std::cout << GetUShortFromPayload() << " (Unsigned Short)";
        break;
    case ParamType::Short:
        std::cout << GetShortFromPayload() << " (Short)";
        break;
    default:
        std::cout << "Unknown Type";
    }
    std::cout << std::endl;
}
