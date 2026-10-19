# Week 1 Wiring and Test Notes

All circuits below were tested using USB-powered development boards and the sketches under `firmware/`. Wiring descriptions specify electrical connections, **not** exact breadboard hole numbers. Disconnect USB before adding or moving wires.

## 1. Arduino Uno: onboard LED Blink

- **Sketches:** `firmware/arduino-uno/blink/blink.ino` and `firmware/arduino-uno/blink_without_delay/blink_without_delay.ino`
- **Wiring:** none; Uno's onboard `LED_BUILTIN` is digital pin D13 on the R3-style board.
- **Behavior tested:** five full blinks per second with 100 ms ON and 100 ms OFF; both `delay()` and `millis()` versions.

## 2. Arduino Uno: pushbutton input

- **Sketches:** `firmware/arduino-uno/button_serial/button_serial.ino` and `firmware/arduino-uno/button_led/button_led.ino`

| From | To |
| --- | --- |
| Uno D2 | One electrical contact of momentary pushbutton |
| Uno GND | Opposite electrical contact of pushbutton |
| Uno D13 / `LED_BUILTIN` | Onboard LED; no external wire |

```text
Uno D2 ---- [normally open button] ---- Uno GND
             (closed when pressed)
```

- `pinMode(2, INPUT_PULLUP)` makes the released input `HIGH` and pressed input `LOW`.
- Uno Serial Monitor: **9600 baud** for `button_serial.ino`.
- **Behavior tested:** Serial Monitor prints PRESSED/RELEASED on state changes; onboard LED turns ON when pressed and OFF when released.
- **Note:** mechanical switch bounce may produce duplicate transition messages. No debounce filter is implemented.

## 3. ESP32: external LED Blink

- **Sketch:** `firmware/esp32/blink/blink.ino`

| From | To |
| --- | --- |
| ESP32 GPIO18 (marked D18 on this board) | One end of 220-ohm resistor |
| Other end of resistor | LED anode (+), typically longer leg |
| LED cathode (-), typically shorter leg / flat side | ESP32 GND |

```text
ESP32 GPIO18 ---- [220 ohm] ---- LED anode (+)
                                   LED cathode (-) ---- ESP32 GND
```

- Resistor and LED must be **in series**, not side by side across the same two nodes.
- **Behavior tested:** 500 ms ON + 500 ms OFF = one blink per second.
- GPIO HIGH is approximately **3.3V**, not 5V.

## 4. ESP32: pushbutton + LED

- **Sketches:** `firmware/esp32/button_led/button_led.ino` and `firmware/esp32/nonblocking_button_led/nonblocking_button_led.ino`
- Keep the ESP32 LED wiring from section 3, and add:

| From | To |
| --- | --- |
| ESP32 GPIO23 (marked D23 on this board) | One electrical contact of momentary pushbutton |
| ESP32 GND | Opposite electrical contact of pushbutton |

```text
ESP32 GPIO18 ---- [220 ohm] ---- LED (+) -> LED (-) ---- GND
ESP32 GPIO23 ---- [normally open button] -------------- GND
```

- Configure GPIO23 as `INPUT_PULLUP`: released = `HIGH`; pressed = `LOW`.
- ESP32 Serial Monitor: **115200 baud** for the button logging sketch.
- **Behavior tested:** button-controlled LED ON/OFF; final nonblocking controller blinks at 2 Hz (250 ms ON, 250 ms OFF) when released, holds LED ON when pressed, and restarts blinking after release.
- **Timing:** final sketch uses `millis()` without `delay()`.

## 5. Troubleshooting and electrical safety

- **ESP32 upload issue:** upload at 921600 failed with `No more data to read from the serial port`; changing **Tools > Upload Speed** to **115200** resolved it. This setting is separate from serial-monitor baud rate.
- **C++ logic issue:** `ledState != ledState;` is a comparison and does not modify the variable. Use `ledState = !ledState;` to toggle the LED.
- A four-legged tactile switch typically has two pins connected on each side; use contacts that connect **only when pressed**. Verify the layout if uncertain.
- **No direct 5V inputs to ESP32 GPIO.** No motors should be connected directly to GPIO. Use a suitable motor driver in Week 2.

## 6. Documentation improvements for later

- Add close-up photos of the two breadboard setups and link them here.
- Add a schematic or breadboard diagram once the layouts are finalized.
- Record exact module model/ratings before any motor or battery experiment.
