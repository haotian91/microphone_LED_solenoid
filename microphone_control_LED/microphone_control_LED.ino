//define 1
#define soloPin1 13
#define LEDPin1 5
const int analogInPin1 = A0;

int sensorValue1 = 0;
unsigned long previousMillis1 = 0;
int soundedge1= 700;
int brightness1 = 0;

//define 2
#define soloPin2 8
#define LEDPin2 3
const int analogInPin2 = A1;

int brightness2 = 0;
int sensorValue2 = 0;
unsigned long previousMillis2 = 0;
int soundedge2= 700;

//global
const long interval = 800; 
int soloTime = 20000;
int delayval = 0;

void setup(){  
  Serial.begin(9600);
  pinMode(LEDPin1,OUTPUT);
  pinMode(soloPin1,OUTPUT);
  analogWrite(LEDPin1,10);
  pinMode(LEDPin2,OUTPUT);
  pinMode(soloPin2,OUTPUT);
  analogWrite(LEDPin2,10);
}

void loop(){
  unsigned long currentMillis = millis();
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  Serial.print(sensorValue1);
  Serial.print(" , ");
  Serial.println(sensorValue2);  

//-----------------------------trigger 1--------------------------//
  if(currentMillis - previousMillis1 <= interval){
     if(sensorValue1 > soundedge1){
        previousMillis1 = currentMillis;
        if(brightness1 < 250){
          brightness1 +=10;
        }
      }
   // solenoid hit three times when the clock goes to 0,10,20,30,40,50 seconds     
   //      Serial.println(millis() % soloTime);     
      if((millis() % soloTime) < 100){        
          solonoid1();          
      }
      
   // LED strips turn on
      analogWrite(LEDPin1,brightness1);
  } 
  
  else{  
    if(sensorValue1 > soundedge1){
        previousMillis1 = currentMillis;
      }
      
    if(sensorValue1 <= soundedge1){
      if(brightness1 > 0){
          brightness1 -=10;
        }
    }
    
    analogWrite(LEDPin1,brightness1);  
  }
  
//-----------------------------trigger 2--------------------------//
  if(currentMillis - previousMillis2 <= interval){
     if(sensorValue2 > soundedge2){
        previousMillis2 = currentMillis;
        if(brightness2 < 250){
          brightness2 +=10;
        }
      }
   // solenoid hit three times when the clock goes to 0,10,20,30,40,50 seconds     
   //      Serial.println(millis() % soloTime);     
      if((millis() % soloTime) < 100){        
          solonoid2();          
      }
      
   // LED strips turn on
      analogWrite(LEDPin2,brightness2);
  } 
  
  else{  
    if(sensorValue2 > soundedge2){
        previousMillis2 = currentMillis;
      }
      
    if(sensorValue2 <= soundedge2){
      if(brightness2 > 0){
          brightness2 -=10;
        }
    }
    
    analogWrite(LEDPin2,brightness2);
    
  }
  
}

void solonoid1(){
  digitalWrite(soloPin1,HIGH);
  delay(90);
  digitalWrite(soloPin1,LOW);
  delay(100);
  digitalWrite(soloPin1,HIGH);
  delay(90);
  digitalWrite(soloPin1,LOW);
  delay(100);
  digitalWrite(soloPin1,HIGH);
  delay(90);
  digitalWrite(soloPin1,LOW);
  delay(100);
}

void solonoid2(){
  digitalWrite(soloPin2,HIGH);
  delay(90);
  digitalWrite(soloPin2,LOW);
  delay(100);
  digitalWrite(soloPin2,HIGH);
  delay(90);
  digitalWrite(soloPin2,LOW);
  delay(100);
  digitalWrite(soloPin2,HIGH);
  delay(90);
  digitalWrite(soloPin2,LOW);
  delay(100);
}
