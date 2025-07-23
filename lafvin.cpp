#include "lafvin.h"
#include <stdlib.h> // Necessário para a função abs()

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
    // Movimento para frente: ambos os motores com direção forward
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
    // Movimento para trás: ambos os motores com direção backward
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
    // Gira para a esquerda: motor esquerdo forward e direito backward
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
    // Gira para a direita: motor esquerdo backward e direito forward
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
    // Curva para a esquerda: reduz a velocidade do motor esquerdo
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    analogWrite(5, 0);  // Motor esquerdo com metade da velocidade
    analogWrite(6, _speed);
}

void Lafvin::moveLeftFor(unsigned long ms) {
    moveLeft();
    delay(ms);
    stop();
}

void Lafvin::moveRight() {
    // Curva para a direita: reduz a velocidade do motor direito
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    analogWrite(5, _speed);
    analogWrite(6, 0);  // Motor direito com metade da velocidade
}

void Lafvin::moveRightFor(unsigned long ms) {
    moveRight();
    delay(ms);
    stop();
}

void Lafvin::stop() {
    // Para ambos os motores
    analogWrite(5, 0);
    analogWrite(6, 0);
}

void Lafvin::preciseMove(int L, int R) {
    // Controle preciso: define a direção com base no sinal e a velocidade com o valor absoluto
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
