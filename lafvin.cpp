#include "lafvin.h"
#include <stdlib.h> // Necessary for abs() function

Lafvin::Lafvin(int speed) {
    _speed = speed;
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    Serial.begin(9600);
}

void Lafvin::setSpeed(int speed) {
    _speed = speed;
}

void Lafvin::forward() {
    // Move forward: both motors set to forward direction
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    analogWrite(5, _speed);
    analogWrite(6, _speed);
}

void Lafvin::forwardFor(unsigned long ms) {
    forward();
    delay(ms);
    stop();
}

void Lafvin::backward() {
    // Move backward: both motors set to backward direction
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    analogWrite(5, _speed);
    analogWrite(6, _speed);
}

void Lafvin::backwardFor(unsigned long ms) {
    backward();
    delay(ms);
    stop();
}

void Lafvin::spinLeft() {
    // Left motor forward and right motor backward
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    analogWrite(5, _speed);
    analogWrite(6, _speed);
}

void Lafvin::spinLeftFor(unsigned long ms) {
    spinLeft();
    delay(ms);
    stop();
}

void Lafvin::spinRight() {
    // Spin right: left motor backward and right motor forward
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    analogWrite(5, _speed);
    analogWrite(6, _speed);
}

void Lafvin::spinRightFor(unsigned long ms) {
    spinRight();
    delay(ms);
    stop();
}

void Lafvin::moveLeft() {
    // Turn left: reduce speed of the left motor
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    analogWrite(5, 0);  // Left motor with zero speed
    analogWrite(6, _speed);
}

void Lafvin::moveLeftFor(unsigned long ms) {
    moveLeft();
    delay(ms);
    stop();
}

void Lafvin::moveRight() {
    // Turn right: reduce speed of the right motor
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    analogWrite(5, _speed);
    analogWrite(6, 0);  // Right motor with zero speed
}

void Lafvin::moveRightFor(unsigned long ms) {
    moveRight();
    delay(ms);
    stop();
}

void Lafvin::stop() {
    // Stop both motors
    analogWrite(5, 0);
    analogWrite(6, 0);
}

void Lafvin::preciseMove(int L, int R) {
    // Precise control: set direction based on sign and speed based on absolute value
    digitalWrite(2, (L >= 0) ? HIGH : LOW);
    digitalWrite(4, (R >= 0) ? HIGH : LOW);
    analogWrite(5, abs(L));
    analogWrite(6, abs(R));
}

void Lafvin::preciseMoveFor(int L, int R, unsigned long ms) {
    preciseMove(L, R);
    delay(ms);
    stop();
}

