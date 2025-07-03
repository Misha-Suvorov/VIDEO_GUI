#include "laserparameters.h"

LaserParameters::LaserParameters() {}

LaserParameters &LaserParameters::GetInstance()
{
    static LaserParameters instance;
    return instance;
}

void LaserParameters::SetLaserStanag(uint32_t value)
{
    stanag_code = value;
}
void LaserParameters::SetLaserCountWorkPulses(uint32_t value)
{
    work_pulses = value;
}
void LaserParameters::SetTimeRemaining(uint32_t value)
{
    time_remaining = value;
}
void LaserParameters::SetLaserError(uint8_t value)
{
    error = value;
}
void LaserParameters::SetDelayRemaining(uint32_t value)
{
    delay_remaining = value;
}
void LaserParameters::SetCountCycles(uint32_t value)
{
    count_cycles = value;
}
void LaserParameters::SetLaserActive(bool value)
{
    is_laser_activ = value;
}
void LaserParameters::SetPulseOn(bool value)
{
    is_pulse_on = value;
}
void LaserParameters::SetThermocontrolOn(bool value)
{
    is_thermocontrol_on = value;
}
void LaserParameters::SetBlindOn(bool value)
{
    is_blind_on = value;
}

uint32_t LaserParameters::GetLaserFrequency() const
{
    return pulse_repetition_frequency;
}
uint32_t LaserParameters::GetLaserStanag() const
{
    return stanag_code;
}
uint32_t LaserParameters::GetLaserCountWorkPulses() const
{
    return work_pulses;
}
uint32_t LaserParameters::GetTimeRemaining() const
{
    return time_remaining;
}
uint8_t LaserParameters::GetLaserError() const
{
    return error;
}
uint32_t LaserParameters::GetDelayRemaining() const
{
    return delay_remaining;
}
uint32_t LaserParameters::GetCountCycles() const
{
    return count_cycles;
}
bool LaserParameters::GetLaserActive() const
{
    return is_laser_activ;
}
bool LaserParameters::GetPulseOn() const
{
    return is_pulse_on;
}
bool LaserParameters::GetThermocontrolOn() const
{
    return is_thermocontrol_on;
}
bool LaserParameters::GetBlindOn() const
{
    return is_blind_on;
}
