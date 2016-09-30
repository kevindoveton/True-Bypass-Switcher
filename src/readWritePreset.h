/*
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 */

#include <SD.h>
#include "loops.h"
File myFile;
// `int exINT = 12;
// float exFloat = 3.14159265358979323846264338327950288419716939;
// boolean exBoolean = false;

void applySetting(String, String);
{
}
//void setup()
//{
// Open serial communications and wait for port to open:
//Serial.begin(9600);
//while (!Serial) {
//; // wait for serial port to connect. Needed for Leonardo only
//}


String tempString; 

//}

void readSDSettings()
{
  char character;
  String settingName;
  String settingValue;
  myFile = SD.open("settings.txt");
  if (myFile) {
    while (myFile.available()) {
      character = myFile.read();
      while(character != '='){
        settingName = settingName + character;
        character = myFile.read();
      }
      character = myFile.read();
      while(character != '\n'){
        settingValue = settingValue + character;
        character = myFile.read();
        if(character == '\n'){

          //Debuuging Printing
          Serial.print("Name:");
          Serial.println(settingName);
          Serial.print("Value :");
          Serial.println(settingValue);

          // Apply the value to the parameter
          applySetting(settingName,settingValue);
          // Reset Strings
          settingName = "";
          settingValue = "";
        }
      }
    }
    // close the file:
    myFile.close();
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening settings.txt");
  }
}
/* Apply the value to the parameter by searching for the parameter name
 Using String.toInt(); for Integers
 toFloat(string); for Float
 toBoolean(string); for Boolean
 */

/*void applySetting(String settingName, String settingValue) {
 
 if (settingName == "presetOne");
 {
 presetOne = settingValue;
 }
 
 if (settingName == "presetTwo");
 {
 presetTwo = settingValue;
 }
 
 if (settingName == "presetThree");
 {
 presetThree = settingValue;
 }
 
 if (settingName == "presetFour");
 {
 presetFour = settingValue;
 }
 
 if (settingName == "presetFive");
 {
 presetFive = settingValue;
 }
 
 if (settingName == "presetSix");
 {
 presetSix = settingValue;
 }
 
 if (settingName == "presetSeven");
 {
 presetSeven = settingValue;
 }
 
 if (settingName == "presetEight");
 {
 presetEight = settingValue;
 }
 
 if (settingName == "presetNine");
 {
 presetNine = settingValue;
 }
 
 if (settingName == "presetTen");
 {
 presetTen = settingValue;
 }
 
 if (settingName == "p1tt");
 {
 p1tt = settingValue.toInt();
 }
 
 if (settingName == "p2tt");
 {
 p2tt = settingValue.toInt();
 }
 
 if (settingName == "p3tt");
 {
 p3tt = settingValue.toInt();
 }
 
 if (settingName == "p4tt");
 {
 p4tt = settingValue.toInt();
 }
 
 if (settingName == "p5tt");
 {
 p5tt = settingValue.toInt();
 }
 
 if (settingName == "p6tt");
 {
 p6tt = settingValue.toInt();
 }
 
 if (settingName == "p7tt");
 {
 p7tt = settingValue.toInt();
 }
 
 if (settingName == "p8tt");
 {
 p8tt = settingValue.toInt();
 }
 
 if (settingName == "p9tt");
 {
 p9tt = settingValue.toInt();
 }
 
 if (settingName == "p10tt");
 {
 p10tt = settingValue.toInt();
 }
 */

/*if(settingName == "exINT") {
 exINT=settingValue.toInt();
 }
 if(settingName == "exFloat") {
 exFloat=toFloat(settingValue);
 }
 if(settingName == "exBoolean") {
 exBoolean=toBoolean(settingValue);
 }*/

//}
/*
// converting string to Float
 float toFloat(String settingValue){
 char floatbuf[settingValue.length()];
 settingValue.toCharArray(floatbuf, sizeof(floatbuf));
 float f = atof(floatbuf);
 return f;
 }
 // Converting String to integer and then to boolean
 // 1 = true
 // 0 = false
 boolean toBoolean(String settingValue) {
 if(settingValue.toInt()==1){
 return true;
 } 
 else {
 return false;
 }
 }*/



// Writes A Configuration file
/*
void writeSDSettings() 
 {
 // Delete the old settings.txt
 SD.remove("settings.txt");
 
 // Create new one
 myFile = SD.open("settings.txt", FILE_WRITE);
 
 // writing in the file works just like regular print()/println() function
 myFile.print("presetOne=");
 myFile.println(presetOne);
 myFile.print("p1tt=");
 myFile.println(p1tt);
 
 myFile.print("presetTwo=");
 myFile.println(presetTwo);
 myFile.print("p2tt=");
 myFile.println(p2tt);
 
 myFile.print("presetThree=");
 myFile.println(presetThree);
 myFile.print("p3tt=");
 myFile.println(p3tt);
 
 myFile.print("presetFour=");
 myFile.println(presetFour);
 myFile.print("p4tt=");
 myFile.println(p4tt);
 
 myFile.print("presetFive=");
 myFile.println(presetFive);
 myFile.print("p5tt=");
 myFile.println(p5tt);
 
 myFile.print("presetSix=");
 myFile.println(presetSix);
 myFile.print("p6tt=");
 myFile.println(p6tt);
 
 myFile.print("presetSeven=");
 myFile.println(presetSeven);
 myFile.print("p7tt=");
 myFile.println(p7tt);
 
 myFile.print("presetEight=");
 myFile.println(presetEight);
 myFile.print("p8tt=");
 myFile.println(p8tt);
 
 myFile.print("presetNine=");
 myFile.println(presetNine);
 myFile.print("p9tt=");
 myFile.println(p9tt);
 
 myFile.print("presetTen=");
 myFile.println(presetTen);
 myFile.print("p10tt=");
 myFile.println(p10tt);
 // close the file:
 myFile.close();
 //Serial.println("Writing done.");
 
 }
 */




