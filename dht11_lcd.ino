#include <DHT.h>
#include <LiquidCrystal.h>


#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  dht.begin();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.write("  TEMP    HUMI  ");
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h)||isnan(t)) {
    Serial.println("FAIL");
    return;
  }
  String temp;
  String humi;
  temp = String(t);
  humi = String(h);
  lcd.setCursor(0, 1);
  lcd.write("        ");
  lcd.setCursor(0, 1);
  lcd.print(temp);
  lcd.setCursor(8, 1);
  lcd.write("        ");
  lcd.setCursor(8, 1);
  lcd.print(humi);
}