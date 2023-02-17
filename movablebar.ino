#include <OneWire.h>
#include <DallasTemperature.h>

#include <LiquidCrystal_I2C.h>

// onewire on 4
#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);	
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);

float setTemperature = 4.0;

unsigned long last_interrupt_time = millis();
unsigned long last_relais_time = 0;

void setTempHigher() {
  if (millis() - last_interrupt_time > 250) 
  {
    setTemperature = setTemperature + 0.5;
    last_interrupt_time = millis();
  }
}

void setTempLower() {
  if (millis() - last_interrupt_time > 250) 
  {
    setTemperature = setTemperature - 0.5;
    last_interrupt_time = millis();
  }
}

void setup() {
  // put your setup code here, to run once:
  sensors.begin();	// Start up the library
  Serial.begin(9600);

  pinMode(5, OUTPUT); // relais output
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(2), setTempHigher, LOW);
  attachInterrupt(digitalPinToInterrupt(3), setTempLower, LOW);

  lcd.init(); // initialize the lcd
  lcd.backlight();

  lcd.clear();                 // clear display
  lcd.setCursor(0, 0);
  lcd.print("cur temp: ");        // print message at (0, 0)

  lcd.setCursor(0, 1);
  lcd.print("set temp: ");        // print message at (0, 0)

}

void loop() {

  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();

  float temperature = sensors.getTempCByIndex(0);

  lcd.setCursor(11, 0);
  lcd.print(temperature);        // print message at (0, 0)

  lcd.setCursor(11, 1);
  lcd.print(setTemperature);        // print message at (0, 0)

  if (millis() - last_relais_time > 120000) {
    if (temperature <= setTemperature) {
      digitalWrite(5, LOW);
    } else if (temperature >= setTemperature + 2) {
      digitalWrite(5, HIGH);
    }
    last_relais_time = millis();
  }
  delay(1000);
}
