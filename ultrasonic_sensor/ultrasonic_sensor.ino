int trigPin=10; //purple
int echoPin=11; //gray
long duration,inches,inches1,duration1;
 int sensor=A1;
//inches1 --> outdoor sensor
int trigPin1=6; //purple
int echoPin1=7; //gray
// door length in inches 
long door = 5;
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit 
float vout;  //temporary variable to hold sensor reading


 int PeopleCount;
 int Count;


void setup() {
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


}

void loop() {
  // ***************************************Ultrasonic 1******************************************
digitalWrite(trigPin1,HIGH);
delayMicroseconds(1000);
digitalWrite(trigPin1,LOW);
//read the signal from sensor
//duration is the time from sending
//ping the reception of its echo off of an object.
  duration1 = pulseIn(echoPin1,HIGH);
 //covert time in to distance
 inches1= (duration1 / 2) / 74;

Serial.print(duration);
 Serial.print(",");

     Serial.print(inches1);
     Serial.print("inches1");
     Serial.println();
     
  // trigerd by HIGH pulse of 10 or more ms :

// ***************************************Ultrasonic 1******************************************

// ***************************************Ultrasonic 2******************************************


digitalWrite(trigPin,HIGH);
delayMicroseconds(100);
digitalWrite(trigPin,LOW);
//read the signal from sensor
//duration is the time from sending
//ping the reception of its echo off of an object.
  duration = pulseIn(echoPin,HIGH);
 //covert time in to distance
 inches= (duration / 2) / 74;

 Serial.print(duration);
 Serial.print(",");

     Serial.print(inches);
     Serial.print("inches");
     Serial.println();

// ***************************************Ultrasonic 2******************************************
//set door length
if (inches1 < door ){
  Count=Count+1;
  

delay(500);}

else if (inches <door ){
  Count=Count-1;}
Serial.println(Count);Serial.println("Count");
delay(500);

 

/*********** Temperature input**********/
vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
tempf=(vout*1.8)+32; // Converting to Fahrenheit 
Serial.print("in DegreeC=");
Serial.print("\t");
Serial.print(tempc);
Serial.println();
Serial.print("in Fahrenheit=");
Serial.print("\t");
Serial.print(tempf);
Serial.println();
delay(1000); //Delay of 1 second for ease of viewing 




  
  }
