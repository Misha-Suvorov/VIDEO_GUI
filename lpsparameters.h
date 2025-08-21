#ifndef LPSPARAMETERS_H
#define LPSPARAMETERS_H
#include "structs.h"
#include <cstdint>

class LpsParameters
{
public:
    static LpsParameters &GetInstance();

    void SetAngleX(float value);
    void SetAngleY(float value);
    void SetSpeedX(float value);
    void SetSpeedY(float value);
    void SetModePlatform(ModePlatform value);

    void SetRange(float value);

    void SetTemperature(float value);
    void SetLaserFrequency(uint32_t value);
    void SetLaserStanag(uint32_t value);
    void SetLaserCountPulses(uint32_t value);
    void SetTimeRemaining(uint32_t value);
    void SetLaserError(uint8_t value);

    float GetAngleX() const;
    float GetAngleY() const;
    float GetSpeedX() const;
    float GetSpeedY() const;
    ModePlatform GetModePlatform() const;

    float GetRange() const;
    float GetTemperature() const;

    uint32_t GetLaserFrequency() const;
    uint32_t GetLaserStanag() const;
    uint32_t GetLaserCountPulses() const;
    uint32_t GetTimeRemaining() const;
    uint8_t GetLaserError() const;

    void SetVoltageX(float value);
    void SetVoltageY(float value);
    float GetVoltageX() const;
    float GetVoltageY() const;
    Voltage GetVoltage() const;

private:
    LpsParameters() = default;
    float angleX = 0.0f;
    float angleY = 0.0f;
    float speedX = 0.0f;
    float speedY = 0.0f;

    ModePlatform mode_platform;

    Voltage voltage;

    float range = 0.0f;
    float temperature = 0.0f;
    uint32_t laser_frequency = 0;
    uint32_t laser_stanag = 0;
    uint32_t laser_pulses = 0;
    uint32_t time_remaining = 0;
    uint8_t laser_error = 0;
};
#endif // LPSPARAMETERS_H
