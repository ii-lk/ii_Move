
#ifndef CODBOTS_MOVE_h
#define CODBOTS_MOVE_h

#include <Arduino.h>
#include <MOTOR.h>
#include <tuple>

#define MAX_MOTORS 4 // Define the maximum number of motors

class CODBOTS_MOVE
{

public:
    CODBOTS_MOVE();
    int addMotor(MOTOR m);
    float m0;
    float m1;
    void move(float m0, float m1);

private:
    MOTOR motors[MAX_MOTORS]; // Array of MOTOR objects
    int motorCount = 0;       // Keep track of the number of motors added
};

#endif
