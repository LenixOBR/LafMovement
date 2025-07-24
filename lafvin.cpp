#include "lafvin.h"
#include <stdlib.h> // abs()

LafvinRobot::LafvinRobot(int motorNumLeft, int motorNumRight, int speedL, int speedR)
    : _leftMotor(motorNumLeft), _rightMotor(motorNumRight), _speedL(speedL), _speedR(speedR)
{
    // Inicializa motores com velocidades padrão
    _leftMotor.setSpeed(_speedL);
    _rightMotor.setSpeed(_speedR);
}

void LafvinRobot::setSpeed(int speedL, int speedR) {
    _speedL = speedL;
    _speedR = speedR;
}

void LafvinRobot::forward() {
    _leftMotor.run(FORWARD);
    _rightMotor.run(FORWARD);
}

void LafvinRobot::forwardFor(unsigned long ms) {
    forward();
    delay(ms);
    stop();
}

void LafvinRobot::backward() {
    _leftMotor.run(BACKWARD);
    _rightMotor.run(BACKWARD);
}

void LafvinRobot::backwardFor(unsigned long ms) {
    backward();
    delay(ms);
    stop();
}

void LafvinRobot::spinLeft() {
    _leftMotor.run(FORWARD);
    _rightMotor.run(BACKWARD);
}

void LafvinRobot::spinLeftFor(unsigned long ms) {
    spinLeft();
    delay(ms);
    stop();
}

void LafvinRobot::spinRight() {
    _leftMotor.run(BACKWARD);
    _rightMotor.run(FORWARD);
}

void LafvinRobot::spinRightFor(unsigned long ms) {
    spinRight();
    delay(ms);
    stop();
}

void LafvinRobot::moveLeft() {
    // Turn left: left motor parado, right motor em velocidade normal
    _leftMotor.run(RELEASE);
    _rightMotor.run(FORWARD);
}

void LafvinRobot::moveLeftFor(unsigned long ms) {
    moveLeft();
    delay(ms);
    stop();
}

void LafvinRobot::moveRight() {
    // Turn right: right motor parado, left motor em velocidade normal
    _leftMotor.run(FORWARD);
    _rightMotor.run(RELEASE);
}

void LafvinRobot::moveRightFor(unsigned long ms) {
    moveRight();
    delay(ms);
    stop();
}

void LafvinRobot::stop() {
    _leftMotor.run(RELEASE);
    _rightMotor.run(RELEASE);
}

void LafvinRobot::preciseMove(int L, int R) {
    _leftMotor.setSpeed(abs(L));
    _rightMotor.setSpeed(abs(R));
    _leftMotor.run((L >= 0) ? FORWARD : BACKWARD);
    _rightMotor.run((R >= 0) ? FORWARD : BACKWARD);
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