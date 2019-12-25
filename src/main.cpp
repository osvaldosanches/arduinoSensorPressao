#include <LiquidCrystal.h>

int sensorPin = A0;
int sensorValue = 0;
float Vout, Value_Kpa, Value_mmHg;

LiquidCrystal lcd(2,3,4,5,6,7);

void setup() {

  lcd.begin(16, 2);
  lcd.display();

}

void loop() {

  sensorValue = analogRead(sensorPin);

  Vout = (sensorValue * 0.00459); //valor de tensao - 0.004594330400782013
  Value_Kpa = (Vout - 0.2)/0.09; //valor de pressao - quilopascals 
  Value_mmHg = Value_Kpa * 7.50061; //converter kPa para mmHg - 7.50061561303 - milímetros de mercúrio

  if(Value_Kpa < 0) Value_Kpa = 0, Value_mmHg = 0;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(Value_Kpa, 0);
  lcd.print("Kpa");
  lcd.setCursor(11, 0);
  lcd.print(Vout);
  lcd.print("V");

  lcd.setCursor(0, 1);
  lcd.print(Value_mmHg, 0);
  lcd.print("mmHg");
  delay(500);



}