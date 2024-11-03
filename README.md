# Smart Garage System

_________________________________________________________________________________________________________________________________________________________________

### Overview
__________________

The **Smart Garage System** is an advanced, Arduino-based project designed to automate and enhance garage management with intelligent capabilities. Equipped with cutting-edge sensor technology, this system monitors environmental conditions, manages entry and exit points, and adjusts lighting based on ambient light levels. Prioritizing safety and convenience, the system also integrates an emergency alert mechanism to detect fire risks and manage occupancy effectively.

#### Developed by:
**ENG. Yosef Zaher**  
**Contributors:** Yousef Almarasi, Mohamed Tarek, Yousef Elnagar, Marwan Elshahiy, Yousry Alsaid

---

### Hardware Requirements
_____________________________________

- **Arduino Board** (e.g., Arduino Uno)
- **DHT11 Temperature and Humidity Sensor** – Monitors temperature to detect potential fire hazards
- **IR Sensors (2 units)** – Detects car entry and exit
- **LDR (Light Dependent Resistor)** – Activates garage lighting based on ambient light levels
- **Servo Motors (2 units)** – Controls entry and exit gates
- **Buzzer** – Sounds an alert in case of an emergency
- **LCD Display with I2C Module** – Displays system status and notifications in real-time

### Software Requirements
___________________________________________________

- **Arduino IDE** ([Download here](https://www.arduino.cc/en/software))

### Wiring Instructions
_________________________________________________

1. Connect the **DHT11 sensor** to the designated data pin on the Arduino.
2. Set up **IR sensors** near the garage entry and exit points.
3. Connect the **LDR** to the Arduino to control the lighting based on ambient brightness.
4. Attach the **servo motors** to control the entry and exit gates.
5. Connect the **buzzer** to signal alerts.
6. Wire the **LCD with I2C module** to display status information, connecting to the I2C pins (SDA, SCL) on the Arduino.
7. Ensure all components share a common ground, and use a reliable power source for the Arduino and sensors.

### Arduino Code
_______________________

The project code is provided in the file named `SmartGarageSystem.ino`.

### Usage
__________________________________

1. Upload the code to the Arduino using the Arduino IDE.
2. Power on the system and monitor the LCD for real-time updates on temperature, entry/exit status, and lighting control.
3. Place the IR sensors and servo motors at the appropriate points in the garage for optimal functionality.
4. Test the system by simulating entry, exit, and changes in ambient lighting.

### Bluetooth Integration (Optional)
_______________________________

The system can be further enhanced with Bluetooth connectivity to receive alerts or control the garage remotely. If adding Bluetooth, connect an HC-05 module and modify the code to handle Bluetooth communication.

### Troubleshooting
_____________________________

- **No display on LCD:** Check I2C connections and ensure the I2C address matches the code.
- **IR sensors not detecting:** Verify sensor wiring and placement; ensure the sensors face the expected path of the car.
- **Temperature readings incorrect:** Ensure the DHT11 sensor is securely connected and not near heat sources other than environmental temperature.

---

### License
__________________________________________________________________________

This project is licensed under the MIT License - see the LICENSE file for details.

### Contributors:
- **ENG. Yosef Zaher** (Lead Developer)
- **Team Members:** Yousef Almarasi, Mohamed Tarek, Yousef Elnagar, Marwan Elshahiy, Yousry Alsaid
