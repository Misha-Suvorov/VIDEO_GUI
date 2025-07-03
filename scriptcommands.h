#ifndef SCRIPTCOMMANDS_H
#define SCRIPTCOMMANDS_H
#include "structs.h"
#include <vector>

class ScriptCommands
{
public:
    static ScriptCommands &GetInstance();
    void SetAngleEncoder_H(float value);
    void SetAngleEncoder_V(float value);
    void SetAngleEncoder(float angle_encoder_H, float angle_encoder_V);
    void SetVoltageEncoder(float voltage_encoder_H, float voltage_encoder_V);

    void SetMode(ModePlatform mode);
    void GetMode();
    void SetLaserEnergy(uint8_t value);

    //ScriptCommands();
};

#endif // SCRIPTCOMMANDS_H
