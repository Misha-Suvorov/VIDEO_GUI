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
void LpsParameters::SetRange(float value) { range = value; }
void LpsParameters::SetTemperature(float value) { temperature = value;}

// Методи отримання значень
float LpsParameters::GetAngleX() const { return angleX; }
float LpsParameters::GetAngleY() const { return angleY; }
float LpsParameters::GetSpeedX() const { return speedX; }
float LpsParameters::GetSpeedY() const { return speedY; }
float LpsParameters::GetRange() const { return range; }
float LpsParameters::GetTemperature() const { return temperature;}
