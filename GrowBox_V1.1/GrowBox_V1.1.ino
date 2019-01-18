#include <EEPROM.h>
//#include <SimpleDHT.h>
#include <SoftwareSerial.h>
#include "dht.h"
#include "Wire.h"
#include "I2Cdev.h"
#include "DS1307.h"

#define MOISURE  A0
#define TEMPRELAY  13
#define HUMRELAY  12
#define RTCRELAY  9
#define MOISURERELAY  4
#define pinDHT11  A1

SoftwareSerial hc06(10, 11); // Rx >> 11  :: Tx >> 10

dht DHT;
DS1307 rtc;
uint8_t month, day, dow, hours, minutes, seconds;
uint16_t year;


//virtuabotixRTC myRTC(6, 7, 8); //
String hc06Data;
byte bsCounter = 0;
char VegetationData[40];
char FloweringData[40];
char hc06CharData[40];
int tempMin,tempMax,humMin,humMax,lightOn,lightOff,duration;
  
char cHour[3],cMinute[3],cSecond[3],cTemp[3],cHum[3],cMoisure[3];
String strMinute, strHour, strSecond, strTemp, strHum,strMoisure;


int moisureData;

byte temperature = 0;
byte humidity = 0;
//int err = SimpleDHTErrSuccess;
String boxStatus;

//SimpleDHT11 dht11(pinDHT11);

void setup()
{
  
  Wire.begin();
  rtc.initialize();
  Serial.begin(9600);
  hc06.begin(9600);
  pinMode(MOISURE, INPUT);
  pinMode(TEMPRELAY, OUTPUT);
  pinMode(HUMRELAY, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(MOISURERELAY, OUTPUT);
  pinMode(RTCRELAY, OUTPUT);
  //rtc.setDateTime24(2019, 1, 17, 22, 18, 0); // rtc 1307
  //myRTC.setDS1302Time(18, 49, 18, 7, 12, 21, 2018); //rtc 1302 drois gasworebistvis
}

void loop()
{
  DHT.read11(pinDHT11);
  //myRTC.updateTime();
  rtc.getDateTime24(&year, &month, &day, &hours, &minutes, &seconds);
  
  moisureData = analogRead(MOISURE);
  moisureData = map(moisureData,550,0,0,100);
  while(hc06.available())
  {
      hc06Data = hc06.readString();  
//      Serial.print("Bluetooth Data: ");
//      Serial.println(hc06Data);
      checkData(hc06Data);    
  }
  relaySwitch();  

  //delay(1000);
}


void printSomeData()
{
  Serial.print("bluetooth data: ");
  Serial.print(hc06Data);
  Serial.println();
  Serial.print(hours);
  Serial.print(":");
  Serial.print(minutes);
  Serial.print(":");
  Serial.println(seconds);  
  //sendDHT11DataToBluetooth();
}


void setupBox()
{



  
}

void autoOff()
{


  
}


void autoOn()
{


  
}


void manualOff()
{



  
}


void manualOn()
{





  
}
