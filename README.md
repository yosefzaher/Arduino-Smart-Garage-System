## Smart Garage System Project Readme
_________________________________________________________________________________________________________________________________________________________________

### Overview:
__________________
The **Smart Garage System** is an Arduino-powered project designed to automate a garage environment. This project utilizes a range of sensors (DHT11, IR sensors, LDR) to enhance security, manage lighting, and monitor environmental conditions within the garage.

Developed by a collaborative team led by **ENG. Yosef Zaher**, along with **Yousef Almarasi, Mohamed Tarek, Yousef Elnagar, Marwan Elshahiy, and Yousry Alsaid**, the Smart Garage System can detect car entry/exit, turn on lighting based on ambient light, and activate an emergency mode if high temperatures are detected, indicating a fire risk.

### Hardware Requirements:
_____________________________________
1. **Arduino Board** (e.g., Arduino Uno)
2. **DHT11 Sensor** - Monitors temperature (for fire detection)
3. **IR Sensors** - 2 units, for entry and exit detection
4. **LDR (Light Dependent Resistor)** - Detects ambient light for lamppost activation
5. **Servo Motors** - Controls entry and exit gates
6. **Buzzer** - Alerts in case of an emergency
7. **LCD Display** - Shows available parking slots and status messages
8. **Wires and Connectors** - Standard jumper wires

### Software Requirements:
___________________________________________________
1. **Arduino IDE** - For programming and uploading code ([Download here](https://www.arduino.cc/en/software))

### Wiring Instructions:
_________________________________________________
1. **Entry Gate IR Sensor** - Connect to digital pin 2 on Arduino.
2. **Exit Gate IR Sensor** - Connect to digital pin 3.
3. **DHT11 Sensor** - Connect data pin to analog pin A1.
4. **LDR Sensor** - Connect to analog pin A0.
5. **Buzzer** - Connect buzzers to digital pins 0 and 1.
6. **Lampposts** - Connect each lamppost to digital pins 8 to 12.
7. **Servo Motors** - Connect entry and exit gate servos to digital pins 4 and 5.
8. **LCD Display** - Use I2C pins (SDA and SCL) for connecting the LCD.

### Key Functionalities:
_______________________

#### 1. **Emergency Fire Detection:**
   - The **DHT11** sensor monitors the temperature inside the garage.
   - If the temperature exceeds a threshold (e.g., 30°C), the system triggers the **emergency alarm** by activating the buzzers.

#### 2. **Car Entry and Exit Detection:**
   - **IR Sensors** are placed at the entry and exit gates to detect car movement.
   - When a car enters or exits, the respective gate opens, and the **car count** is updated on the LCD.

#### 3. **Automatic Lighting Control:**
   - The **LDR sensor** measures ambient light levels to activate the **lampposts** at night or in low-light conditions.

### Arduino Code:
_______________________
The main code file is named **Sensors.ino**. This file contains the core logic for sensor readings, gate control, and alarm activation.

### Usage:
__________________________________
1. **Power on the system** and ensure all sensors are connected.
2. The **LCD display** will show the available parking slots upon startup.
3. **Drive into or out of the garage** to see the system detect movement, open/close the gates, and update the available slot count.
4. **In case of fire detection**, the system will activate the emergency mode.

### Troubleshooting:
_____________________________
- **Sensors not responding**: Check the sensor connections and ensure correct wiring.
- **LCD not displaying correctly**: Verify the I2C connections and LCD initialization in code.
- **Emergency alarm not functioning**: Ensure the buzzer pins are set correctly and that the temperature threshold is suitable for your environment.

__________________________________________________________________________

### Contributors:
  - **ENG. Yosef Zaher**
  - **Yousef Almarasi**
  - **Mohamed Tarek**
  - **Yousef Elnagar**
  - **Marwan Elshahiy**
  - **Yousry Alsaid**

---

This Smart Garage System showcases a practical application of Arduino with sensor integration for enhanced garage automation. Enjoy the added convenience and safety features of a modern garage!

