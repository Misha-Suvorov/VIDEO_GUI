#ifndef SCRIPTCOMMANDS_H
#define SCRIPTCOMMANDS_H
#include "structs.h"
#include <cstdint>

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

    void SetProgrammZero();
    void ZeroSet(uint8_t canal, uint8_t command);

    void AskValueDACHoriz();
    void AskValueDACVert();
    void SetTrackingDot(uint16_t x, uint16_t y);
    void SetTrackingDotNormalized(float nx, float ny);
    void ResetTracking();
    void SetTrackingFOV_H(float value);
    void SetTrackingFOV_V(float value);
    void SetTrackingFOV(float FOV_H, float FOV_V);
    void SetTrackingRoiSize(uint16_t value);

    void SetPlatformZero();
};

#endif // SCRIPTCOMMANDS_H
