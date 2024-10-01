# Arduino Weather Station

  This project involves creating a weather station using an Arduino microcontroller to measure and log environmental data such as temperature and humidity, which is then displayed on a Nokia 5110 LCD screen.

## What is a Weather Station?

  A weather station is a setup consisting of various sensors that collect information about the atmosphere, typically including temperature, humidity, barometric pressure, wind speed, and rainfall. This data can be used for weather forecasting, climate studies, or personal curiosity. With an Arduino-based weather station, you can build your own affordable, customizable solution for monitoring the environment around you.

## Project Overview

The Arduino Weather Station project uses a combination of sensors to gather weather-related data and displays this information on a Nokia 5110 LCD. The code for this project is written in Arduino C++ and can be easily adapted or expanded to include additional sensors or functionality.
<img src="https://github.com/user-attachments/assets/03372b42-c26b-4725-b1fb-f74cd4396c90" alt="Scrot 2024-10-09 035541" style="border:2 solid lightblue;"/>
### Contents

- **StationModel1.ino**: The main Arduino code file for the weather station.

## Requirements

To use this project, you will need:

- **Arduino LEONARDO or Compatible Board**: The main microcontroller for running the code.
- **DHT22 Sensor**: A sensor used to measure temperature and humidity.
- **Nokia 5110 LCD Display**: A small, monochrome LCD display for visualizing sensor data.
- **10kΩ Resistor**: A pull-up resistor to stabilize the data line for the DHT22 sensor.
- **Jumper Wires**: To make connections between the sensor, display, and the Arduino.

<img src="https://github.com/user-attachments/assets/3f879672-f10e-4173-b48b-92f0ecfb2532" alt="Screenshot 2024-10-09 035541" width="330" height="330" style="border:2 solid lightblue;"/>
<img src="https://github.com/user-attachments/assets/a4c3f56a-a635-4da3-9f89-9b8a0a2e71ff" alt="Screenshot 2024-10-00 035541" width="330" height="330" style="border:2 solid lightblue;"/>
<img src="https://github.com/user-attachments/assets/a7217dd7-ae48-4efc-82f4-dbca0bbbc899" alt="Screenshot 2024-10-03 035541" width="250" height="200" style="border:2 solid lightblue;"/>

## Library Installation

This project uses a few libraries to work with the display and the sensor. You need to install the following libraries:

1. **Adafruit GFX Library**: Provides graphics support for drawing shapes and text.
2. **Adafruit PCD8544 (Nokia 5110) Library**: Handles communication with the Nokia 5110 LCD.
3. **DHT Sensor Library**: For working with DHT22 sensors to read temperature and humidity.

### How to Install Libraries

1. Open the **Arduino IDE**.
   
2. Go to **Sketch** > **Include Library** > **Add.ZIP Library...**.
    
3. In the Library Manager, search for and install the following libraries:
   
   - **Adafruit GFX Library** by Adafruit
     
     ```sh
     https://github.com/adafruit/Adafruit-GFX-Library
     
   - **Adafruit PCD8544 Nokia 5110 LCD Library** by Adafruit
     
     ```sh
     https://github.com/adafruit/Adafruit-PCD8544-Nokia-5110-LCD-library
    
   - **DHT sensor library** by Adafruit
     
     ```sh
     https://github.com/adafruit/DHT-sensor-library
     
     
4. Once all libraries are installed, you can proceed to upload the code to your Arduino.
   
## How to Connect the Components

### Wiring the DHT22 Sensor

The DHT22 sensor has three pins to be connected to the Arduino:

| DHT22 Pin  | Arduino Pin       |
|------------|-------------------|
| VCC        | 3.3V              |
| GND        | GND               |
| DATA       | A0 (Analog Pin 0) |

**Note**: Use a **10kΩ pull-up resistor** between `VCC` (5V) and `DATA` (A0). This resistor is important for stabilizing the data signal from the sensor.

### Wiring the Nokia 5110 LCD Display

The Nokia 5110 LCD requires six connections to the Arduino:

| LCD Pin | Arduino Pin |
|---------|-------------|
| `VCC`   | `3.3V`      |
| `GND`   | `GND`       |
| `CLK`   | `7`         |
| `DIN`   | `6`         |
| `D/C`   | `5`         |
| `CS`    | `4`         |
| `RST`   | `3`         |

Ensure that the display is powered with 3.3V to avoid damage, as it is not designed for 5V operation.

## How to Use

1. **Setup Hardware**: Connect the DHT22 sensor, the 10kΩ resistor, and the Nokia 5110 display to your Arduino according to the wiring instructions above.
2. **Upload Code**: Open the `StationModel1.ino` file in the Arduino IDE. Select your board and port, and upload the code to your Arduino.
3. **Monitor Data**: Once the code is running, your Arduino will start collecting data from the DHT22 sensor and display the temperature and humidity readings on the Nokia 5110 LCD.

## Future Improvements

- Adding more sensors (e.g., barometric pressure, wind speed) for a more comprehensive weather station.
- Storing data on an SD card for long-term tracking.
- Creating a web interface for real-time data visualization.

## License

This project is open-source and free to use under the MIT License.
