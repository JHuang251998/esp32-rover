# Hardware Inventory

Updated: Week 1 (October 2026)

This list records the hardware available for the `esp32-rover` learning project. **Verified** means identified or used during an experiment; **kit-listed** means listed on the LAFVIN box but not individually tested; **tentative** means the model still needs confirmation. Quantities for the Arduino kit are approximate unless specified.

## Development boards and tools

| Component | Details | Status |
| --- | --- | --- |
| Arduino Uno | Uno R3-style board, onboard LED on D13 (`LED_BUILTIN`); USB uploads tested | Verified |
| ESP32 development board | LAFVIN 30-pin ESP32 DevKit V1-style; detected as **ESP32-D0WD-V3**; CP2102 USB-to-serial; Micro-USB; `ESP32 Dev Module` in Arduino IDE | Verified |
| Small Arduino-compatible board | Pro Micro-style board seen in Arduino kit; exact board and logic voltage not confirmed | Tentative |
| Bambu Lab A1 | 3D printer for future rover chassis | Available; not used in Week 1 |
| Breadboards | Mini and larger breadboards in Arduino kit; 830-point breadboard listed in ESP32 kit | Seen / kit-listed |
| Jumper wires | Mixed Arduino-kit wires; ESP32 kit lists 10 F-M, 10 F-F, 10 M-M | Seen / kit-listed |
| USB cables | USB connection to Uno; ESP32 kit includes Micro-USB data cable | Verified / kit-listed |

## Arduino kit (visually identified)

| Component | Approximate quantity | Notes |
| --- | --- | --- |
| Uno prototyping shield | 1 | Used for prototyping; not tested |
| HC-SR04 ultrasonic range module | 1 | Potential future obstacle-sensing experiment |
| DHT11 temperature/humidity module | 1 | Not tested |
| Microphone/sound sensor module | 1 | Exact model unconfirmed |
| Single-channel relay module | 1 | **Not** a speed/direction motor driver |
| Micro servo (SG90-style) | 1 | Exact model unconfirmed |
| 28BYJ-48 stepper motor | 1 | Driver board not yet confirmed |
| 16x2 LCD | 1 | Exact interface to confirm |
| 8x8 LED matrix and seven-segment displays | Assorted | Drivers/interfaces not confirmed |
| 4x4 membrane keypad, IR remote | 1 each | Not tested |
| RFID module and tag/fob | Set | Reader model unconfirmed |
| LEDs, resistors, buttons, capacitors, miscellaneous sensors | Assorted | Exact counts/models unconfirmed |

## LAFVIN ESP32 Basic Starter Kit (as printed on kit label)

| Component | Kit-listed quantity |
| --- | ---: |
| ESP32 development board | 1 |
| 0.96-inch OLED | 1 |
| 830-point breadboard | 1 |
| Obstacle avoidance module | 1 |
| Photosensitive resistor module | 1 |
| DHT11 temperature/humidity module | 1 |
| HC-SR501 PIR motion sensor | 1 |
| 5V dual-channel relay module | 1 |
| 10k-ohm potentiometer | 1 |
| Pushbuttons | 6 |
| Passive buzzer / active buzzer | 1 each |
| RGB LEDs | 2 |
| Red/yellow/green LEDs | 5 per kit label (distribution unconfirmed) |
| 220-ohm / 1k-ohm / 10k-ohm resistors | 30 total per kit label |
| Micro-USB cable | 1 |
| F-M / F-F / M-M jumper wires | 10 each |

## Verified Week 1 connections

- **Arduino Uno:** onboard LED (`LED_BUILTIN`, D13); pushbutton between D2 and GND using `INPUT_PULLUP`.
- **ESP32:** external LED connected GPIO18 -> 220-ohm resistor -> LED anode; LED cathode -> GND. Pushbutton between GPIO23 and GND using `INPUT_PULLUP`.
- **Power:** each board powered from the computer via USB for these experiments; no separate motor/battery supply was used.
- **Software:** Arduino IDE 2.x on Apple Silicon macOS; Uno board selected for Uno sketches; `ESP32 Dev Module` selected for ESP32 sketches.
- **ESP32 uploading:** 921600 baud caused a serial-communication upload failure; **115200 baud** uploaded successfully. This is the *upload speed*, distinct from `Serial.begin(...)`.

## Hardware still to verify before rover construction

- Pair of geared DC drive motors, wheels, and caster.
- Suitable dual-channel motor driver (correct voltage, logic level, and current rating).
- Wheel encoders, if available, and motor driver for the stepper, if applicable.
- Battery pack and safe power distribution for motors + controller.
- Model numbers and voltage ratings of any remaining unidentified boards/modules.

**Electrical safety:** ESP32 GPIO is 3.3V logic; do not feed 5V directly into ESP32 GPIO. Use an LED current-limiting resistor. Never drive a motor directly from microcontroller GPIO. Disconnect USB before changing breadboard wiring.
