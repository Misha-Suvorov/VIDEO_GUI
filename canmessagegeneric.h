#ifndef CANMESSAGEGENERIC_H
#define CANMESSAGEGENERIC_H
#include "BaseCanMessage.h"
#include <vector>
//#include "AngleManager.h"
//#include "SpeedManager.h"
//#include "RangeManager.h"
enum class ParamType {
    NoneType,
    ErrorType,
    Float,
    Long,
    ULong,
    BLong,
    Short,
    UShort,
    BShort,
    Char,
    UChar,
    BChar,
    Short2,
    UShort2,
    BShort2,
    Char4,
    UChar4,
    BChar4,
    Char2,
    UChar2,
    BChar2,
    MEMID,
    CHIKSUM,
    AChar,
    AChar2,
    AChar4,
    Char3,
    UChar3,
    BChar3,
    AChar3,
    DoubleH,
    DoubleL,
};

enum class NodeId {
    PLATFORM = 1,
    GYROVERTICAL,
    RANGE_FINDER,
    LASER_POINTER,
    THERMAL_CAMERA = 8
};

enum class IdNode1 {
    SET_HORIZONTAL_CHANNEL = 0x10,
    ANGLE_HORIZONTAL_CHANNEL = 0x11,
    ZERO_SET_HORIZONTAL_ENCODER = 0x12,
    ZERO_RESET_HORIZONTAL_ENCODER = 0x13,
    ENABLE_HORIZONTAL_ENCODER = 0x14,
    SET_PROGRAM_ZERO_HORIZONTAL_ENCODER = 0x15,


    SET_VERTICAL_CHANNEL = 0x20,
    ANGLE_VERTICAL_CHANNEL = 0x21,
    ZERO_SET_VERTICAL_ENCODER = 0x22,
    ZERO_RESET_VERTICAL_ENCODER = 0x23,
    ENABLE_VERTICAL_ENCODER = 0x24,
    SET_PROGRAM_ZERO_VERTICAL_ENCODER = 0x25
};

enum class IdNode3 {
    MEASURED_RANGES_1 = 0x01
};



class CanMessageGeneric : public BaseCanMessage {
public:
    struct MESSAGE_t {
        uint8_t PART_NUM;
        uint8_t PART_CNT;
        uint8_t ID;
        ParamType TYPE;
        uint8_t ACTION;
        uint8_t PL[4];

        MESSAGE_t(const std::vector<uint8_t>& message);
    };

    MESSAGE_t Message;

    CanMessageGeneric(const std::vector<uint8_t>& bytes);

    float ParseFloat();

    void PrintParsedValue();
    float GetFloatFromPayload();
    uint32_t GetULongFromPayload();
    int32_t GetLongFromPayload();
    uint16_t GetUShortFromPayload();
    int16_t GetShortFromPayload();
};


#endif // CANMESSAGEGENERIC_H
