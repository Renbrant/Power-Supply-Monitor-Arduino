# Arduino Power Supply Monitor

An Arduino-based monitoring system designed to track voltage, current, and wattage in real-time. This project was specifically developed to test audio amplifiers, allowing for precise graphical analysis of voltage drops and current behavior to ensure the power supply is not limiting equipment performance.

## 📺 Project Video
Click the image below to watch the detailed explanation of the system, hardware setup, and monitoring goals:

[![Arduino Power Supply Monitor](https://img.youtube.com/vi/y2zvvojK88o/maxresdefault.jpg)](https://youtu.be/y2zvvojK88o)

## 🚀 Features
- **Real-time Monitoring:** Tracks Voltage (V), Amperage (A), and Wattage (W).
- **High Precision ADC:** Uses the **ADS1115** for accurate voltage readings via a voltage divider.
- **Isolated Current Sensing:** Employs the **ACS712** Hall-effect sensor for safe, isolated current measurement.
- **Symmetrical Supply Support:** Designed to monitor both positive and negative rails of a symmetrical power supply using operational amplifiers to process negative signals.
- **Performance Analysis:** Ideal for identifying power bottlenecks during high-demand tests (e.g., audio amplifier stress tests).

## 🛠️ Hardware Components
- **Microcontroller:** Arduino (any compatible board).
- **ADC:** ADS1115 (16-bit Analog-to-Digital Converter).
- **Current Sensor:** ACS712 (Hall Effect).
- **Other:** Voltage divider resistors, Op-amps (for symmetrical rail monitoring).

## 📂 Project Status
- [x] **Firmware:** The source code is available in this repository.
- [ ] **Schematics:** Currently not included. If you are interested in the wiring diagram, please open an issue or reach out, and I will research and recreate it for sharing.

---
*Developed for power delivery analysis and electronic equipment testing.*
