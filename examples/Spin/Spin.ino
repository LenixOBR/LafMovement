#include <lafvin.h>

LafvinRobot robot(1, 2, 200, 200);

void setup() {
  robot.spinLeftFor(1000);
  robot.spinRightFor(1000);
  robot.stop();
}

void loop() {}
