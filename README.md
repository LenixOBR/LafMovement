# LafvinMotorShield

**LafvinMotorShield** is an Arduino library for controlling a differential-drive robot using the Lafvin Motor Shield.

It simplifies movement control by providing high-level functions such as `forward()`, `spinLeft()`, and `preciseMove()`, without the need to manually control PWM and direction pins.

---

## 📦 Installation

1. Download or clone this repository.
2. Copy the `lafvin` folder into your Arduino `libraries/` folder.
3. Restart the Arduino IDE.
4. Go to **File > Examples > Lafvin** to see usage examples.

---

## 🔌 Hardware Requirements

- Arduino-compatible board (Uno, Mega, Nano, etc.)
- Lafvin Motor Shield (or similar motor driver with 2 DC outputs)
- Two DC motors connected to the motor shield

---

## 🧰 Library Overview

### 🚗 LafvinRobot

```cpp
LafvinRobot robot(leftMotor, rightMotor, speedL, speedR);
```

- `leftMotor`, `rightMotor`: integers (1 or 2)
- `speedL`, `speedR`: integers from `0` to `255`

#### 📋 Example

```cpp
#include <lafvin.h>

LafvinRobot robot(1, 2, 150, 150);

void setup() {
  robot.forwardFor(1000);
  robot.spinLeftFor(500);
  robot.backward();
  delay(800);
  robot.stop();
}
```

---

## 🧠 API Reference

### Initialization

```cpp
LafvinRobot robot(1, 2, 150, 150);
```

### Motion Commands

- `forward()`, `forwardFor(ms)`
- `backward()`, `backwardFor(ms)`
- `spinLeft()`, `spinLeftFor(ms)`
- `spinRight()`, `spinRightFor(ms)`
- `moveLeft()`, `moveLeftFor(ms)`
- `moveRight()`, `moveRightFor(ms)`
- `stop()`

### Precise Control

- `preciseMove(leftSpeed, rightSpeed)`
- `preciseMoveFor(leftSpeed, rightSpeed, ms)`
- `setSpeed(newLeftSpeed, newRightSpeed)`

All speeds are `0–255`.

---

## 📂 Examples

You can find ready-to-use sketches in the `examples/` folder:

- `BasicExample` – simple forward/backward movement
- `Curves` – soft turns using one motor
- `Spin` – in-place rotation
- `PreciseMovement` – fine-grained motor control

---

## 🧑‍💻 Maintainer

LenixOBR  
📧 lenix.obr@gmail.com  
🔗 https://github.com/LenixOBR/Lafvin

---

## 📝 License

This library is released under the [LGPL License](https://www.gnu.org/licenses/lgpl-3.0.html).
