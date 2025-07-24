#include <lafvin.h>

LafvinRobot robot(1, 2, 0, 0); // Start with 0 speed

void setup() {
  robot.preciseMove(100, 200);           // Left slower than right
  delay(1000);
  robot.preciseMoveFor(200, 100, 500);   // Then right slower
  robot.stop();
}

void loop() {}
