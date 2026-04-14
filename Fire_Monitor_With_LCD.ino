#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int Buzzer = 13;

void setup() {
  pinMode(Buzzer, OUTPUT);
  
  Serial.begin(9600);
  lcd.begin(16, 2);
    
  lcd.setCursor(1, 0);
  lcd.print(" Loading...");
  delay(2000);
  lcd.clear();
  
}

void loop() {
  
  int Sensor_Val = analogRead(A0);
  float voltage = Sensor_Val * (5.0 / 1023.0);
  float celsius = (voltage - 0.5) * 100;
  
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(celsius);
  lcd.print(" C     ");
  
  if(celsius > 50.0) {
    Serial.println("High Flame");
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, 1000);
    lcd.setCursor(0, 1);
    lcd.print("!! FIRE ALARM !!");
  }
  else {
    Serial.println("Everything OK");
    digitalWrite(Buzzer, LOW);
    noTone(13);
    lcd.setCursor(0, 1);
    lcd.print("Status: Normal");
  }
  
    
  
}
