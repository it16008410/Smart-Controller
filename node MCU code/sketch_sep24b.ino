#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <Wire.h>
#include <ESP8266HTTPClient.h>

const int sampleWindow = 50; 
unsigned int sample;

String apiKey = "QOG48EQUUBJ01KLW"; // Enter your Write API key from ThingSpeak
const char* ssid = "shanaka";
const char* password = "shanaka123";
const char* server = "api.thingspeak.com";

WiFiClient client;

ESP8266WebServer server(80);

const int led = 13;

int sensorPin = A0; // select the input pin for the potentiometer
int ledPin = D7; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  pinMode(led, OUTPUT);       // Initialize the Led_OnBoard pin as an output
  Serial.begin(115200);
  WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(100);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println(" ");

  Serial.print("Connecting");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(led, LOW);
    delay(250);
    Serial.print(".");
    digitalWrite(led, HIGH);
    delay(250);
  }
 digitalWrite(led, HIGH);
  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.println("Connected to Network/SSID");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
}

  //SETUP SOUND SENSOR 



void loop(void){
  sensorValue = analogRead (sensorPin);
  Serial.println (sensorValue);//, DEC);
  if (sensorValue > 80){
    digitalWrite (ledPin, HIGH);
    delay (1000);
    digitalWrite (ledPin, LOW);
  }
 
   unsigned long startMillis= millis();                   // Start of sample window
   float peakToPeak = 0;                                  // peak-to-peak level
 
   unsigned int signalMax = 0;                            //minimum value
   unsigned int signalMin = 1024;                         //maximum value
 
                                                          // collect data for 50 mS
   while (millis() - startMillis < sampleWindow)
  
      sample = analogRead(sensorPin);                    //get reading from microphone
      if (sample < 1024)                                  // toss out spurious readings
      {
         if (sample > signalMax)
         {
            signalMax = sample;                           // save just the max levels
         }
         else if (sample < signalMin)
         {
            signalMin = sample;                           // save just the min levels
         }
      }
   
 
   peakToPeak = signalMax - signalMin;                    // max - min = peak-peak amplitude
   int db = map(peakToPeak,20,900,49.5,90);             //calibrate for deciBels
 
       if (client.connect(server, 80)) // "184.106.153.149" or api.thingspeak.com
  {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(db);
    postStr += "r\n";
    
    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(sample);
    Serial.println(postStr);

   

   
  }
    client.stop();
  
}
