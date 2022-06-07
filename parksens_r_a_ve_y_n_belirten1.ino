#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int echoPin1=7;
int trigPin1=8;

long duration1=0;
float distance1=0.0;

int echoPin2=1;
int trigPin2=0;

long duration2=0;
float distance2=0.0;

int buzzer=6;
int buzzer2=10;

float carp ;
float bol ;
float aci;
double derece;

void setup() {
  lcd.begin(16, 2);
  pinMode(echoPin1,INPUT);
  pinMode(trigPin1,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(buzzer2,OUTPUT);
  pinMode(echoPin2,INPUT);
  pinMode(trigPin2,OUTPUT);
  
  
  
}

void loop() {
  sensor1();
  sensor2();
  kosinus();
  yon();

}

void sensor1(){
  digitalWrite(trigPin1,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1,LOW);
  
  duration1=pulseIn(echoPin1,HIGH);
  distance1=(duration1*0.034/2);
  
  if(distance1 < 20){
  
    tone(buzzer2, 500);
    digitalWrite(buzzer2, HIGH);
     delay(50);
    digitalWrite(buzzer2, LOW);

  }else{
    
    noTone(buzzer2);
  }
  
 
}
 
void sensor2(){
  digitalWrite(trigPin2,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2,LOW);
  
  duration2=pulseIn(echoPin2,HIGH);
  distance2=(duration2*0.034/2);
  
  if(distance2 < 20){
  
    tone(buzzer, 500);
    digitalWrite(buzzer, HIGH);
     delay(50);
    digitalWrite(buzzer, LOW);

  }else{
    
    noTone(buzzer);
  }
  
 
}

void kosinus(){

  carp = ( distance1 * distance1) + (distance2 * distance2) - (100 * 100);
  bol = 2 * (distance1 * distance2);
  aci = carp / bol;

    float aci_sonuc = aci * 180 / M_PI;
    
    float derece = abs(aci_sonuc);
   
  		
    	lcd.setCursor(0, 1); 
        lcd.print("ACI :");
        lcd.print(derece);
        lcd.print("°");
       delay(1000);
}

void yon(){

 
  
  if(distance1 > distance2){
  			
    	lcd.clear();
        lcd.setCursor(0, 0); 
        lcd.print("saga don");
  }
  if(distance2 > distance1){
  		
    	lcd.clear();
        lcd.setCursor(0, 0); 
        lcd.print("sola don");
  }
 
  delay(1000);
}