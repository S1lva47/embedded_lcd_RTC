#include <Arduino.h>
#include <LiquidCrystal.h>
#include <RTClib.h>

size_t last_seg;
DateTime now; 

LiquidCrystal lcd(12,11,10,9,8,7);
RTC_DS1307 rtc;


void time();

void setup() {
  //start LCD
  lcd.begin(16,2);

  Serial.begin(9600);
  //Start RTC and config
  if (!rtc.begin()){
    Serial.println("the device no started");
    Serial.flush();
   
  }
  Serial.println("RTC on!");
  rtc.writeSqwPinMode(DS1307_SquareWave1HZ);
    
  

}

void loop() {
  now = rtc.now();
  if (now.second() > last_seg){
    lcd.clear();
    time();
    last_seg = now.second();
  }
}
  

void time(){
  DateTime now = rtc.now();
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  lcd.println();
  
}



