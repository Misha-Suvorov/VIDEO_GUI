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
    void SetEnergy(uint8_t value);
    void SetHeartbeat(bool);

    float GetTemperature() const;
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
    bool GetHeartbeat();
    uint8_t GetEnergy() const;


private:
    uint32_t pulse_frequency = 0; // частота імпульсів (період між імпульсами в мкс)
    uint32_t stanag_code = 0;     // код STANAG 0x0000-0x01FF
    uint32_t work_pulses = 0;     // лічильник кількості імпульсів напрацювання
    uint32_t time_remaining = 0;  // залишок часу підсвіту в мс
    uint8_t error = 0;            // код помилки
    float temperature = 0.0;      // значення температури
    uint32_t delay_remaining = 0; // залишок часу  затримки підсвіту в мс
    uint32_t count_cycles = 0;    // кількість циклів випромінювання (Діапазон значень — 1-100000)
    uint8_t energy = 0;           // потужність вимпромінювання (0-5)

    bool is_laser_activ = false;  // активація
    bool is_pulse_on = false;     // включення підсвіту
    bool is_thermocontrol_on = false; // включення термоконтролю
    bool is_blind_on = false;     // включення затвору
    uint8_t is_heartbeat = 0;
};

#endif // LASERPARAMETERS_H
