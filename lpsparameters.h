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

    float GetAngleX() const;
    float GetAngleY() const;
    float GetSpeedX() const;
    float GetSpeedY() const;
    float GetRange() const;


private:
    LpsParameters() = default;
    float angleX = 0.0f;
    float angleY = 0.0f;
    float speedX = 0.0f;
    float speedY = 0.0f;
    float range = 0.0f;
};
#endif // LPSPARAMETERS_H
