#ifndef LPSPARAMETERS_H
#define LPSPARAMETERS_H
#include <cstdint>


class LpsParameters
{
public:
    static LpsParameters& GetInstance();

    void SetAngleX(float value);
    void SetAngleY(float value);
    void SetSpeedX(float value);
    void SetSpeedY(float value);
    void SetRange(float value);
    void SetTemperature(float value);
    void SetLaserFrequency(uint32_t value);
    void SetLaserStanag(uint32_t value);
    void SetLaserCountPulses(uint32_t value);


    float GetAngleX() const;
    float GetAngleY() const;
    float GetSpeedX() const;
    float GetSpeedY() const;
    float GetRange() const;
    float GetTemperature() const;


    uint32_t GetLaserFrequency() const;
    uint32_t GetLaserStanag() const;
    uint32_t GetLaserCountPulses() const;



private:
    LpsParameters() = default;
    float angleX = 0.0f;
    float angleY = 0.0f;
    float speedX = 0.0f;
    float speedY = 0.0f;
    float range = 0.0f;
    float temperature = 0.0f;
    uint32_t laser_frequency = 0;
    uint32_t laser_stanag = 0;
    uint32_t laser_pulses = 0;
};
#endif // LPSPARAMETERS_H
