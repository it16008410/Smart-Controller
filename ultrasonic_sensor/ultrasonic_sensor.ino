#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Data wire is conntect to the Arduino digital pin 4
#define ONE_WIRE_BUS 4

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

// set the LCD address to 0x20(Cooperate with 3 short circuit caps) for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);  

int trigPin=10; //purple
int echoPin=11; //gray
long duration,cm2,cm1,duration1;
 int sensor=A1;
//inches1 --> outdoor sensor
int trigPin1=6; //purple
int echoPin1=7; //gray
// door length in inches 
long door = 30;
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading
const int buzzer = 9;

 int PeopleCount;   
 int Count;


void setup() {
//buzzer
pinMode(buzzer, OUTPUT);
// pir inputs
  pinMode(4,INPUT);
  pinMode(12,OUTPUT);
   pinMode(5,INPUT);
  pinMode(13,OUTPUT);

// serial port begin
Serial.begin(9600);
//Define inputs and outputs
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(trigPin1,OUTPUT);
pinMode(echoPin1,INPUT);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin1,LOW);
  delayMicroseconds(5);

  // Start serial communication for debugging purposes
  Serial.begin(9600);
  // Start up the library
  sensors.begin();

 // initialize the lcd 
  lcd.init();                      
  lcd.backlight();
  

}


void loop() {
  
// ******************************************Ultrasonic 1******************************************
digitalWrite(trigPin1,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1,LOW);
//read the signal from sensor
//duration is the time from sending
//ping the reception of its echo off of an object.
  duration1 = pulseIn(echoPin1,HIGH);
 //covert time in to distance
 cm1= (duration1 / 2) /29 ;

//Serial.print(duration);
// Serial.print(",");
     
     Serial.print("sensor A- ");
     Serial.print(cm1);
     Serial.print("cm");
     Serial.println();
     
  // trigerd by HIGH pulse of 10 or more ms :
  

// ***************************************Ultrasonic 2******************************************


digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
//read the signal from sensor
//duration is the time from sending
//ping the reception of its echo off of an object.
  duration = pulseIn(echoPin,HIGH);
 //covert time in to distance
 cm2= (duration / 2) / 29;

 //Serial.print(duration);
// Serial.print(",");

     Serial.print("sensor B- ");
     Serial.print(cm2);
     Serial.print("cm");
     Serial.println();

// ***************************************Ultrasonic 2*************************************************************
//set door length
if (cm1 < door ){
  Count = Count+1;
  Serial.println(Count);
  Serial.println("Count");
  delay(100);}

else if (cm2 <door ){
  Count = Count-1;}
  Serial.println(Count);
  Serial.println("Count");
  delay(100);

//******************************************LCD Displaying**********************************************************
  
  lcd.home();
  
  lcd.setCursor(0, 0);
  lcd.print("Students = ");
  lcd.print(Count);
  lcd.setCursor(0, 1);
  lcd.print(50-Count);
  lcd.print(" Can Go Inside");

//*************************************buzzer***********************************************************************
  if (cm2 <door ){
  tone(buzzer, 10000); // Send 1KHz sound signal...
  delay(100);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(10);        // ...for 1sec
  }
    else if (cm1 <door ){
  tone(buzzer, 10000); // Send 1KHz sound signal...
  delay(100);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(10);        // ...for 1sec
  }
  
//********************************* Temperature input****************************************************************
 
  // Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  
  Serial.print("Celsius temperature: ");
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  Serial.println(sensors.getTempCByIndex(0)); 
  //Serial.print(" - Fahrenheit temperature: ");
  //Serial.println(sensors.getTempFByIndex(0));
  delay(10);
 
int value1 = digitalRead(4);
int value2 = digitalRead(5);
if (value1 == 1){
    digitalWrite(12,HIGH);
  delay(50);
  digitalWrite(12,LOW);
  delay(100);
}
 
else if(value2 == 1){
  digitalWrite(13,HIGH);
  delay(50);
 digitalWrite(13,LOW);
 delay(100);
}
 
  
  }
