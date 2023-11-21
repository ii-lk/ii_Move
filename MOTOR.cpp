
#include <MOTOR.h>

MOTOR::MOTOR()
{
}

MOTOR::MOTOR(String name_)
{
    name = name_;
}
MOTOR::MOTOR(String name_, int pinDIR_, int pinPWM_)
{
    name = name_;
    pinDIR = pinDIR_;
    pinPWM = pinPWM_;
    pinMode(pinDIR, OUTPUT);
    pinMode(pinPWM, OUTPUT);
    inverse = false;
}

void MOTOR::setRange(int min_, int max_)
{
    min = min_;
    max = max_;
}

void MOTOR::setPropotion(float propotion_)
{
    propotion = propotion_;
}

void MOTOR::setInverse(bool inverse_)
{
    inverse = inverse_;
}

void MOTOR::forceStop()
{
    if (dir)
    {
        move(-1);
    }
    else
    {
        move(1);
    }
    delay(50);
    move(0);
}

void MOTOR::forceStart(float speed_)
{
    // move((speed_ > 0) ? 1 : ((speed_ < 0) ? -1 : 0));
    delay(50);
    move(speed_);
}

void MOTOR::move(float speed_)
{

    value = speed_;

    bool dir_ = speed_ > 0; // get direction
                            // Serial.println("dir_:" + String(dir_));
    int pwmvalue_;          // pwm value

    // if(speed_!=0){
    speed_ = abs(speed_);                                      // get abalute button
    speed_ = (speed_ < -1) ? -1 : ((speed_ > 1) ? 1 : speed_); // validate input value -1,1
    pwmvalue_ = min + ((max - min) * speed_ * propotion);
    // }
    //  Serial.println("inverse:" + String(inverse));

    if (inverse)
    {
        dir_ = !dir_;
    }

    dir = dir_;

    pwmvalue_ = dir_ ? (255 - pwmvalue_) : pwmvalue_;

    pwmvalue = pwmvalue_;

    // Serial.println(String(speed_) + '\t' + String(255 - pwmvalue_) + '\t' + String(pwmvalue));

    analogWrite(pinDIR, dir * 255);
    analogWrite(pinPWM, pwmvalue_);
}