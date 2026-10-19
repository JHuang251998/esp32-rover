# Robotics Learning Roadmap - Master Plan

**Version:** 1.1 (October 2026)  
**Status:** In progress / Week 1 completed, Week 2 next  
**Target:** 24 weeks, approximately 5-8 hours per week  
**Initial additional hardware budget:** $100-$250 (buy only what is needed)  
**Primary objective:** Explore robotics hands-on, build real projects, and evaluate potential robotics engineering career paths.

> This is the master reference file for the Robotics ChatGPT project. Its canonical version lives at [docs/robotics-roadmap.md](https://github.com/JHuang251998/esp32-rover/blob/main/docs/robotics-roadmap.md). Update the progress tracker at the end of each week. Weekly chats should use the latest GitHub version as their source of truth, while adapting pacing to actual progress.

## 1. Starting Point

- **Work:** Backend software engineer at Amazon Leo, Commerce organization; works on accounting and invoicing systems.
- **Programming:** Java, Python, JavaScript/TypeScript.
- **Linux and systems:** Comfortable.
- **Electronics and microcontrollers:** Basic experience.
- **Math:** Studied before, but rusty; refresh as needed rather than taking full courses at the outset.
- **Interests:** Mobile robots, autonomous navigation, robotic arms, embedded systems, fleet/orchestration software.
- **Career intent:** Explore before deciding on a transition.
- **Available hardware:** Bambu Lab A1 3D printer; Arduino Uno; motors; LEDs; capacitors; breadboards; various sensors; RFID; numpads; display/screen; ESP32 basic starter kit.

### Guiding principles

1. Spend more time building and debugging than watching tutorials.
2. Reuse current hardware before purchasing more.
3. Build one evolving rover project plus a separate simulated autonomous robot.
4. Learn targeted math and C/C++ concepts when the project needs them.
5. Use the last four weeks to test a specialization, not to cram every robotics field.
6. Pacing is flexible; 'week' means a learning unit, not an inflexible deadline.

## 2. End-of-Program Outcomes

By the end of the 24-week exploration, aim to:

- Build and safely operate a 3D-printed, ESP32-controlled mobile rover.
- Understand electrical interfaces, sensors, motors, PWM, basic feedback control, and wheel odometry.
- Write Python ROS 2 nodes, use ROS topics/services/actions, launch and debug a robot in simulation.
- Demonstrate autonomous navigation and mapping in a simulated environment with ROS 2/Nav2.
- Complete one capstone project in fleet software, manipulation, or embedded control.
- Publish two to three reproducible GitHub repositories with READMEs, wiring/CAD files, tests, demos, and engineering notes.
- Decide whether robotics is worth pursuing professionally, and if so which branch.

### Main artifacts

1. `esp32-rover` - physical rover, firmware, wiring diagram, CAD models, Python controls.
2. `ros2-autonomous-rover` - ROS 2 packages, Gazebo simulation, navigation demos.
3. `robotics-capstone` - chosen specialization: fleet, arm/manipulation, or embedded control.

## 3. Six Phases at a Glance

| Phase | Weeks | Focus | Primary milestone |
| --- | --- | --- | --- |
| 1 | 1-3 | Electronics and embedded basics | Control motor and read sensor; send commands to ESP32 |
| 2 | 4-7 | Physical mobile rover | 3D-printed, wireless-controlled rover with safety stop |
| 3 | 8-10 | Robotics math and control | Measured-square experiment, odometry and optional PID |
| 4 | 11-15 | ROS 2 and simulation | Python ROS 2 package and simulated robot |
| 5 | 16-20 | Autonomous navigation | Simulated delivery robot with map and waypoints |
| 6 | 21-24 | Capstone and career evaluation | Specialization demo and written career reflection |

## 4. Phase 1 - Electronics and Embedded Basics (Weeks 1-3)

**Goal:** Learn to interact with physical components from software and understand timing, sensor readings, and motor safety.

### Week 1 - Arduino and ESP32 Fundamentals

**Topics:** Voltage/current/resistance, GPIO, digital versus analog inputs, serial monitor, blocking versus nonblocking loops, basic wiring.

- [ ] Inventory Arduino Uno, ESP32, motors, sensors, motor drivers, breadboards, wires, and power supplies; identify exact board and part models.
- [ ] Install Arduino IDE and configure board support for both Arduino Uno and ESP32.
- [ ] Upload a Blink sketch to both boards.
- [ ] Complete Blink Without Delay to understand `millis()` and nonblocking timing.
- [ ] Wire a button or sensor and read it using the Serial Monitor.
- [ ] Recreate an LED/sensor exercise on the ESP32, respecting 3.3 V GPIO limits.
- [ ] Document wiring, code, problems, and solutions in a README.

**Definition of done:** Both boards can upload and run programs; at least one input and output work; the wiring is documented.

### Week 2 - Motors and Sensors

**Topics:** PWM, H-bridge/motor drivers, motor speed/direction, electrical noise, I2C/SPI/UART basics.

- [ ] Identify available motors and confirm whether the kit contains an appropriate motor driver.
- [ ] Safely drive a motor through a motor driver rather than directly from GPIO.
- [ ] Control forward/reverse and speed.
- [ ] Test at least one sensor and collect repeatable readings.
- [ ] Compare desired versus observed physical behavior.

**Definition of done:** A motor can be controlled safely and a sensor can be read reliably.

### Week 3 - ESP32 Wi-Fi Controller

**Topics:** Wi-Fi connectivity, simple command protocol, state machines, telemetry, failsafes.

- [ ] Connect the ESP32 to local Wi-Fi.
- [ ] Send `FORWARD`, `REVERSE`, `STOP` or analogous commands from a local Python script.
- [ ] Report device/motor state to the script.
- [ ] Implement a command timeout so the motor stops if communication fails.
- [ ] Measure and record at least basic round-trip command latency.

**Definition of done:** A safe, working Python-to-ESP32 command channel.

**Recommended material:**

- [Arduino Built-in Examples](https://docs.arduino.cc/built-in-examples/)
- [Arduino-ESP32 documentation](https://docs.espressif.com/projects/arduino-esp32/en/latest/)
- [University of Michigan ROB 311](https://github.com/michiganrobotics/rob311) - select introductory motors and hardware lectures.

## 5. Phase 2 - Build a Physical Rover (Weeks 4-7)

**Goal:** Build and control a custom 3D-printed two-wheel differential-drive robot.

**Architecture:** Computer running Python controller -> Wi-Fi -> ESP32 -> appropriate dual motor driver -> left/right motors, with sensor and optionally encoder feedback.

### Week 4 - Mechanical Design and Printing

- [ ] Choose motors and measure mounting dimensions.
- [ ] Sketch a chassis, wheel placement, battery location, board mounts, and cable management.
- [ ] Model and print chassis parts on the Bambu Lab A1.
- [ ] Assemble a mechanically stable rover; identify potential tip-over or cable-snag issues.

### Week 5 - Power and Motion

- [ ] Install wheels, caster/skid, driver board, batteries, and ESP32.
- [ ] Verify supply voltages, shared ground where required, and motor-driver current ratings.
- [ ] Demonstrate forward/reverse/left/right motion.
- [ ] Test emergency stop and safe startup behavior.

### Week 6 - Wireless Teleoperation

- [ ] Write a minimal keyboard-controlled Python app or local web interface.
- [ ] Control left/right motor speeds remotely.
- [ ] Display command status and connection health.
- [ ] Demonstrate safe handling of disconnection/timeouts.

### Week 7 - Sensor-Assisted Operation

- [ ] Install a compatible obstacle sensor, if available.
- [ ] Stop or slow near an obstacle.
- [ ] Test false readings and corner cases.
- [ ] Record a short demo video and update wiring/CAD documentation.

**Definition of done:** A mechanically stable, remote-controlled rover with a reliable failsafe and basic obstacle sensing.

**Scope discipline:** Avoid spending significant time building a polished mobile app or cloud backend. The key learning goal is physical robot engineering.

## 6. Phase 3 - Math, Kinematics, Odometry and Control (Weeks 8-10)

**Goal:** Understand how wheel motion produces robot motion, and learn when feedback matters.

### Week 8 - Kinematics and Motion Measurement

- [ ] Refresh trigonometry (angles, radians, sine/cosine) and coordinate frames.
- [ ] Learn differential-drive kinematics.
- [ ] Measure robot speed over a known distance.
- [ ] Calculate expected travel from wheel radius and motor rotation.

For a differential-drive robot:

`v = (r/2) * (omega_right + omega_left)`

`omega_robot = (r/L) * (omega_right - omega_left)`

where `r` is wheel radius, `L` is wheel-center separation, and wheel speeds use radians/second.

### Week 9 - Odometry

- [ ] Learn position/heading `(x, y, theta)` and why integration accumulates error.
- [ ] If wheel encoders are available, implement encoder readings and estimate movement.
- [ ] Attempt a measured square using timed commands; record position/heading errors.
- [ ] Repeat using encoder-based targets if hardware allows.

### Week 10 - Feedback and PID

- [ ] Understand setpoint, measurement, error, proportional/integral/derivative terms.
- [ ] If encoders are available, close the loop around motor speed.
- [ ] Compare open-loop versus closed-loop performance.
- [ ] Summarize limits from slippage, battery level, and measurement noise.

**Definition of done:** Can explain differential-drive motion and demonstrate a measured navigation test with quantified error. Encoder/PID work can be deferred if the existing hardware does not support it.

**Recommended material:**

- [Peter Corke's Robot Academy](https://petercorke.com/resources/robot-academy/)
- [Modern Robotics - Northwestern University](https://modernrobotics.northwestern.edu/)
- [University of Michigan free online robotics courses](https://robotics.umich.edu/academics/courses/online-courses/)

## 7. Phase 4 - ROS 2 and Simulation (Weeks 11-15)

**Goal:** Learn widely-used robot middleware and a simulation-driven development workflow.

**Starting software stack:** Ubuntu 24.04, ROS 2 Jazzy, Gazebo Harmonic, Python nodes. Confirm compatibility before installing on a specific computer or VM. If using macOS or Apple Silicon, plan a supported Linux environment or adjust the simulator strategy rather than assuming every native install path works.

### Week 11 - ROS 2 Foundations

- [ ] Set up a working ROS 2 development environment.
- [ ] Run `turtlesim`.
- [ ] Practice nodes, topics, `ros2 topic`, and CLI introspection.
- [ ] Publish velocity commands and inspect messages.

### Week 12 - Write Python ROS 2 Nodes

- [ ] Create a workspace and Python package.
- [ ] Write publisher and subscriber nodes.
- [ ] Try a service and action; understand when to use each.
- [ ] Add a test and a launch file.

### Week 13 - Robot Models and Coordinate Frames

- [ ] Learn `tf2`, URDF, joints, links, and frames.
- [ ] Create or adapt a simple two-wheel robot description.
- [ ] Display the robot in RViz.

### Week 14 - Gazebo

- [ ] Launch a Gazebo simulation with a wheeled robot.
- [ ] Observe physics, sensor, and command interfaces.
- [ ] Understand how ROS messages reach the simulated model.

### Week 15 - Control and Observability

- [ ] Drive the simulated robot by teleoperation.
- [ ] Inspect sensor streams, record/replay with rosbag where feasible.
- [ ] Add basic logging and diagnostics.
- [ ] Write a setup README for reproducibility.

**Definition of done:** Your own Python ROS 2 package can command and monitor a simulated robot.

**Recommended material:**

- [ROS 2 Jazzy tutorials](https://docs.ros.org/en/jazzy/Tutorials.html)
- [Gazebo Harmonic documentation](https://gazebosim.org/docs/harmonic/)

**Important:** The physical ESP32 rover does not need to run ROS 2. A ROS node on the laptop can communicate with the ESP32 via Wi-Fi or serial later. Prioritize simulation first.

## 8. Phase 5 - Autonomous Navigation (Weeks 16-20)

**Goal:** Navigate a simulated environment autonomously and learn localization, mapping, planning, and obstacle handling.

### Week 16 - Nav2 Getting Started

- [ ] Launch the Nav2-supported simulated robot example.
- [ ] Inspect map, robot pose, planned paths, and navigation goals.
- [ ] Complete a point-to-point navigation demo.

### Week 17 - Frames, Pose and Localization

- [ ] Learn `map`, `odom`, `base_link`, and typical frame relationships.
- [ ] Examine simulated wheel odometry and localization estimates.
- [ ] Diagnose a frame or localization issue in a controlled test.

### Week 18 - SLAM and Mapping

- [ ] Use a simulated range sensor to create a 2D occupancy grid.
- [ ] Drive or teleoperate while mapping.
- [ ] Save and reload a usable map.

### Week 19 - Planning and Avoidance

- [ ] Send several target poses.
- [ ] Compare planned path and actual robot trajectory.
- [ ] Test obstacle avoidance and failure recovery.

### Week 20 - Autonomous Delivery Mission

- [ ] Implement stations A/B and a return-to-start mission.
- [ ] Record success/failure for each waypoint.
- [ ] Add retries/timeouts or an abort state.
- [ ] Record video of the full simulated mission.

**Definition of done:** A simulated autonomous delivery robot navigates between waypoints, with a documented architecture and reproducible demo.

**Recommended material:**

- [Nav2 Jazzy Getting Started](https://docs.nav2.org/jazzy/getting_started/)
- [ROS 2 Jazzy tutorials](https://docs.ros.org/en/jazzy/Tutorials.html)

**Scope note:** Real physical SLAM is not required; it would add sensor, computer, and integration costs beyond the core budget.

## 9. Phase 6 - Capstone and Career Exploration (Weeks 21-24)

**Choose one capstone** based on which earlier phases were most enjoyable.

### Option A: Robot Fleet / Orchestration Software (closest transfer from backend)

- Build a Python service to accept mission requests.
- Dispatch missions to a simulated ROS 2 robot.
- Monitor state transitions, mission progress, and failures.
- Implement clear status/telemetry and tests.
- Stretch: multiple simulated robots and simple job scheduling.

**Explore:** Robotics infrastructure, fleet software, distributed systems, robot orchestration.

### Option B: Robot Arm / Manipulation

- Use an existing MoveIt 2 sample arm in simulation.
- Understand joints, forward and inverse kinematics.
- Plan a simple reaching or pick-and-place movement.
- Stretch: 3D-print a simple servo-operated arm/gripper.

**Explore:** Motion planning, controls, manipulation, mechatronics.

**Resource:** [MoveIt 2 tutorials](https://moveit.picknik.ai/main/doc/tutorials/tutorials.html)

### Option C: Embedded Controller and Control Quality

- Refactor rover firmware with explicit states and faults.
- Add interrupt-driven encoder tracking if supported.
- Implement and test closed-loop wheel speed control.
- Measure latency, loop timing, and behavior under communication loss.

**Explore:** Embedded C/C++, firmware, real-time constraints, mechatronics, controls.

**Definition of done:** A working capstone, tests, demonstration, architecture writeup, and career reflection.

## 10. Hardware Purchasing Guide

**Do not purchase until your Week 1 inventory is complete.** Prices are approximate, not current purchase quotes.

| Component | Approximate additional spend | Notes |
| --- | ---: | --- |
| Dual motor driver | $5-$15 | Verify voltage and current ratings for your motors |
| Geared DC motors with encoders (pair) | $20-$40 | May replace existing motors; useful for Phase 3 |
| Wheels and caster | $8-$20 | Might already be included |
| Suitable power supply / battery accessories | $15-$35 | Choose safe, compatible power solution |
| Mounting hardware/connectors | $10-$20 | Reuse printed mounts where possible |
| IMU | $5-$15 | Optional extension |
| Small servos | $5-$20 | Optional arm capstone |
| Miscellaneous sensors | $10-$25 | Optional |

**Planned core rover spending:** Roughly $60-$150 depending on what is already owned, with a hard exploratory budget of $100-$250 unless explicitly revised.

### Basic electrical safety

- Never drive a DC motor directly from Arduino/ESP32 GPIO.
- Use a motor driver rated for the motor's stall current, operating voltage, and control-level voltage.
- ESP32 GPIO is typically 3.3 V logic and must not be exposed directly to 5 V outputs.
- Check polarity, wiring, fusing/protection where appropriate, and battery handling before powering a new system.
- Ensure loss of wireless communication causes a safe motor stop.

## 11. Weekly Time Allocation (Example: 7 hours)

- 4 hours: building, testing, and debugging.
- 1.5 hours: courses and documentation.
- 1 hour: math and theory.
- 0.5 hour: notes, tests, and GitHub documentation.

Adjust if a difficult hardware issue or simulator setup takes longer. Building fluency matters more than a calendar target.

## 12. Career Fit Evaluation

After every phase, score each statement from 1 (strongly disagree) to 5 (strongly agree):

1. I enjoyed the work, including frustrating debugging sessions.
2. I wanted to understand the system, not just get a pass/fail result.
3. I would willingly spend another weekend improving this project.
4. I can imagine doing similar engineering work professionally.

**Total:** 4-20. Use results comparatively across phases; this is not a validated career test.

### Potential career paths

| Path | Transfer from current backend skills | Main gap to develop |
| --- | --- | --- |
| Robotics infrastructure / fleet software | Very high | ROS 2 concepts, telemetry, mission lifecycle |
| Robotics software | High | ROS 2, C++, simulation, kinematics |
| Autonomy / navigation | Medium | SLAM, planning, probability, localization |
| Embedded / firmware | Medium | C/C++, electronics, RTOS, timing |
| Controls / manipulation | Lower initially | Linear algebra, mechanics, dynamics, control theory |

**Decision checkpoint:** End of Phase 4. Compare enjoyment of hands-on electronics and mechanical design versus ROS 2/simulation. Choose Phase 6 accordingly.

## 13. Weekly Progress Tracker

Update one row at the end of each weekly chat. The week numbers represent milestones, not mandatory calendar deadlines.

| Week | Topic | Status | Date completed | Demo / repo / notes |
| ---: | --- | --- | --- | --- |
| 1 | Hardware inventory and GPIO | Completed | 2026-10-18 | [esp32-rover](https://github.com/JHuang251998/esp32-rover) - 7 compiled sketches; Uno and ESP32 physical I/O verified; wiring and learning summary documented; commit `7bfffb1` |
| 2 | Motors and sensors | Not started | | |
| 3 | ESP32 Wi-Fi control | Not started | | |
| 4 | CAD and chassis | Not started | | |
| 5 | Rover power and motor assembly | Not started | | |
| 6 | Remote control | Not started | | |
| 7 | Obstacle detection and rover demo | Not started | | |
| 8 | Differential-drive kinematics | Not started | | |
| 9 | Odometry | Not started | | |
| 10 | Feedback / PID | Not started | | |
| 11 | ROS 2 basics | Not started | | |
| 12 | Python ROS 2 nodes | Not started | | |
| 13 | TF2, URDF, RViz | Not started | | |
| 14 | Gazebo simulation | Not started | | |
| 15 | ROS control and debugging | Not started | | |
| 16 | Nav2 quickstart | Not started | | |
| 17 | Localization | Not started | | |
| 18 | SLAM and maps | Not started | | |
| 19 | Planning and obstacle avoidance | Not started | | |
| 20 | Autonomous delivery demo | Not started | | |
| 21 | Capstone scoping | Not started | | |
| 22 | Capstone implementation | Not started | | |
| 23 | Capstone testing and demo | Not started | | |
| 24 | Portfolio, reflection, next-step decision | Not started | | |

## 14. Weekly Study Chat Protocol

Chat titles:

- `00 - Robotics Learning Roadmap` (master conversation)
- `Week 01 - Arduino & ESP32 Basics`
- `Week 02 - Motors & Electronics`
- `Week 03 - ESP32 Wi-Fi Control`
- Continue one chat per weekly milestone.

### Instructor expectations for each weekly chat

- Follow the master roadmap, but adapt based on completed work and available hardware.
- Teach underlying engineering concepts and ask probing questions.
- Favor hints and guided debugging over complete solutions unless requested.
- Verify understanding with practical mini-challenges.
- Do not require new hardware unless necessary.
- At the end, generate a weekly summary with concepts, parts, projects, blockers, technical decisions, and next steps.

### End-of-week report template

```
# Week NN - Weekly Learning Summary

## Completed
- 

## Key concepts learned
- 

## Hardware/software used
- 

## Bugs and fixes
- 

## Demo / repository link
- 

## Remaining questions
- 

## Career interest reflection (1-5 each)
- Enjoyed work/debugging:
- Wanted deeper understanding:
- Willing to spend extra time:
- Can imagine as a career:

## Recommended next week
- 
```

## 15. Recommended Learning Resource Index

- **Arduino basics:** https://docs.arduino.cc/built-in-examples/
- **ESP32 Arduino reference:** https://docs.espressif.com/projects/arduino-esp32/en/latest/
- **Michigan ROB 311:** https://github.com/michiganrobotics/rob311
- **Michigan open robotics courses:** https://robotics.umich.edu/academics/courses/online-courses/
- **Peter Corke Robot Academy:** https://petercorke.com/resources/robot-academy/
- **Modern Robotics:** https://modernrobotics.northwestern.edu/
- **ROS 2 Jazzy:** https://docs.ros.org/en/jazzy/Tutorials.html
- **Gazebo Harmonic:** https://gazebosim.org/docs/harmonic/
- **Nav2 Jazzy:** https://docs.nav2.org/jazzy/getting_started/
- **MoveIt 2:** https://moveit.picknik.ai/main/doc/tutorials/tutorials.html
- **MIT Robotic Manipulation:** https://manipulation.mit.edu/
- **MIT Underactuated Robotics:** https://underactuated.mit.edu/

## 16. Change Log

| Date | Version | Notes |
| --- | --- | --- |
| 2026-10-11 | 1.0 | Initial consolidated master plan reconstructed from original roadmap chat, with progress tracking and resource links. |
| 2026-10-18 | 1.1 | Week 1 completed; confirmed first GitHub repository and prepared Week 2 motor/sensor inventory. |
