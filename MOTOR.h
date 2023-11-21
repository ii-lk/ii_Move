
#ifndef MOTOR_h
#define MOTOR_h

#include <Arduino.h>

class MOTOR
{
public:
    MOTOR();
    MOTOR(String name_);
    MOTOR(String name_, int pinDIR_, int pinPWM_);

    void setRange(int min_, int max_);
    void setPropotion(float propotion_);
    void setInverse(bool inverse_);

    // void stop();
    // void start(bool dir_);

    void forceStop();
    void forceStart(float speed_);

    void move(float speed_);
    // void move(float speed_,float dir_safe_);
    // void moveSmooth(bool dir_,int speed_);

    float value;

private:
    String name;

    int pinDIR;
    int pinPWM;

    bool inverse;

    bool dir;
    float pwmvalue;

    int min = 0; // recomand 130
    int max = 255;

    float propotion = 1;
};

#endif
