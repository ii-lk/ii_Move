
#ifndef ii_MOVE_h
#define ii_MOVE_h

#include <Arduino.h>
#include <MOTOR.h>
#include <tuple>

#define MAX_MOTORS 4 // Define the maximum number of motors

class ii_MOVE
{

public:
    ii_MOVE();
    int addMotor(MOTOR m);
    float m0;
    float m1;
    void move(float m0, float m1);
    // set rotational digree
    void rotate(int angle_);
    // return true while rotating, when end return false
    bool start();
    // stop all movemenets
    void stop();
    // millis per 1dig rotate
    void setRotationalFactor(float f);

private:
    MOTOR motors[MAX_MOTORS]; // Array of MOTOR objects
    int motorCount = 0;       // Keep track of the number of motors added

    int angle;
    long starttime;
    long duration;

    float rotational_factor = 5;
};

#endif
