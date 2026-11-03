# Week 02 - HC-SR04 Sensor Experiment

**Status:** Sensor measurements completed; motor experiment still pending.
**Hardware:** Arduino Uno R3-style, HC-SR04, breadboard, jumper wires, USB cable.
**Firmware:** [ultrasonic_basic.ino](../firmware/arduino-uno/ultrasonic_basic/ultrasonic_basic.ino)

## Purpose

Measure distances using ultrasonic echo timing and investigate sensor accuracy, repeatability, blocking timeouts, and implications for obstacle avoidance.

## Wiring

| HC-SR04 | Arduino Uno |
| --- | --- |
| VCC | 5V |
| TRIG | D9 |
| ECHO | D10 |
| GND | GND |

The HC-SR04 Echo pin commonly produces 5V logic. This setup uses the 5V Arduino Uno, **not** a direct ESP32 Echo connection. Confirm connections with USB disconnected before rewiring.

## Firmware and method

- Arduino IDE Serial Monitor: **9600 baud**.
- Output a LOW pre-pulse (2 microseconds), then a **10-microsecond HIGH** on TRIG.
- Measure ECHO HIGH duration with `pulseIn(ECHO_PIN, HIGH, 30000UL)`, which limits blocking to an approximately 30 ms timeout.
- Treat duration 0 as **no complete echo pulse**, not zero distance.
- Calculate approximate distance at 20 C: `distanceCm = duration * 0.0343 / 2.0`, dividing by two for outbound and returning sound.
- Print results, with `delay(200)` between measurement cycles.

A flat target was placed at ruler-referenced distances of approximately 10, 20, and 30 cm from the front of the ultrasonic transducers. The sensor and target were held stationary for the controlled series; alignment and reference measurement are potential error sources. No calibration offset or software filtering was applied.

## Controlled measurements (cm)

### 10 cm reference (21 readings)

```text
10.38, 10.36, 10.26, 10.26, 10.26, 10.26, 10.36,
10.38, 10.27, 10.26, 10.26, 10.36, 10.38, 10.27,
10.27, 10.26, 10.36, 10.41, 10.26, 10.27, 10.27
```

### 20 cm reference (15 readings)

```text
20.17, 19.74, 19.74, 20.17, 20.15, 20.17, 19.74,
20.05, 20.17, 19.74, 20.15, 20.15, 20.17, 19.74, 20.17
```

### 30 cm reference (24 readings)

```text
29.82, 29.41, 29.41, 29.82, 29.82, 29.38, 29.36, 29.82,
29.46, 29.46, 29.91, 29.46, 29.36, 29.36, 29.77, 29.36,
29.36, 29.82, 30.24, 29.81, 29.82, 29.91, 29.91, 30.34
```

## Summary statistics

All distances and deviations are centimeters. Sample standard deviation uses denominator **n - 1**. Signed bias is **mean minus nominal reference**, and absolute percentage error is `abs(bias) / reference * 100`.

| Nominal reference | N | Mean | Signed bias | Absolute percent error | Sample std. dev. | Min | Max | Range |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 10 | 21 | 10.306 | +0.306 | 3.06% | 0.056 | 10.26 | 10.41 | 0.15 |
| 20 | 15 | 20.015 | +0.015 | 0.073% | 0.203 | 19.74 | 20.17 | 0.43 |
| 30 | 24 | 29.675 | -0.325 | 1.08% | 0.291 | 29.36 | 30.34 | 0.98 |

The first informal ~10 cm run had 12 readings with noticeably greater spread (9.09–10.43 cm). It was not a controlled reference measurement and should not be used for calibration.

## Observations and interpretation

1. **Repeatability changed with distance in this setup.** Sample standard deviation rose from ~0.056 cm (10 cm) to ~0.203 cm (20 cm) to ~0.291 cm (30 cm). Three reference positions are not sufficient to establish that variability always rises with range.
2. **Bias was not constant.** At 10 cm the mean was high by ~0.306 cm, whereas at 30 cm it was low by ~0.325 cm. Subtracting a fixed 10 cm offset from all distances would worsen some readings. No calibration correction has been adopted.
3. **Repeated value clusters** occurred near 19.74/20.15–20.17 cm and 29.36–29.46/29.82–29.91 cm. Echo reflections, internal echo-detection thresholds, and timing behavior are possible explanations, but the cause was not isolated.
4. **Reference distance uncertainty matters.** Without more precise alignment and measuring tools, these errors describe differences from manually placed reference positions rather than verified absolute sensor accuracy.
5. **Blocking behavior matters.** The echo timeout prevents the program waiting indefinitely. The 200 ms loop delay and any filtering also introduce latency relevant to a moving robot.

## Robotics lessons

- A more repeatable sensor is not necessarily unbiased: precision and accuracy differ.
- Averaging can reduce random noise for a stationary target, but a trailing average can lag behind changing distance while a rover approaches a wall.
- Requiring three successive readings below 20 cm can reduce false stops but delays braking and cannot guarantee a stop before the 20 cm mark.
- A conservative obstacle controller can stop on a credible near-obstacle reading and require a larger clearance plus repeated valid readings before resuming (hysteresis). Actual stopping distance also depends on control and mechanical braking delays.

## Next steps

- Sensor experiment completed and documented.
- Review this document and confirm the firmware compiles from the repository.
- Continue **Week 2 motor control** only after verifying the 28BYJ-48 supply, ULN2003 power pins, and safe connections.
- Do **not** mark the full Week 2 milestone complete until motor direction/speed and comparison of requested vs. observed behavior are demonstrated.
