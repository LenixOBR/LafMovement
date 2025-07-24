#include <lafvin.h>

LafvinRobot robot(1, 2, 150, 150);

void setup() {
  robot.moveLeftFor(1000);
  robot.moveRightFor(1000);
  robot.stop();
}

void loop() {
}
