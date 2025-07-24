/*
  lafvin.h - Library for moving lafvin robots.
  Created by Lenix Team, March 13, 2025
  Released with an LGPL License.
*/

#ifndef LAFVIN_H
#define LAFVIN_H

#define FORWARD 1
#define BACKWARD 0
#define RELEASE 2

#define A 1
#define B 2

/*
    VS Code is complaining about arduino.h, let's hope it's nothing.
    https://docs.arduino.cc/learn/contributions/arduino-creating-library-guide/ <- guide being used
*/

#include "Arduino.h"

/*L=Left, R=Right*/

class LafvinMotor
{
  public: 
    LafvinMotor(int motorNum);
    void setSpeed(int speed);
    void run(int direction);
  private:
    int _motorDirPin;
    int _motorPWMPin;
};

class LafvinRobot
{
  public:
    LafvinRobot(int motorLeft, int motorRight, int speedL, int speedR);
    void setSpeed(int speedL, int speedR);
    void forward();
    void forwardFor(unsigned long ms);
    void backward();
    void backwardFor(unsigned long ms);
    void spinLeft();
    void spinLeftFor(unsigned long ms);
    void spinRight();
    void spinRightFor(unsigned long ms);
    void moveLeftFor(unsigned long ms);
    void moveLeft();
    void moveRightFor(unsigned long ms);
    void moveRight();
    void stop();
    void preciseMove(int L, int R);
    void preciseMoveFor(int L, int R, unsigned long ms);
  private:
    int _speedL;
    int _speedR;
    LafvinMotor _leftMotor;
    LafvinMotor _rightMotor;
};


#endif

