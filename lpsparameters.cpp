#include "lpsparameters.h"

//LpsParameters::LpsParameters() {}


LpsParameters& LpsParameters::GetInstance() {
    static LpsParameters instance;
    return instance;
}

// Методи встановлення значень
void LpsParameters::SetAngleX(float value) { angleX = value; }
void LpsParameters::SetAngleY(float value) { angleY = value; }
void LpsParameters::SetSpeedX(float value) { speedX = value; }
void LpsParameters::SetSpeedY(float value) { speedY = value; }

void LpsParameters::SetModePlatform(ModePlatform value) {mode_platform = value;}

void LpsParameters::SetRange(float value) { range = value; }
void LpsParameters::SetTemperature(float value) { temperature = value;}
void LpsParameters::SetLaserFrequency(uint32_t value) { laser_frequency = value;}
void LpsParameters::SetLaserStanag(uint32_t value) { laser_stanag = value;}
void LpsParameters::SetLaserCountPulses(uint32_t value) { laser_pulses = value;}
void LpsParameters::SetTimeRemaining(uint32_t value) {time_remaining = value;}
void LpsParameters::SetLaserError(uint8_t value) {laser_error = value;}


// Методи отримання значень
float LpsParameters::GetAngleX() const { return angleX; }
float LpsParameters::GetAngleY() const { return angleY; }
float LpsParameters::GetSpeedX() const { return speedX; }
float LpsParameters::GetSpeedY() const { return speedY; }

ModePlatform LpsParameters::GetModePlatform() const { return mode_platform;}

float LpsParameters::GetRange() const { return range; }
float LpsParameters::GetTemperature() const { return temperature;}

uint32_t LpsParameters::GetLaserFrequency() const { return laser_frequency;}
uint32_t LpsParameters::GetLaserStanag() const { return laser_stanag;}
uint32_t LpsParameters::GetLaserCountPulses() const { return laser_pulses;}
uint32_t LpsParameters::GetTimeRemaining() const { return time_remaining;}
uint8_t LpsParameters::GetLaserError() const {return laser_error;}



