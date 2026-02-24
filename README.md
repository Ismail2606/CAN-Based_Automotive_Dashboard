# CAN-Based Automotive Dashboard (Multi-ECU System)
---

## Description
This project implements a **multi-ECU automotive dashboard system** using the CAN (Controller Area Network) protocol. It simulates real-time communication between multiple ECUs in a vehicle.

- **ECU1** → Speed & Gear Position  
- **ECU2** → RPM & Indicators on Led's 
- **ECU3** → CLCD Display  

The system uses both **analog (ADC)** and **digital (keypad)** inputs to mimic real automotive behavior.

---

## ECU Functionalities

### ECU1 (Speed & Gear Module)
- Reads **Speed using ADC**
- Reads **Gear using Digital Keypad**
- Sends data via CAN

### ECU2 (RPM & Indicators Module)
- Reads **RPM using ADC**
- Controls:
  - Left Indicator  
  - Right Indicator  
- Uses **Digital Keypad for input**
- Controls LEDs
- Sends data via CAN

### ECU3 (Display Module)
- Receives CAN messages
- Displays:
  - Speed
  - Gear
  - RPM
  - Indicator status on **CLCD**

---

## Input Methods

### Digital Keypad
Used for:
- Gear Position (N/R/1/2/3/4/5)
- Indicator Control (Left / Right)

---

### ADC (Analog Input)
Used for:
- Speed  
- RPM  

Working:
- Analog signal → ADC → Digital value  
- Converted into Speed (km/h) and RPM  

---

## LED Indicators
- Left Indicator LED  
- Right Indicator LED  

- Controlled via CAN messages  
- Supports blinking behavior  

---

## Concepts Used
- CAN Protocol  
- Embedded C  
- ADC (Analog-to-Digital Conversion)  
- Digital Input (Keypad)  
- CLCD interfacing  
- GPIO (LED control)  
- Real-time systems  

---

