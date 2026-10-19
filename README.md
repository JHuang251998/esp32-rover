# ESP32 Rover

An evolving robotics learning project: start with Arduino Uno and ESP32 fundamentals, then build toward a 3D-printed, ESP32-controlled mobile rover. This repository follows a 24-week robotics learning roadmap.

**Current stage:** Week 1 electronics and embedded basics completed on physical boards. **The rover has not been built yet.**

## Week 1 firmware

Each sketch lives in a folder with the same name as its `.ino` file, so Arduino IDE can open it independently.

| Board | Sketch | What it demonstrates |
| --- | --- | --- |
| Uno | [`blink`](firmware/arduino-uno/blink/blink.ino) | Built-in LED; `delay()`; five complete blinks/second |
| Uno | [`blink_without_delay`](firmware/arduino-uno/blink_without_delay/blink_without_delay.ino) | `millis()`-based blinking at five blinks/second |
| Uno | [`button_serial`](firmware/arduino-uno/button_serial/button_serial.ino) | Button transitions via Serial Monitor |
| Uno | [`button_led`](firmware/arduino-uno/button_led/button_led.ino) | Button controls the built-in LED |
| ESP32 | [`blink`](firmware/esp32/blink/blink.ino) | External LED on GPIO18; one blink/second |
| ESP32 | [`button_led`](firmware/esp32/button_led/button_led.ino) | Button on GPIO23 controls GPIO18 LED; serial messages |
| ESP32 | [`nonblocking_button_led`](firmware/esp32/nonblocking_button_led/nonblocking_button_led.ino) | 2 Hz blink when released; held button forces LED ON; no `delay()` |

## Hardware used

- Arduino Uno R3-style board with a built-in LED (`LED_BUILTIN`, D13).
- LAFVIN 30-pin ESP32 DevKit V1-style board, detected as **ESP32-D0WD-V3** with a **CP2102** USB-to-serial interface.
- Breadboard, jumper wires, momentary pushbutton, red LED, and **220-ohm current-limiting resistor**.
- Apple Silicon Mac, USB cables, and Arduino IDE 2.x.

See [hardware inventory](docs/hardware-inventory.md) for additional kit components, confidence levels, and hardware still needed for a rover.

## Setup and reproduce

1. Install [Arduino IDE 2.x](https://www.arduino.cc/en/software/).
2. For **Uno** sketches, select **Arduino Uno** with Arduino AVR Boards support.
3. For **ESP32** sketches, install **esp32 by Espressif Systems** through Boards Manager, using the [official package instructions](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html) if needed. Select **ESP32 Dev Module**.
4. Open a `.ino` file from its containing sketch folder, select the correct board and serial port, then **Verify** and **Upload**.
5. For this ESP32/USB setup, **Tools > Upload Speed > 115200** was reliable; 921600 produced a serial-port read failure. Upload speed is separate from the sketch's `Serial.begin(...)` value.
6. For `button_serial.ino`, set the Uno Serial Monitor to **9600 baud**. For the ESP32 `button_led.ino`, set it to **115200 baud**.

### Week 1 wiring

| Board | Signal | Connection |
| --- | --- | --- |
| Uno | `LED_BUILTIN` / D13 | Onboard LED; no external wiring |
| Uno | D2 | Button to GND, using `INPUT_PULLUP` |
| ESP32 | GPIO18 | 220-ohm resistor -> LED anode (+); LED cathode (-) -> GND |
| ESP32 | GPIO23 | Button to GND, using `INPUT_PULLUP` |

The pushbutton is **active-low**: released = HIGH; pressed = LOW. See [Week 1 circuit notes](docs/wiring/week-01-circuits.md) for more detail and tests. Disconnect USB before changing wiring.

## Verified behavior

- Uno Blink and Blink Without Delay both produced five complete LED blinks/second.
- Uno button transitions appeared in the Serial Monitor; button press illuminated the onboard LED.
- ESP32 external LED blinked once/second; GPIO23 button controlled it.
- Final ESP32 controller passed all four physical tests: automatic 2 Hz blinking, button override ON, restart after release, and repeated presses.
- All seven saved sketches were subsequently verified to compile from the repository.

## Debugging notes

- `ledState != ledState;` **compares** a value to itself; it does not change the variable. The intended toggle is `ledState = !ledState;`.
- An ESP32 upload failed with `No more data to read from the serial port` at 921600 baud; lowering upload speed to 115200 allowed uploading.
- Button contacts can bounce; the Week 1 sketches do **not** implement debouncing.

## Electrical safety

- ESP32 GPIO uses **3.3 V logic**; do not apply 5 V directly to GPIO.
- Keep the LED's current-limiting resistor in series.
- Never drive DC motors directly from microcontroller GPIO. Select a driver matched to the motor's voltage, current, and control logic before future motor experiments.

## Learning notes and next steps

- [Week 1 learning summary](docs/week-01-summary.md)
- **Week 2:** identify available motors and a safe driver, study PWM and motor control, and read at least one sensor.

This repository documents the learning process; it is not yet a production robot or a safety-rated controller.
