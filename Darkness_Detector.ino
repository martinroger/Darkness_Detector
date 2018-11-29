#include <LiquidCrystal.h>

//This is using the weird shield
LiquidCrystal lcd(8,9,4,5,6,7);
int buttonPin = A0;
int buttonSensorValue = 0;
int previous_Value = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("Starting Up");
  delay(3000);
  lcd.clear();
  lcd.blink();
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonSensorValue = analogRead(buttonPin);
  if (buttonSensorValue != previous_Value) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Value ");
    lcd.print(buttonSensorValue);
    lcd.setCursor(0,1);
    lcd.print("Previous ");
    lcd.print(previous_Value);
    previous_Value = buttonSensorValue;
  }
  delay(500);
}

//Output values on A0 :
//1023 rien d'appuyé
//741 - SELECT
//505 - LEFT
//141 - UP
//330 - DOWN
//0 - RIGHT
