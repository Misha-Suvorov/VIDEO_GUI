#include "canmessagegeneric.h"
#include "laserparameters.h"
#include "lpsparameters.h"

#include <cstring>
#include <iostream>

CanMessageGeneric::MESSAGE_t::MESSAGE_t(const std::vector<uint8_t> &message)
{
    PART_NUM = (message[5] & 0xF0) >> 4;
    PART_CNT = message[5] & 0x0F;
    ID = message[6];
    TYPE = static_cast<ParamType>(message[7]);
    ACTION = message[8];
    std::memcpy(PL, &message[9], 4);
}

CanMessageGeneric::CanMessageGeneric(const std::vector<uint8_t> &bytes)
    : BaseCanMessage(bytes)
    , Message(bytes)
{}

float CanMessageGeneric::GetFloatFromPayload()
{
    float floatValue;
    std::memcpy(&floatValue, Message.PL, sizeof(float));

    return floatValue;
}

// uint32_t CanMessageGeneric::GetULongFromPayload() {
//     uint32_t ulongValue;
//     std::memcpy(&ulongValue, Message.PL, sizeof(uint32_t));
//     return ulongValue;
// }

uint32_t CanMessageGeneric::GetULongFromPayload()
{
    uint32_t ulongValue = 0;
    ulongValue |= static_cast<uint32_t>(Message.PL[3]) << 0;
    ulongValue |= static_cast<uint32_t>(Message.PL[2]) << 8;
    ulongValue |= static_cast<uint32_t>(Message.PL[1]) << 16;
    ulongValue |= static_cast<uint32_t>(Message.PL[0]) << 24;
    return ulongValue;
}

int32_t CanMessageGeneric::GetLongFromPayload()
{
    int32_t longValue;
    std::memcpy(&longValue, Message.PL, sizeof(int32_t));
    return longValue;
}

uint16_t CanMessageGeneric::GetUShortFromPayload()
{
    uint16_t ushortValue;
    std::memcpy(&ushortValue, Message.PL, sizeof(uint16_t));
    return ushortValue;
}

int16_t CanMessageGeneric::GetShortFromPayload()
{
    int16_t shortValue;
    std::memcpy(&shortValue, Message.PL, sizeof(int16_t));
    return shortValue;
}

uint8_t CanMessageGeneric::GetByteFromPayload()
{
    uint8_t byteValue;
    std::memcpy(&byteValue, Message.PL, sizeof(uint8_t));
    return byteValue;
}

uint8_t CanMessageGeneric::ParseByte()
{
    uint8_t byteValue = GetByteFromPayload();
    LaserParameters &manager = LaserParameters::GetInstance();
    if (Node == static_cast<uint8_t>(NodeId::LASER_POINTER) && Message.ACTION == 0) {
        switch (Message.ID) {
        case static_cast<uint8_t>(IdNode4::LASER_ACTIVE):
            manager.SetLaserActive(byteValue);
            break;
        case static_cast<uint8_t>(IdNode4::PULSE_ON):
            manager.SetPulseOn(byteValue);
            break;
        case static_cast<uint8_t>(IdNode4::THERMAL_CONTROLE):
            manager.SetThermocontrolOn(byteValue);
            break;
        case static_cast<uint8_t>(IdNode4::BLIND_ON):
            manager.SetBlindOn(byteValue);
            break;
        default:
            break;
        }
    }
    return byteValue;
}

float CanMessageGeneric::ParseFloat()
{
    float floatValue = GetFloatFromPayload();
    LpsParameters &manager = LpsParameters::GetInstance();

    // Process the float based on Node and Priority
    if (Node == static_cast<uint8_t>(NodeId::PLATFORM) && Priority == 2 && Dir == 0) {
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

    if (Node == static_cast<uint8_t>(NodeId::PLATFORM) && Priority == 5 && Dir == 0) {
        switch (Message.ID) {
        case static_cast<uint8_t>(IdNode1::SET_HORIZONTAL_CHANNEL):
            manager.SetVoltageX(floatValue);
            break;
        case static_cast<uint8_t>(IdNode1::SET_VERTICAL_CHANNEL):
            manager.SetVoltageY(floatValue);
            break;
        }
    }

    if (Node == static_cast<uint8_t>(NodeId::RANGE_FINDER)) {
        if (Message.ID == static_cast<uint8_t>(IdNode3::MEASURED_RANGES_1)) {
            manager.SetRange(floatValue);
        }
    }

    if (Node == static_cast<uint8_t>(NodeId::LASER_POINTER)) {
        if (Message.ID == static_cast<uint8_t>(IdNode4::TEMPERATURE)) {
            manager.SetTemperature(floatValue);
        }
    }

    return floatValue;
}

uint32_t CanMessageGeneric::ParseULong()
{
    uint32_t uLongValue = GetULongFromPayload();
    LpsParameters &manager = LpsParameters::GetInstance();

    if (Node == static_cast<uint8_t>(NodeId::PLATFORM) /* && ParamID==0*/) {
        if(Message.ID == static_cast<uint8_t>(IdNode1::MODE))
            manager.SetModePlatform((ModePlatform) uLongValue);
    }

    if (Node == static_cast<uint8_t>(NodeId::LASER_POINTER)) {
        switch (Message.ID) {
        case static_cast<uint8_t>(IdNode4::FREQUENCY):
            manager.SetLaserFrequency(uLongValue);
            break;
        case static_cast<uint8_t>(IdNode4::STANAG):
            manager.SetLaserStanag(uLongValue);
            break;
        case static_cast<uint8_t>(IdNode4::COUNT_PULSES):
            manager.SetLaserCountPulses(uLongValue);
            break;
        case static_cast<uint8_t>(IdNode4::TIME_RADIATION_REMAINING):
            manager.SetTimeRemaining(uLongValue);
            break;
        }
    }

    return uLongValue;
}

void CanMessageGeneric::PrintParsedValue()
{
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
