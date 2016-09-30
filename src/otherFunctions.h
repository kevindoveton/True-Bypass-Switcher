#include "Arduino.h"
#include <SD.h>
#include <ctype.h>
//#include "readWritePreset.h"
#include "loops.h"

// Set Active Preset

String activePreset;

void relay1State(int);
void relay2State(int);
void relay3State(int);
void relay4State(int);
void relay5State(int);
void relay6State(int);
void relay7State(int);
void relay8State(int);
void relay9State(int);
void relay10State(int);

const int button1Pin = 2;
const int button2Pin = 3;
const int button3Pin = 4;
const int button4Pin = 5;
const int button5Pin = 6;
const int button6Pin = 7;
const int button7Pin = 8;
const int button8Pin = 9;
const int button9Pin = 10;
const int button10Pin = 11;
const int button11Pin = 12;
const int button12Pin = 47;

const int led1Pin = 14;
const int led2Pin = 15;
const int led3Pin = 16;
const int led4Pin = 17;
const int led5Pin = 18;
const int led6Pin = 19;
const int led7Pin = 20;
const int led8Pin = 21;
const int led9Pin = 22;
const int led10Pin = 23;
const int led11Pin = 24;
const int led12Pin = 25;
const int led13Pin = 26;
const int led14Pin = 27;
const int led15Pin = 28;
const int led16Pin = 29;
const int led17Pin = 30;
const int led18Pin = 31;
const int led19Pin = 32;
const int led20Pin = 33;
const int led21Pin = 34;
const int led22Pin = 35;

const int relay1Pin = 36;
const int relay2Pin = 37;
const int relay3Pin = 38;
const int relay4Pin = 39;
const int relay5Pin = 40;
const int relay6Pin = 41;
const int relay7Pin = 42;
const int relay8Pin = 43;
const int relay9Pin = 44;
const int relay10Pin = 45;
const int relay11Pin = 46;

const int tapTempoPin =  13;      // the number of the LED pin
int tapTempoPinState = LOW; 

int buttonOneState = 0;
int buttonTwoState = 0;
int buttonThreeState = 0;
int buttonFourState = 0;
int buttonFiveState = 0;
int buttonSixState = 0;
int buttonSevenState = 0;
int buttonEightState = 0;
int buttonNineState = 0;
int buttonTenState = 0;
int buttonElevenState = 0;
int buttonTwelveState = 0;

int initialTapTime = 0;
int lastTapSend = 0;
int tapTempoPresses = 0; // Number of times tap tempo has been pushed
long int tapTime1;
long int tapTime2;
long int tapTime3;
long int tapTime4;
long tapTime1Millis;
long tapTime2Millis;
long tapTime3Millis; 
long tapTime4Millis;
long int tapTime; // Tap Tempo Time
int tapSent = 0; // Declares whether Relay 11 has sent 4 taps
int relayTaps = 0;
int lastTap = 0;
int relayTapOn = 0;
unsigned long previousMillis = 0;

unsigned long int lastDebounceTime = 0;
int holdTime = 1000;
int button12LastReading = 0;
int hold = 0;

int editMode = 0;
int manualMode = 0;
long button12OnTime = 0;
long lastSwitchTime = 0;
long int time = millis();
int bounceTime = 50;
int button11LastReading = 0;
int activePresetLED = 0;
char tempChar = 0;

int button1LastReading = 0;
int button2LastReading = 0;
int button3LastReading = 0;
int button4LastReading = 0;
int button5LastReading = 0;
int button6LastReading = 0;
int button7LastReading = 0;
int button8LastReading = 0;
int button9LastReading = 0;
int button10LastReading = 0;
// SD CARD
int presetRead = 0;
File presetOneSD;

void setup ()
{
  Serial.begin(9600);
  // Pin Mode (Buttons)
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
  pinMode(button6Pin, INPUT);
  pinMode(button7Pin, INPUT);
  pinMode(button8Pin, INPUT);
  pinMode(button9Pin, INPUT);
  pinMode(button10Pin, INPUT);
  pinMode(button11Pin, INPUT);
  pinMode(button12Pin, INPUT);

  // Pin Mode (LEDs)
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
  pinMode(led4Pin, OUTPUT);
  pinMode(led5Pin, OUTPUT);
  pinMode(led6Pin, OUTPUT);
  pinMode(led7Pin, OUTPUT);
  pinMode(led8Pin, OUTPUT);
  pinMode(led9Pin, OUTPUT);
  pinMode(led10Pin, OUTPUT);
  pinMode(led11Pin, OUTPUT);
  pinMode(led12Pin, OUTPUT);
  pinMode(led13Pin, OUTPUT);
  pinMode(led14Pin, OUTPUT);
  pinMode(led15Pin, OUTPUT);
  pinMode(led16Pin, OUTPUT);
  pinMode(led17Pin, OUTPUT);
  pinMode(led18Pin, OUTPUT);
  pinMode(led19Pin, OUTPUT);
  pinMode(led20Pin, OUTPUT);
  pinMode(led21Pin, OUTPUT);
  pinMode(led22Pin, OUTPUT);

  // Pin Mode (Relays)
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);
  pinMode(relay5Pin, OUTPUT);
  pinMode(relay6Pin, OUTPUT);
  pinMode(relay7Pin, OUTPUT);
  pinMode(relay8Pin, OUTPUT);
  pinMode(relay9Pin, OUTPUT);
  pinMode(relay10Pin, OUTPUT);
  pinMode(relay11Pin, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(53, OUTPUT);

  if (!SD.begin(53)) {
    Serial.println("initialization failed!");
    return;
  }

  Serial.println("initialization done.");



}

//relay#States - Used to turn relays on and off.
void relay1State(int n)
{
  digitalWrite(relay1Pin, n);
  digitalWrite(led13Pin, n);
  Serial.println("relay1State "); 
  Serial.println(n); 
  delay(1);

}

void relay2State(int n)
{
  digitalWrite(relay2Pin, n);
  digitalWrite(led14Pin, n);
  Serial.println("relay2State "); 
  Serial.println(n); 
  delay(1);
}

void relay3State(int n)
{
  digitalWrite(relay3Pin, n);
  digitalWrite(led15Pin, n);
  Serial.println("relay3State "); 
  Serial.println(n); 
  delay(1);
}

void relay4State(int n)
{
  digitalWrite(relay4Pin, n);
  digitalWrite(led16Pin, n);
  Serial.println("relay4State "); 
  Serial.println(n); 
  delay(1);
}

void relay5State(int n)
{
  digitalWrite(relay5Pin, n);
  digitalWrite(led17Pin, n);
  Serial.println("relay5State "); 
  Serial.println(n); 
  delay(1);
}

void relay6State(int n)
{
  digitalWrite(relay6Pin, n);
  digitalWrite(led18Pin, n);
  Serial.println("relay6State "); 
  Serial.println(n); 
  delay(1);
}

void relay7State(int n)
{
  digitalWrite(relay7Pin, n);
  digitalWrite(led19Pin, n);
  Serial.println("relay7State "); 
  Serial.println(n); 
  delay(1);
}

void relay8State(int n)
{
  digitalWrite(relay8Pin, n);
  digitalWrite(led20Pin, n);
  Serial.println("relay8State "); 
  Serial.println(n); 
  delay(1);
}

void relay9State(int n)
{
  digitalWrite(relay9Pin, n);
  digitalWrite(led21Pin, n);
  Serial.println("relay9State "); 
  Serial.println(n); 
  delay(1);
}

void relay10State(int n)
{
  digitalWrite(relay10Pin, n);
  digitalWrite(led22Pin, n);
  Serial.println("relay10State "); 
  Serial.println(n); 
  delay(1);
}



// The On/Off Section :)
const String L1 = "L1,"; //Defining Loops
const String L2 = "L2,";
const String L3 = "L3,";
const String L4 = "L4,";
const String L5 = "L5,";
const String L6 = "L6,";
const String L7 = "L7,";
const String L8 = "L8,";
const String L9 = "L9,";
const String L10 = "L10,";

void Loop1 (String);
void Loop2 (String);
void Loop3 (String);
void Loop4 (String);
void Loop5 (String);
void Loop6 (String);
void Loop7 (String);
void Loop8 (String);
void Loop9 (String);
void Loop10 (String);
void readPreset (String);

void Loop1 (int n) // Loop 1 - N=Preset Name..
{
    relay1State(n);
}

void Loop2 (int n)
{
    relay2State(n);
}

void Loop3 (int n)
{
    relay3State(n);
}

void Loop4 (int n)
{
    relay4State(n);
}

void Loop5 (int n)
{
    relay5State(n);
}

void Loop6 (int n)
{
    relay6State(n);
}

void Loop7 (int n)
{
    relay7State(n);
}

void Loop8 (int n)
{
    relay8State(n);
}

void Loop9 (int n)
{
    relay9State(n);
}

void Loop10 (int n)
{
    relay10State(n);
}

void allLEDsOut() // turn off all preset LEDs
{
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);
  digitalWrite(led4Pin, LOW);
  digitalWrite(led5Pin, LOW);
  digitalWrite(led6Pin, LOW);
  digitalWrite(led7Pin, LOW);
  digitalWrite(led8Pin, LOW);
  digitalWrite(led9Pin, LOW);
  digitalWrite(led10Pin, LOW);
  Serial.println("allLEDsOut");
}

//Save Preset to String
/*void savePresetToString(String m, String n)
{
  if (m = "presetOne")
  {
    presetOne = "";

    for (int x = 1; x < 11; x++){
x = "led";
      if (digitalRead(tempString) == HIGH);{
        presetOne = presetOne + te;
      }
      else
      {
        presetOne = presetOne;
      }
    }
  }
}*/


/*void invertArray(String a, String b)
{
  if (a)
}*/


