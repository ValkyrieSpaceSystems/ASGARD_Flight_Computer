# Asgard Flight Computer

An open-source high power rocketry flight computer designed for long-term affordability through flexibility, modularity, and expandability. Designed to fly with [ODIN flight software](#) and communicate with the [Midgard ground station](#) over the [BIFROST protocol](#).

---

## Sensors

| Component | Part | Interface |
|---|---|---|
| Low-altitude barometer | BMP581 | SPI |
| High-altitude barometer *(optional)* | MS5607 | SPI |
| Low-g IMU | BMI270 | SPI |
| Mid-g IMU | BMI088 | SPI |
| High-g accelerometer | H3LIS331DLTR | SPI |
| Magnetometer | MMC5983MA | SPI |
| GNSS | MAX-M10S | UART |
| Current monitor | INA226 | I2C |

---

## Pyrotechnics

3 independent events, 2 channels each (6 total). High-side arming via external switch keeps all channels unpowered until deliberately armed. Each channel has its own independent low-side MOSFET.

---

## Servo Control

6 outputs — a 4-channel group for fin deflection and a 2-channel group for thrust vector control. Each group is independently configurable via jumper to run from battery or regulated 5V.

---

## Communications

Interface agnostic — any physical transport (XBee, ELRS, RS-485, Bluetooth, CAN, USB, etc.) can carry BIFROST traffic with no firmware changes. A bypass switch port enables autonomous operation if ground station comms are unavailable.

---

## Expansion

2× SPI, 3× UART, 2× I2C, 1× CAN expansion ports, plus 2 GPIO breakout pins. Pyro arm and servo arm signals are also broken out for auxiliary boards.

**Current expansion boards:** RS-485, GPIO breakout

**Planned:** camera module, extra sensors, payload, multi-stage, Bluetooth/WiFi, high-power servos, pyro expansion
