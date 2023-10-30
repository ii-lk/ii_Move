
#include <CODBOTS_MOVE.h>

 CODBOTS_MOVE::CODBOTS_MOVE(){

 }
// Implement the addMotor function
int CODBOTS_MOVE::addMotor(MOTOR m) {
    if (motorCount < MAX_MOTORS) {
        motors[motorCount] = m; // Add the motor to the array
        motorCount++; // Increment the count
    }
    return motorCount; // Return the new count
}

void CODBOTS_MOVE::move(float m0, float m1) {
    if (motorCount > 1) {
        motors[0].move(m0);
        motors[1].move(m1);
    }
}