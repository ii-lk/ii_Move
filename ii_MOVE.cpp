#include <ii_MOVE.h>

ii_MOVE::ii_MOVE()
{
}
// Implement the addMotor function
int ii_MOVE::addMotor(MOTOR m)
{
    if (motorCount < MAX_MOTORS)
    {
        motors[motorCount] = m; // Add the motor to the array
        motorCount++;           // Increment the count
    }
    return motorCount; // Return the new count
}

void ii_MOVE::move(float m0_, float m1_)
{
    if (motorCount > 1 && (motors[0].value != m0_ || motors[1].value != m1_))
    {
        Serial.println("M1: " + String(m0_) + "\tM2: " + String(m1_));
        motors[0].move(m0_);
        motors[1].move(m1_);
        m0 = m0_;
        m1 = m1_;
    }
}

void ii_MOVE::setRotationalFactor(float f)
{
    this->rotational_factor = f;
}

void ii_MOVE::rotate(int angle_)
{
    starttime = 0;
    angle = angle_;
    duration = abs(angle) * rotational_factor;
}

bool ii_MOVE::start()
{
    if (starttime == 0)
    {
        starttime = millis();
    }

    if (millis() - starttime < duration)
    {
        if (angle > 0)
        {
            move(-1, 1);
        }
        else
        {
            move(1, -1);
        }
        return true;
    }
    else
    {
        move(0, 0);
        return false;
    }
}

void ii_MOVE::stop()
{
    move(0, 0);
}
