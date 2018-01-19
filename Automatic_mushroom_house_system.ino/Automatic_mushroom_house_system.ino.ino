#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define Lamp1 8   //พัดลม1
#define Lamp2 9   //ปั๊มน้ำ
#define Lamp3 10  //cooling pad 
#define Lamp4 11  //ไอน้ำ
//#define Lamp5 12  //เครื่องทำความร้อน

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht;

void setup()
{
  Serial.begin(9600);
  Serial.println();
  pinMode(Lamp1, OUTPUT); //กำหนดโหมดให้เป็น Output
  pinMode(Lamp2, OUTPUT);
  pinMode(Lamp3, OUTPUT);
  pinMode(Lamp4, OUTPUT);
  //pinMode(Lamp5, OUTPUT);
  //Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");

  dht.setup(2); // data pin 2
  // initialize the LCD
  lcd.begin();
  //lcd.setCursor(4, 0);
  //lcd.print("Hello (^__^)");
  //lcd.clear();
        //lcd.setCursor(2, 1);
        //lcd.print("ThaiEasyElec");
        //lcd.clear();
}

void loop()
{
   delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  //lcd.print(dht.getStatusString());
  lcd.setCursor(0, 0);
  lcd.print("H:");
  lcd.print(humidity, 1);
   lcd.print("%");
  lcd.print(" C:");
  lcd.print(temperature, 1);
  
  lcd.setCursor(0, 1); 
  lcd.print("HIGH:70");
   lcd.setCursor(8, 1); 
  lcd.print("HIGH:35");
 //ตรวจสอบความชื่นถ้ามากกว่า 80 % ให้พัดลมทำงาน
  if(humidity>=80){
      //digitalWrite(Lamp5, LOW);
    } else{
      //digitalWrite(Lamp5, HIGH);
    }
/////////////////////////////////////////////////////
//ตรวจสอบความชื้นถ้าน้อยกว่า 70% ให้เปิดปั๊มน้ำ และเปิดไอพุ้นหมอก
  if(humidity>=70){
    
    digitalWrite(Lamp2, HIGH);//ปิดปั๊มน้ำ
    digitalWrite(Lamp4, HIGH);//ปิดไอหมอก
    }   
   else{
    digitalWrite(Lamp2, LOW);//เปิดปั๊มน้ำ
    digitalWrite(Lamp4, LOW);//เปิดไอหมอก
    }
  /////////////////////////////////////////////////////////
  //ตรวจสอบอุณหภูมิถ้ามากกว่า 35 องศา ให้เปิดพัดลม เปิด Cooling pad และปั๊มน้ำ
  if(temperature>=35)
  { 
     
   digitalWrite(Lamp1, HIGH); //ปิดพัดลม
   digitalWrite(Lamp2, HIGH);
   digitalWrite(Lamp3, HIGH);
  // digitalWrite(Lamp4, LOW);
   //digitalWrite(Lamp5, LOW);
   
  }
  else
  {
   //lcd.clear();
   lcd.setCursor(0, 1);
   digitalWrite(Lamp1, LOW);
   digitalWrite(Lamp2, LOW);
   digitalWrite(Lamp3, LOW);
  // digitalWrite(Lamp4, HIGH);
  // digitalWrite(Lamp5, HIGH);
  // lcd.clear();
   
  }
  delay(1000);
 
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
