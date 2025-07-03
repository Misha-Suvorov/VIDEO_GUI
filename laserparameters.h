#ifndef LASERPARAMETERS_H
#define LASERPARAMETERS_H
#include "structs.h"
#include <cstdint>

class LaserParameters
{
public:
    static LaserParameters &GetInstance();

    LaserParameters();
    void SetTemperature(float value);
    void SetLaserFrequency(uint32_t value);
    void SetLaserStanag(uint32_t value);
    void SetLaserCountWorkPulses(uint32_t value);
    void SetTimeRemaining(uint32_t value);
    void SetLaserError(uint8_t value);
    void SetDelayRemaining(uint32_t value);
    void SetCountCycles(uint32_t value);
    void SetLaserActive(bool);
    void SetPulseOn(bool);
    void SetThermocontrolOn(bool);
    void SetBlindOn(bool);

    uint32_t GetLaserFrequency() const;
    uint32_t GetLaserStanag() const;
    uint32_t GetLaserCountWorkPulses() const;
    uint32_t GetTimeRemaining() const;
    uint8_t GetLaserError() const;
    uint32_t GetDelayRemaining() const;
    uint32_t GetCountCycles() const;
    bool GetLaserActive() const;
    bool GetPulseOn() const;
    bool GetThermocontrolOn() const;
    bool GetBlindOn() const;

private:
    uint32_t pulse_repetition_frequency = 0;
    uint32_t stanag_code = 0;
    uint32_t work_pulses = 0;
    uint32_t time_remaining = 0;
    uint8_t error = 0;
    float temperature = 0.0;
    uint32_t delay_remaining = 0;
    uint32_t count_cycles = 0;

    bool is_laser_activ = false;
    bool is_pulse_on = false;
    bool is_thermocontrol_on = false;
    bool is_blind_on = false;
};

#endif // LASERPARAMETERS_H
