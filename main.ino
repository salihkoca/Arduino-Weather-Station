#include <SPI.h>               // include SPI library
#include <Adafruit_GFX.h>      // include adafruit graphics library
#include <Adafruit_PCD8544.h>  // include adafruit PCD8544 (Nokia 5110) library
#include <DHT.h>               // include DHT library code

// Nokia 5110 LCD module connections (CLK, DIN, D/C, CS, RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

#define DHTPIN A0            // DHT22 data pin is connected to Arduino analog pin 0
#define DHTTYPE DHT22        // DHT22 sensor is used
DHT dht22(DHTPIN, DHTTYPE);  // configure DHT library

char temperature[] = "000.0 C";
char humidity[] = "000.0 %";

void setup() {
  delay(1000);  // wait 1 second

  // initialize the display
  display.begin();
  // initialize the DHT library
  dht22.begin();

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(50);

  display.clearDisplay();  // clear the screen and buffer
  display.display();

  display.drawFastHLine(0, 23, display.width(), BLACK);

  display.setTextSize(1);
  display.setTextColor(BLACK, WHITE);
  display.setCursor(6, 0);
  display.print("TEMPERATURE:");
  display.setCursor(15, 28);
  display.print("HUMIDITY:");
  display.display();
}

// main loop
void loop() {
  // read humidity
  int RH = dht22.readHumidity() * 10;
  // read temperature in degree Celsius
  int Temp = dht22.readTemperature() * 10;

  // update temperature and humidity arrays
  if (Temp < 0) {
    temperature[0] = '-';
    Temp = abs(Temp);
  } else
    temperature[0] = ' ';
  temperature[1] = (Temp / 100) % 10 + '0';
  temperature[2] = (Temp / 10) % 10 + '0';
  temperature[4] = Temp % 10 + '0';

  if (RH >= 1000)
    humidity[0] = '1';
  else
    humidity[0] = ' ';
  humidity[1] = (RH / 100) % 10 + '0';
  humidity[2] = (RH / 10) % 10 + '0';
  humidity[4] = RH % 10 + '0';

  // print temperature
  display.setCursor(18, 12);
  display.print(temperature);
  // print degree symbol ( ° )
  display.drawRect(50, 12, 3, 3, BLACK);
  // print humidity
  display.setCursor(18, 40);
  display.print(humidity);
  // now update the display
  display.display();

  delay(1000);  // wait 1 second
}
// end of code.