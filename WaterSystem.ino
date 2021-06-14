#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

int moisture;

void setup() {
  initiate_lcd();
  Serial.begin(57600);
  pinMode(12, OUTPUT);
}

void loop() {
  read_humidity();
  control_moisture();
}

void initiate_lcd() {
  lcd.init();
  lcd.backlight();
}

void control_moisture() {
  if (moisture < 300) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Te droog");
    lcd.setCursor(0, 1);
    lcd.print("Pomp aan");
    digitalWrite(12, HIGH);
    delay(5000);
  }
  if (moisture > 950) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OK");
    lcd.setCursor(0, 1);
    digitalWrite(12, LOW);
    delay(5000);
  }
}

void read_humidity() {
  moisture = analogRead(A3);
  Serial.println(moisture);

}
