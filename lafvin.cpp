#include "lafvin.h"
#include <stdlib.h> // Necessary for abs() function

LafvinRobot::LafvinRobot(int motorNumLeft, int motorNumRight, int speedL, int speedR)
  : _leftMotor(motorNumLeft), _rightMotor(motorNumRight)
{
  _speedL = speedL;
  _speedR = speedR;
  _leftMotor.setSpeed(_speedL);
  _rightMotor.setSpeed(_speedR);
}

void LafvinRobot::setSpeed(int speed) {
    _speed = speed;
}

void LafvinRobot::forward() {
    // Move forward: both motors set to forward direction
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    analogWrite(5, _speed);
    analogWrite(6, _speed);
}

void LafvinRobot::forwardFor(unsigned long ms) {
    forward();
    delay(ms);
    stop();
}

void LafvinRobot::backward() {
    // Move backward: both motors set to backward direction
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    analogWrite(5, _speed);
    analogWrite(6, _speed);
}

void LafvinRobot::backwardFor(unsigned long ms) {
    backward();
    delay(ms);
    stop();
}

void LafvinRobot::spinLeft() {
    // Left motor forward and right motor backward
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    analogWrite(5, _speed);
    analogWrite(6, _speed);
}

void LafvinRobot::spinLeftFor(unsigned long ms) {
    spinLeft();
    delay(ms);
    stop();
}

void LafvinRobot::spinRight() {
    // Spin right: left motor backward and right motor forward
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    analogWrite(5, _speed);
    analogWrite(6, _speed);
}

void LafvinRobot::spinRightFor(unsigned long ms) {
    spinRight();
    delay(ms);
    stop();
}

void LafvinRobot::moveLeft() {
    // Turn left: reduce speed of the left motor
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    analogWrite(5, 0);  // Left motor with zero speed
    analogWrite(6, _speed);
}

void LafvinRobot::moveLeftFor(unsigned long ms) {
    moveLeft();
    delay(ms);
    stop();
}

void LafvinRobot::moveRight() {
    // Turn right: reduce speed of the right motor
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    analogWrite(5, _speed);
    analogWrite(6, 0);  // Right motor with zero speed
}

void LafvinRobot::moveRightFor(unsigned long ms) {
    moveRight();
    delay(ms);
    stop();
}

void LafvinRobot::stop() {
    // Stop both motors
    analogWrite(5, 0);
    analogWrite(6, 0);
}

void LafvinRobot::preciseMove(int L, int R) {
    // Precise control: set direction based on sign and speed based on absolute value
    digitalWrite(2, (L >= 0) ? HIGH : LOW);
    digitalWrite(4, (R >= 0) ? HIGH : LOW);
    analogWrite(5, abs(L));
    analogWrite(6, abs(R));
}

void LafvinRobot::preciseMoveFor(int L, int R, unsigned long ms) {
    preciseMove(L, R);
    delay(ms);
    stop();
}

LafvinMotor::LafvinMotor(int motorNum) {
    // Initialize motor pins based on motor number
    if (motorNum == 1) {
        _motorDirPin = 2; // Example pin for direction
        _motorPWMPin = 5; // Example pin for PWM
    } else if (motorNum == 2) {
        _motorDirPin = 4; // Example pin for direction
        _motorPWMPin = 6; // Example pin for PWM
    }
    pinMode(_motorDirPin, OUTPUT);
    pinMode(_motorPWMPin, OUTPUT);
}

void LafvinMotor::setSpeed(int speed) {
    // Set the speed of the motor
    analogWrite(_motorPWMPin, speed);
}

void LafvinMotor::run(int direction) {
    // Set the motor direction
    if (direction == FORWARD) {
        digitalWrite(_motorDirPin, HIGH);
    } else if (direction == BACKWARD) {
        digitalWrite(_motorDirPin, LOW);
    } else if (direction == RELEASE) {
        analogWrite(_motorPWMPin, 0); // Stop the motor
    }
}