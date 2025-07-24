#include <lafvin.h>

LafvinRobot robot(1, 2, 150, 150);

void setup() {
  robot.forwardFor(1000);
  robot.backwardFor(1000);
  robot.stop();
}

void loop() {
}
