
#include <CODBOTS_MOVE.h>

CODBOTS_MOVE::CODBOTS_MOVE()
{
}
// Implement the addMotor function
int CODBOTS_MOVE::addMotor(MOTOR m)
{
    if (motorCount < MAX_MOTORS)
    {
        motors[motorCount] = m; // Add the motor to the array
        motorCount++;           // Increment the count
    }
    return motorCount; // Return the new count
}

void CODBOTS_MOVE::move(float m0_, float m1_)
{
    if (motorCount > 1)
    {
        motors[0].move(m0_);
        motors[1].move(m1_);
        m0 = m0_;
        m1 = m1_;
    }
}