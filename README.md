# Dustbin Door Opening System using Ultrasonic Sensor and Servo Motor

## Project Overview

This project uses an ultrasonic sensor and a servo motor to automate the opening and closing of a dustbin lid. The system detects the proximity of a person and adjusts the lid’s opening angle based on the distance. The system operates as follows:

- **0-10 cm:** Lid opens fully (90 degrees).
- **11-20 cm:** Lid opens moderately (60 degrees).
- **21-30 cm:** Lid opens slightly (30 degrees).
- **>30 cm:** Lid remains closed (0 degrees).

## Components Used

- Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- Breadboard
- Jumper Wires
- Resistors (optional)

## Circuit Setup

1. **Ultrasonic Sensor Connections:**
   - VCC: Connect to the 5V pin on the Arduino.
   - GND: Connect to GND.
   - Trig: Connect to pin 9.
   - Echo: Connect to pin 10.

2. **Servo Motor Connections:**
   - Signal: Connect to pin 6.
   - VCC: Connect to the 5V pin.
   - GND: Connect to GND.

## How It Works

1. The ultrasonic sensor measures the distance of a person approaching the dustbin.
2. Based on the measured distance, the servo motor rotates to open the dustbin lid at an appropriate angle:
   - 0-10 cm: 90 degrees (fully open).
   - 11-20 cm: 60 degrees.
   - 21-30 cm: 30 degrees.
   - >30 cm: 0 degrees (closed).
3. The system updates the distance and adjusts the lid position in real-time.
