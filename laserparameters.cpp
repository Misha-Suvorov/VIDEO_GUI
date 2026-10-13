#include "laserparameters.h"

LaserParameters::LaserParameters() {}

LaserParameters &LaserParameters::GetInstance()
{
    static LaserParameters instance;
    return instance;
}

// Встановити STANAG код
void LaserParameters::SetLaserStanag(uint32_t value)
{
    stanag_code = value;
}

// Задати лічильник кількості імпульсів напрацювання
void LaserParameters::SetLaserCountWorkPulses(uint32_t value)
{
    work_pulses = value;
}

// Задати залишок часу підсвіту в мс
void LaserParameters::SetTimeRemaining(uint32_t value)
{
    time_remaining = value;
}

// Встановити код помилки
void LaserParameters::SetLaserError(uint8_t value)
{
    error = value;
}

// Встановити залишок часу  затримки підсвіту в мс.
void LaserParameters::SetDelayRemaining(uint32_t value)
{
    delay_remaining = value;
}

// Задати Лічильник кількості імпульсів напрацювання
void LaserParameters::SetCountCycles(uint32_t value)
{
    count_cycles = value;
}

// Встановлення статусу Активація ЛЦВ
void LaserParameters::SetLaserActive(bool value)
{
    is_laser_activ = value;
}

// Встановлення статусу Включення підсвіту
void LaserParameters::SetPulseOn(bool value)
{
    is_pulse_on = value;
}

// Встановлення статусу Термоконтроль включено
void LaserParameters::SetThermocontrolOn(bool value)
{
    is_thermocontrol_on = value;
}

// Встановлення статусу Затвор (якщо увімкнений випромінювання не виходить назовні)
void LaserParameters::SetBlindOn(bool value)
{
    is_blind_on = value;
}

//Серцебиття
void LaserParameters::SetHeartbeat(bool value)
{
    if(value) is_heartbeat = 30;
    else if(is_heartbeat>0) is_heartbeat--;
}

// Задати температуру
void LaserParameters::SetTemperature(float value)
{
    temperature = value;
    SetHeartbeat(1);
}

// Задати частоту
void LaserParameters::SetLaserFrequency(uint32_t value)
{
    pulse_frequency = value;
}

// Задати потужність
void LaserParameters::SetEnergy(uint8_t value)
{
    energy = value;
}


//=== Зчитування параметрів лазера
uint32_t LaserParameters::GetLaserFrequency() const
{
    return pulse_frequency;
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
float LaserParameters::GetTemperature() const
{
     return temperature;
}
uint8_t LaserParameters::GetEnergy() const
{
    return energy;
}
bool LaserParameters::GetHeartbeat() {
    if(is_heartbeat>0) is_heartbeat--;
    return is_heartbeat;
}
