#include<LiquidCrystal.h>
#define trigger=8;
#define echo=9;
float distance=0;
float time=0;
const int rs=12,en=11,d4=5,d5=4,d6=3,d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(40,2);
  lcd.print(" ICT_Innovation_lab                      ");
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
  Serial.begin(9600);
   
}

void loop() {
  // put your main code here, to run repeatedly:
  
  lcd.setCursor(0,1);
  lcd.print(" Distance: ");
  //lcd.print(millis()/1000);
  //delay(1000);
  
  digitalWrite(8,LOW);
  delayMicroseconds(2);
  digitalWrite(8,HIGH);
  delayMicroseconds(2);
  digitalWrite(8,LOW);
  delayMicroseconds(2);
  time=pulseIn(9,HIGH);
  distance=time*340/20000;
  lcd.print(distance);
  lcd.print(" cm                    ");
  Serial.print(distance);
  
  delay(1000);
 


}
