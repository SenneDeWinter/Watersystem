#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

int pump = 13;
int moisture;

void setup() {
  initiate_lcd();
  Serial.begin(57600);
}

void loop() {
  read_humidity();
  control_moisture();
}

void initiate_lcd() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  lcd.setCursor(0, 1);
  lcd.print("haha. yes.");
}


void control_moisture() {
  moisture = analogRead(A0);


  if (moisture < 300) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Im dying!");
    lcd.setCursor(0, 1);
    lcd.print("Watering");

    digitalWrite(13, HIGH);
    delay(2000);
    digitalWrite(13, LOW);
  }
  if (300 < moisture < 700) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Im fine!");
    lcd.setCursor(0, 1);
    delay(5000);
  }
  if (moisture > 900) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Im drowning!");
    digitalWrite(13, LOW);
    delay(5000);
  }
}

void read_humidity() {

  Serial.println(moisture);

}
