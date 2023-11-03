
#include <CODBOTS_MOVE.h>

// motor pins
#define MOTOR_L2 33 //PWM
#define MOTOR_L1 25
#define MOTOR_R1 26
#define MOTOR_R2 27  //PWM

CODBOTS_MOVE move;
void setup() {
  Serial.begin(115200);

  MOTOR motorA("L", MOTOR_L1, MOTOR_L2);
  MOTOR motorB("R", MOTOR_R1, MOTOR_R2);

  move.addMotor(motorA);
  move.addMotor(motorB);
}

void loop() {
  move.move(1, 1);
  delay(2000);

  move.move(0, 0);
  delay(2000);

  move.move(-1, -1);
  delay(2000);

  move.move(0, 0);
  delay(2000);
}
