int ledPin1 = 9;  // ขั้วบวก LED เชื่อมต่อกับขาดิจิตอล 9
int ledPin2 = 10; // ขั้วบวก LED เชื่อมต่อกับขาดิจิตอล 10
int ledPin3 = 11; // ขั้วบวก LED เชื่อมต่อกับขาดิจิตอล 11

int inputPin1 = 2; // สวิทช์ความใกล้ชิดอินฟราเรดเชื่อมต่อกับขาดิจิตอล 2
int inputPin2 = 3; // สวิทช์ความใกล้ชิดอินฟราเรดเชื่อมต่อกับขาดิจิตอล 3
int inputPin3 = 4; // สวิทช์ความใกล้ชิดอินฟราเรดเชื่อมต่อกับขาดิจิตอล 4

int val1 = 0; // ตัวแปรนี้จะอ่านค่าจากเซ็นเซอร์ 1
int val2 = 0; // ตัวแปรนี้จะอ่านค่าจากเซ็นเซอร์ 2
int val3 = 0; // ตัวแปรนี้จะอ่านค่าจากเซ็นเซอร์ 3

void setup() 
{
Serial.begin(6900);

pinMode(ledPin1, OUTPUT); // ให้ประกาศ LED เป็นเอาท์พุท
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);

pinMode(inputPin1, INPUT); // ประกาศเซนเซอร์อินฟราเรดเป็นอินพุท
pinMode(inputPin2, INPUT);
pinMode(inputPin3, INPUT);



}



void loop()
{
  
val1 = digitalRead(inputPin1); // อ่านค่าการป้อนข้อมูล
val2 = digitalRead(inputPin2);
val3 = digitalRead(inputPin3);



if (val1 == LOW&& val2 == LOW && val3 == LOW )  // ตรวจสอบว่าการป้อนข้อมูลที่อยู่ในระดับสูง
{  
      unsigned long startTime = 0; 
      unsigned long showTime = millis() - startTime ;
      
          if(showTime <= 5000){
                Serial.print("Finish!");
      

          }else if(showTime > 5000 &&showTime<=10000){ 


                digitalWrite(ledPin1, HIGH); 
                analogWrite(ledPin1,127);

                digitalWrite(ledPin2, HIGH);
                analogWrite(ledPin2,127);

                digitalWrite(ledPin3, HIGH);
                analogWrite(ledPin3,127);
//delay(3000);

          }else if(showTime > 10000 &&showTime<=15000){ 


                  digitalWrite(ledPin1, HIGH); 
                  analogWrite(ledPin1,191);

                  digitalWrite(ledPin2, HIGH);
                  analogWrite(ledPin2,191);

                  digitalWrite(ledPin3, HIGH);
                  analogWrite(ledPin3,191);
          
            

          }else if (showTime > 15000){ 


                  digitalWrite(ledPin1, HIGH);
                  analogWrite(ledPin1,255);

                  digitalWrite(ledPin2, HIGH);
                  analogWrite(ledPin2,255);

                  digitalWrite(ledPin3, HIGH);
                  analogWrite(ledPin3,255);
 
                      startTime = millis();

          }else if(val1 == HIGH&& val2 == LOW && val3 == LOW ){//ถ้าถั่วเขียวลดลงเหลือแค่เซ็นเซ็อร์ตัวที่ 2 ให้มอเตอร์ทำงานแค่ 75%
          
                  digitalWrite(ledPin1, HIGH);
                  analogWrite(ledPin1,191);

                  digitalWrite(ledPin2, HIGH);
                  analogWrite(ledPin2,191);

                  digitalWrite(ledPin3, HIGH);
                  analogWrite(ledPin3,255);
                  
          }else if(val1 == HIGH&& val2 == HIGH && val3 == LOW ){//ถ้าถั่วเขียวลดลงเหลือแค่เซ็นเซ็อร์ตัวที่ 1 ให้มอเตอร์ทำงานแค่ 50%
          
                  digitalWrite(ledPin1, HIGH);
                  analogWrite(ledPin1,127);

                  digitalWrite(ledPin2, HIGH);
                  analogWrite(ledPin2,127);

                  digitalWrite(ledPin3, HIGH);
                  analogWrite(ledPin3,255);
          }else if(val1 == HIGH&& val2 == HIGH && val3 == HIGH ){//ถ้าถั่วเขียวลดลงเซ็นเซ็อร์ตัไม่เห็นให้มอเตอร์หยุดทำงาน
    
                  digitalWrite(ledPin1, LOW);
                  analogWrite(ledPin1,0);

                  digitalWrite(ledPin2, LOW);
                  analogWrite(ledPin2,0);

                  digitalWrite(ledPin3, LOW);
                  analogWrite(ledPin3,0);
          }
   }

else if (val1 == HIGH&& val2 == LOW && val3 == LOW )  //ตรวจสอบการเทถั่วเขียวครั้งแรกเมื่อถั่ว้ขียวมีแค่เซ็นเซอร์ตัวที่ 2 ให้มอเตอร์เริ่มทำงานที่ 50% ไปถึง 75%
{
 
       unsigned long startTime = 0; 
       unsigned long showTime = millis() - startTime ;
       
          if(showTime <= 5000){
            
                Serial.print("Finish!");      

          }else if(showTime > 5000 && showTime <= 10000){ 


                digitalWrite(ledPin1, HIGH); 
                analogWrite(ledPin1,127);

                digitalWrite(ledPin2, HIGH);
                analogWrite(ledPin2,127);

                digitalWrite(ledPin3, HIGH);
                analogWrite(ledPin3,127);
//delay(3000);

          }else if (showTime > 15000){ 


                  digitalWrite(ledPin1, HIGH);
                  analogWrite(ledPin1,191);

                  digitalWrite(ledPin2, HIGH);
                  analogWrite(ledPin2,191);

                  digitalWrite(ledPin3, HIGH);
                  analogWrite(ledPin3,255);
 
                      startTime = millis();

          }else if(val1 == HIGH&& val2 == HIGH && val3 == LOW ){//ถ้าถั่วเขียวลดลงเหลือแค่เซ็นเซ็อร์ตัวที่ 1 ให้มอเตอร์ทำงานแค่ 50%
          
                  digitalWrite(ledPin1, HIGH);
                  analogWrite(ledPin1,127);

                  digitalWrite(ledPin2, HIGH);
                  analogWrite(ledPin2,127);

                  digitalWrite(ledPin3, HIGH);
                  analogWrite(ledPin3,255);
                  
          }else if(val1 == HIGH&& val2 == HIGH && val3 == HIGH ){//ถ้าถั่วเขียวลดลงเซ็นเซ็อร์ตัไม่เห็นให้มอเตอร์หยุดทำงาน
    
                  digitalWrite(ledPin1, LOW);
                  analogWrite(ledPin1,0);

                  digitalWrite(ledPin2, LOW);
                  analogWrite(ledPin2,0);

                  digitalWrite(ledPin3, LOW);
                  analogWrite(ledPin3,0);
          }
}

else if (val1 == HIGH&& val2 == HIGH && val3 == LOW )  //ตรวจสอบการเทถั่วเขียวครั้งแรกเมื่อถั่ว้ขียวมีแค่เซ็นเซอร์ตัวที่ 2 ให้มอเตอร์เริ่มทำงานที่ 50% ไปถึง 75%
{
unsigned long startTime = 0; 
       unsigned long showTime = millis() - startTime ;
       
          if(showTime <= 5000){
            
                Serial.print("Finish!");      

          }else if (showTime > 5000){ 


                digitalWrite(ledPin1, HIGH); 
                analogWrite(ledPin1,127);

                digitalWrite(ledPin2, HIGH);
                analogWrite(ledPin2,127);

                digitalWrite(ledPin3, HIGH);
                analogWrite(ledPin3,255);
                
                  startTime = millis();

          }else if(val1 == HIGH&& val2 == HIGH && val3 == HIGH ){//ถ้าถั่วเขียวลดลงเซ็นเซ็อร์ตัไม่เห็นให้มอเตอร์หยุดทำงาน
    
                  digitalWrite(ledPin1, LOW);
                  analogWrite(ledPin1,0);

                  digitalWrite(ledPin2, LOW);
                  analogWrite(ledPin2,0);

                  digitalWrite(ledPin3, LOW);
                  analogWrite(ledPin3,0);
          }
}
else
{
       unsigned long startTime1 = 0; 
       unsigned long showTime1 = millis() - startTime1 ;
       
          if(showTime1 <= 15000){
            
                Serial.print("Finish!");      

          }
  
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);

  
}
}


