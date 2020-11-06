#include <IRLibSendBase.h>    //We need the base code
#include <IRLib_HashRaw.h>    //Only use raw sender
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is conntect to the Arduino digital pin 4
#define ONE_WIRE_BUS 4

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);

IRsendRaw mySender;

void setup() {
// Start serial communication for debugging purposes
  Serial.begin(9600);
  // Start up the library
  delay(2000); 
  while (!Serial); //delay for Leonardo
  Serial.println("Temperature Sensor\n\n");
  sensors.begin();
}
/* Cut and paste the output from "rawRecv.ino" below here. It will 
 * consist of a #define RAW_DATA_LEN statement and an array definition
 * beginning with "uint16_t rawData[RAW_DATA_LEN]= {…" and concludes
 * with "…,1000};"
 */
#define RAW_DATA_LEN 350
uint16_t rawDataOff[RAW_DATA_LEN]={
  42, 350, 86, 274, 126, 242, 34, 290, 
  118, 518, 30, 494, 58, 1806, 66, 1434, 
  98, 1626, 118, 686, 174, 422, 110, 930, 
  46, 1286, 94, 674, 66, 274, 74, 510, 
  42, 1550, 170, 1254, 98, 706, 34, 1658, 
  30, 770, 146, 594, 142, 1390, 38, 1674, 
  78, 2154, 34, 1546, 54, 670, 38, 122, 
  206, 594, 114, 1386, 150, 594, 154, 618, 
  38, 1466, 110, 130, 46, 542, 42, 702, 
  102, 246, 70, 534, 126, 594, 42, 762, 
  118, 618, 42, 754, 126, 686, 110, 674, 
  42, 278, 38, 490, 78, 650, 118, 1470, 
  94, 254, 26, 658, 130, 454, 34, 170, 
  134, 570, 150, 594, 178, 562, 42, 1046, 
  46, 462, 98, 1594, 150, 570, 98, 646, 
  158, 1398, 102, 1430, 102, 226, 66, 590, 
  158, 642, 38, 674, 82, 590, 34, 286, 
  30, 502, 174, 614, 106, 930, 130, 618, 
  42, 1542, 102, 466, 182, 118, 86, 402, 
  98, 226, 30, 442, 42, 194, 106, 594, 
  150, 566, 126, 622, 90, 254, 30, 1202, 
  422, 382, 150, 1382, 174, 1386, 102, 242, 
  46, 1406, 182, 1146, 98, 242, 46, 458, 
  110, 634, 38, 114, 142, 622, 142, 566, 
  186, 586, 130, 218, 34, 414, 74, 186, 
  54, 618, 98, 642, 50, 222, 30, 602, 
  210, 454, 158, 610, 138, 134, 70, 642, 
  134, 558, 210, 506, 154, 622, 94, 242, 
  86, 346, 126, 190, 82, 582, 182, 566, 
  310, 538, 154, 514, 94, 218, 82, 554, 
  186, 426, 78, 242, 50, 586, 158, 598, 
  146, 586, 130, 614, 134, 178, 86, 610, 
  210, 534, 82, 610, 106, 826, 158, 502, 
  82, 214, 46, 550, 230, 1322, 210, 486, 
  150, 1350, 138, 242, 34, 1154, 38, 158, 
  138, 622, 154, 1246, 74, 246, 98, 1142, 
  78, 218, 158, 530, 130, 506, 190, 174, 
  90, 1000};

#define RAW_DATA_LEN 350
uint16_t rawDataOn[RAW_DATA_LEN]={
 110, 174, 118, 182, 138, 174, 118, 126, 
  110, 182, 886, 122, 162, 182, 142, 1770, 
  166, 122, 110, 1186, 218, 122, 86, 1110, 
  50, 138, 178, 510, 210, 506, 186, 126, 
  110, 394, 86, 126, 110, 1342, 162, 530, 
  102, 178, 118, 374, 54, 170, 146, 1182, 
  190, 134, 106, 1130, 110, 126, 190, 502, 
  186, 1314, 322, 582, 210, 454, 106, 174, 
  94, 1126, 170, 122, 110, 1158, 82, 174, 
  198, 506, 262, 1130, 82, 174, 170, 1342, 
  218, 498, 190, 578, 162, 1286, 114, 122, 
  90, 602, 190, 502, 370, 1166, 262, 526, 
  378, 550, 110, 582, 406, 498, 182, 482, 
  154, 182, 90, 374, 38, 186, 142, 506, 
  242, 474, 190, 170, 66, 394, 86, 134, 
  158, 418, 162, 178, 90, 530, 190, 502, 
  186, 530, 186, 134, 102, 370, 50, 186, 
  166, 526, 190, 478, 78, 182, 190, 530, 
  162, 582, 190, 502, 126, 214, 82, 478, 
  218, 1338, 82, 610, 342, 458, 158, 174, 
  90, 1134, 110, 174, 90, 1322, 238, 470, 
  166, 578, 158, 178, 86, 370, 86, 130, 
  162, 502, 110, 166, 22, 394, 342, 450, 
  106, 210, 110, 530, 210, 526, 162, 1346, 
  158, 606, 134, 214, 82, 370, 266, 502, 
  110, 122, 166, 422, 106, 210, 110, 346, 
  42, 158, 142, 666, 158, 1262, 158, 562, 
  274, 1278, 106, 190, 134, 1130, 82, 210, 
  162, 1134, 318, 1346, 106, 558, 454, 446, 
  162, 530, 102, 186, 134, 550, 142, 502, 
  134, 186, 82, 538, 122, 554, 182, 590, 
  130, 218, 42, 406, 134, 182, 86, 394, 
  54, 210, 110, 582, 206, 514, 154, 558, 
  186, 190, 42, 482, 214, 530, 190, 554, 
  50, 214, 82, 510, 150, 590, 206, 586, 
  142, 122, 110, 590, 122, 618, 154, 610, 
  134, 590, 126, 666, 110, 210, 78, 394, 
  82, 182, 118, 470, 106, 614, 214, 122, 
  114, 502, 186, 478, 402, 526, 162, 474, 
  422, 534, 186, 1210, 134, 242, 42, 406, 
  78, 238, 86, 1234, 318, 1134, 178, 190, 
  82, 346, 210, 1398, 354, 1150, 454, 470, 
  130, 594, 154, 190, 38, 1000};



/*
 * Cut-and-paste into the area above.
 */
   
void loop() {
// Call sensors.requestTemperatures() to issue a global temperature and Requests to all devices on the bus
  sensors.requestTemperatures(); 
  
  int temp = sensors.getTempCByIndex(0);
  Serial.print("Celsius temperature: ");
  // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
  Serial.print(sensors.getTempCByIndex(0)); 
  Serial.println(" C");
  //Serial.print(" - Fahrenheit temperature: ");
 // Serial.println(sensors.getTempFByIndex(0));
  delay(1000);

  if (temp > 29) {
    mySender.send(rawDataOn,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    Serial.println(("AC Switched On"));
  }
  /*else if (temp > 28) {
    mySender.send(rawDataOnt,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    Serial.println(F("AC turbo On"));
  }
  else if (temp = 22) {
    mySender.send(rawDataOfft,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    Serial.println(F("AC turbo Off"));
  }*/
  else if (temp < 29) {
    mySender.send(rawDataOff,RAW_DATA_LEN,36);//Pass the buffer,length, optionally frequency
    Serial.println(("AC Switched Off"));
  }
  delay(5000);
}
