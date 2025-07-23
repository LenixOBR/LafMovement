/*
  lafvin.h - Library for moving lafvin robots.
  Created by Lenix Team, March 13, 2025
  Released into the public domain.
*/

#ifndef lafvin_h
#define lafvin_h

/*
    VS Code is complaining about arduino.h, let's hope it's nothing.
    https://docs.arduino.cc/learn/contributions/arduino-creating-library-guide/ <- guide being used
*/

#include "Arduino.h"
#include "AFMotor.h"

/*L=Left, R=Right*/

class Lafvin
{
  public:
    Lafvin(int speed);
    void setSpeed(int speed);
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
    int _speed;

};

#endif

