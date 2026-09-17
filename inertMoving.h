#ifndef INERTMOVING_H
#define INERTMOVING_H

class InertMoving
{
public:
    InertMoving();
    void sendVoltage();

private:
    void UpdateVoltageBasedOnPosition();
};

#endif // INERTMOVING_H
