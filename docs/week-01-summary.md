# Week 01 - Weekly Learning Summary

**Topic:** Arduino and ESP32 Fundamentals
**Period:** October 2026
**Status:** Coding and physical tests complete; GitHub publication pending.

## Completed

- Inventoried the Arduino kit and LAFVIN ESP32 Basic Starter Kit; distinguished identified parts from unverified models and quantities.
- Installed Arduino IDE 2.x on an Apple Silicon Mac and configured **Arduino Uno** and **ESP32 Dev Module** support.
- Uploaded Blink sketches to both boards.
- Used `delay()` and then `millis()` to blink the Uno's onboard LED at five full cycles per second.
- Wired a Uno pushbutton between D2 and GND; read and reported PRESSED/RELEASED in the Serial Monitor; used it to control the onboard LED.
- Wired an ESP32 external LED to GPIO18 through a 220-ohm resistor and a pushbutton from GPIO23 to GND.
- Built a nonblocking ESP32 controller: LED blinks at **2 Hz** when the button is released, stays ON while pressed, and restarts blinking after release.
- Passed all four final ESP32 physical tests: blinking, pressed override, release recovery, and repeated presses.
- Saved and verified compilation of seven independent sketches in `firmware/`.

## Key concepts learned

- GPIO direction (`INPUT`, `OUTPUT`), digital HIGH/LOW, and the difference between **5 V Uno** and **3.3 V ESP32** logic.
- Floating input pins and `INPUT_PULLUP`; an active-low button reads LOW when pressed.
- Basic voltage, resistance, LED current limiting, and why GPIO is not a motor power source.
- `setup()` versus `loop()` and the firmware compile/upload/run cycle.
- Blocking `delay()` versus nonblocking elapsed-time checks with `millis()`.
- Period versus frequency: 100 ms ON + 100 ms OFF = **5 Hz**; 250 ms ON + 250 ms OFF = **2 Hz**.
- Polling, state-change detection, and simple state-based button override logic.
- `unsigned long` for `millis()` and unsigned elapsed-time subtraction; introductory timer rollover awareness.
- Serial Monitor baud rate versus firmware upload speed; basic mechanical switch bounce.

## Hardware/software used

- **Boards:** Arduino Uno R3-style; LAFVIN 30-pin ESP32 DevKit V1-style (ESP32-D0WD-V3 chip, CP2102 USB interface).
- **Components:** external red LED, 220-ohm resistor, pushbutton, breadboard, jumper wires, USB cables.
- **Software:** Arduino IDE 2.x, Espressif ESP32 board package, macOS on Apple Silicon, Git.
- **Pin mapping:** Uno built-in LED D13 and button D2; ESP32 LED GPIO18 and button GPIO23; both buttons connected to GND with `INPUT_PULLUP`.

## Bugs and fixes

1. **LED did not blink:** wrote `ledState != ledState;` (comparison) rather than `ledState = !ledState;` (toggle and assignment). Correcting the expression fixed the behavior.
2. **ESP32 firmware upload failed:** after the board connected, `esptool` reported `No more data to read from the serial port` when uploading at **921600 baud**. Changing **Tools > Upload Speed** to **115200** resolved the failure.
3. **Missing saved sketches:** reconstructed six Week 1 examples into separate `.ino` folders and verified all seven sketches compile from the repository.

## Demo / repository link

- **Local project:** `esp32-rover/`, with code in `firmware/` and hardware/wiring notes in `docs/`.
- **Physical verification:** all four final ESP32 button/LED tests passed.
- **GitHub URL:** _Add after creating the remote repository and pushing the initial commit._
- **Demo video or photos:** _Optional; not recorded in this report._

## Remaining questions

- Are there suitable **paired geared DC motors, wheels, a dual motor driver, and a safe power supply** in either kit? Verify before buying parts.
- What are the exact specifications of the remaining unidentified modules?
- How would switch debouncing affect the button event stream?
- Which sensor should be tested first in Week 2 (for example, HC-SR04 or DHT11)?

## Career interest reflection (1-5 each)

Rate these from 1 (strongly disagree) to 5 (strongly agree) after reflecting on the work:

- **Enjoyed work/debugging:** 5
- **Wanted deeper understanding:** 4
- **Willing to spend extra time:** 5
- **Can imagine as a career:** 5

## Recommended next week

**Week 2 - Motors and Sensors**

- Confirm the motor types, motor-driver availability, voltage/current ratings, and safe power arrangement **before connecting any motor**.
- Learn PWM and H-bridge motor control; drive a motor only through a properly rated driver.
- Read at least one sensor and record repeatable readings.
- Compare commanded behavior with physical observations and document any discrepancies.

**Week 1 completion criterion:** both boards ran uploaded firmware; physical input and output worked; wiring and debugging notes are documented. Finish reviewing documentation and publishing the GitHub repository to close the portfolio workflow.
