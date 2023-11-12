# RS485 Communication between Arduino Master and Slaves

## Overview

This project demonstrates communication between an Arduino master and multiple slave devices using RS485 modules. The master Arduino has buttons to toggle individual pins on the slaves, and each slave has a button to toggle a specific pin on the master.

## Hardware Requirements

- **Master Arduino:**
  - Arduino board (e.g., Arduino Mega)
  - RS485 module
  - Buttons (number corresponding to the number of slaves)
  - LEDs or other output devices (number corresponding to the number of slaves)

- **Slave Arduino:**
  - Arduino board
  - RS485 module
  - Button
  - LED or other output device

## Wiring

### Master Arduino:

#### 1. RS485 Module:

Connect the RS485 module to the Master Arduino.

- Connect the module's `RX` pin to the Arduino's `TX` pin.
- Connect the module's `TX` pin to the Arduino's `RX` pin.
- Connect the module's `DE` (Data Enable) and `RE` (Receiver Enable) pins to any digital pins on the Arduino (e.g., pins 9 and 10).

#### 2. Buttons:

For each button on the Master Arduino (Button1 to Button7):

- Connect one leg of the button to a digital pin on the Arduino (e.g., pins 40 to 52).
- Connect the other leg of the button to the ground (GND) pin.
- Optionally, use a pull-up resistor or enable the internal pull-up resistor on the digital pin.

#### 3. Output Devices:

For each output device on the Master Arduino (Output1 to Output7):

- Connect an LED or other output device to a digital pin on the Arduino (e.g., pins 22 to 34).
- Connect the other leg of the output device to a current-limiting resistor.
- Connect the remaining leg of the resistor to the ground (GND) pin.

### Slave Arduino:

#### 1. RS485 Module:

Connect the RS485 module to the Slave Arduino.

- Connect the module's `RX` pin to the Arduino's `TX` pin.
- Connect the module's `TX` pin to the Arduino's `RX` pin.
- Connect the module's `DE` (Data Enable) and `RE` (Receiver Enable) pins to any digital pin on the Arduino.

#### 2. Button:

Connect the button on the Slave Arduino:

- Connect one leg of the button to a digital pin on the Arduino (e.g., pin 7).
- Connect the other leg of the button to the ground (GND) pin.
- Optionally, use a pull-up resistor or enable the internal pull-up resistor on the digital pin.

#### 3. Output Device:

Connect the output device on the Slave Arduino:

- Connect an LED or other output device to a digital pin on the Arduino (e.g., pin 9).
- Connect the other leg of the output device to a current-limiting resistor.
- Connect the remaining leg of the resistor to the ground (GND) pin.

Ensure that you double-check the pin assignments in your code to ensure they match the physical connections. Additionally, verify that the RS485 modules are configured with the correct termination resistors if required by your hardware setup.


## Software Requirements

- Arduino IDE
- SoftwareSerial library

## How to Use

1. **Upload Code:**
   - Upload the master code to the master Arduino.
   - Upload the slave code to each slave Arduino.

2. **Wiring:**
   - Connect the hardware as specified in the "Wiring" section.

3. **Configure Slave Numbers:**
   - In the slave code, set the `slaveNumber` variable to a unique number for each slave.

4. **Run the System:**
   - Power up the master and slave Arduino devices.

5. **Master Operation:**
   - Press the buttons on the master Arduino to toggle the corresponding pins on the slaves.

6. **Slave Operation:**
   - Press the button on each slave Arduino to toggle a specific pin on the master.

## Additional Notes

- Adjust pin numbers and configurations in the code to match your specific hardware setup.

- Ensure that the baud rates in the code match the settings of your RS485 modules.

## Troubleshooting

- If communication issues arise, double-check the wiring and ensure proper connections.

- Verify that the RS485 modules are configured with the correct termination resistors.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.

## Acknowledgments

- Thanks to the Arduino community for their support and contributions.

