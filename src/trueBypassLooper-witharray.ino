

#include "Arduino.h"
#include <SD.h>
//#include "readWritePreset.h"
#include "otherFunctions.h"


void loop()
{


  // Read State of Preset buttons - ie. whether they've been pushed
  int buttonOneState = digitalRead(button1Pin);
  int buttonTwoState = digitalRead(button2Pin);
  int buttonThreeState = digitalRead(button3Pin);
  int buttonFourState = digitalRead(button4Pin);
  int buttonFiveState = digitalRead(button5Pin);
  int buttonSixState = digitalRead(button6Pin);
  int buttonSevenState = digitalRead(button7Pin);
  int buttonEightState = digitalRead(button8Pin);
  int buttonNineState = digitalRead(button9Pin);
  int buttonTenState = digitalRead(button10Pin);
  int buttonElevenState = digitalRead(button11Pin);
  int buttonTwelveState = digitalRead(button12Pin);

  if (presetRead == 0)
  {
    readSDSettings();
    presetRead = 1;
  }
  // PRESET BUTTONS  
  // If a preset button has been pushed turn on/off corresponding loops, then all Preset LEDs turn on, the active preset LED then turns on. Tap Time is converted from BPM to ms and then sent.

  // PRESET ONE
  if (buttonOneState == HIGH && button1LastReading == LOW && manualMode == 0)
  {
    button1LastReading == HIGH; // Prevent a retrigger.
    relay1State(presetOne[1]); // Check if preset contains loop and then turns on or off
    relay2State(presetOne[2]);
    relay3State(presetOne[3]);
    relay4State(presetOne[4]);
    relay5State(presetOne[5]);
    relay6State(presetOne[6]);
    relay7State(presetOne[7]);
    relay8State(presetOne[8]);
    relay9State(presetOne[9]);
    relay10State(presetOne[10]);
    allLEDsOut(); // Turn off all preset LEDs
    digitalWrite(led1Pin, HIGH); // Turn on LED corresponding to preset
    activePreset = "presetOne"; // Define which preset is active, for edit mode/saving
    activePresetLED = led1Pin; // Define which preset is on, this is flashed in edit mode
    Serial.println(activePreset); // Print the active preset to confirm.
    tapTime = 60000 / presetOne[0]; // Convert tapTime from BPM to ms
    tapSent = 0; // Set tapSent to 0 so that the relay is triggered
  }

  // PRESET TWO
  if (buttonTwoState == HIGH && button2LastReading == LOW && manualMode == 0)
  {
    relay1State(presetTwo[1]);
    relay2State(presetTwo[2]);
    relay3State(presetTwo[3]);
    relay4State(presetTwo[4]);
    relay5State(presetTwo[5]);
    relay6State(presetTwo[6]);
    relay7State(presetTwo[7]);
    relay8State(presetTwo[8]);
    relay9State(presetTwo[9]);
    relay10State(presetTwo[10]);
    allLEDsOut();
    digitalWrite(led2Pin, HIGH);
    activePreset = "presetTwo";
    activePresetLED = led2Pin;
    Serial.println(activePreset);
    tapTime = 60000 / presetTwo[0];
    tapSent = 0;
    button2LastReading == HIGH;
  }

  // PRESET THREE    
  if (buttonThreeState == HIGH && button3LastReading == LOW && manualMode == 0)
  {
    relay1State(presetThree[1]);
    relay2State(presetThree[2]);
    relay3State(presetThree[3]);
    relay4State(presetThree[4]);
    relay5State(presetThree[5]);
    relay6State(presetThree[6]);
    relay7State(presetThree[7]);
    relay8State(presetThree[8]);
    relay9State(presetThree[9]);
    relay10State(presetThree[10]);

    allLEDsOut();
    digitalWrite(led3Pin, HIGH);
    activePreset = "presetThree";
    activePresetLED = led3Pin;
    Serial.println(activePreset);
    tapTime = 60000 / presetThree[0];
    tapSent = 0;
    button3LastReading == HIGH;
  }

  // PRESET FOUR
  if (buttonFourState == HIGH && button4LastReading == LOW && manualMode == 0)
  {
    relay1State(presetFour[1]);
    relay2State(presetFour[2]);
    relay3State(presetFour[3]);
    relay4State(presetFour[4]);
    relay5State(presetFour[5]);
    relay6State(presetFour[6]);
    relay7State(presetFour[7]);
    relay8State(presetFour[8]);
    relay9State(presetFour[9]);
    relay10State(presetFour[10]);
    allLEDsOut();
    digitalWrite(led4Pin, HIGH);
    activePreset = "presetFour";
    activePresetLED = led4Pin;
    Serial.println(activePreset);
    tapTime = 60000 / presetFour[0];
    tapSent = 0;
    button4LastReading == HIGH;
  }

  // PRESET FIVE    
  if (buttonFiveState == HIGH && button5LastReading == LOW && manualMode == 0)
  {
    relay1State(presetFive[1]);
    relay2State(presetFive[2]);
    relay3State(presetFive[3]);
    relay4State(presetFive[4]);
    relay5State(presetFive[5]);
    relay6State(presetFive[6]);
    relay7State(presetFive[7]);
    relay8State(presetFive[8]);
    relay9State(presetFive[9]);
    relay10State(presetFive[10]);
    allLEDsOut();
    digitalWrite(led5Pin, HIGH);
    activePreset = "presetFive";
    activePresetLED = led5Pin;
    Serial.println(activePreset);
    tapTime = 60000 / presetFive[0];
    tapSent = 0;
    button5LastReading == HIGH;
  }

  // PRESET SIX
  if (buttonSixState == HIGH && button6LastReading == LOW && manualMode == 0)
  {
    relay1State(presetSix[1]);
    relay2State(presetSix[2]);
    relay3State(presetSix[3]);
    relay4State(presetSix[4]);
    relay5State(presetSix[5]);
    relay6State(presetSix[6]);
    relay7State(presetSix[7]);
    relay8State(presetSix[8]);
    relay9State(presetSix[9]);
    relay10State(presetSix[10]);
    allLEDsOut();
    digitalWrite(led6Pin, HIGH);
    activePreset = "presetSix";
    activePresetLED = led6Pin;
    Serial.println(activePreset);
    tapTime = 60000 / presetSix[0];
    tapSent = 0;
    button6LastReading == HIGH;
  }

  // PRESET SEVEN
  if (buttonSevenState == HIGH && button7LastReading == LOW && manualMode == 0)
  {
    relay1State(presetSeven[1]);
    relay2State(presetSeven[2]);
    relay3State(presetSeven[3]);
    relay4State(presetSeven[4]);
    relay5State(presetSeven[5]);
    relay6State(presetSeven[6]);
    relay7State(presetSeven[7]);
    relay8State(presetSeven[8]);
    relay9State(presetSeven[9]);
    relay10State(presetSeven[10]);
    allLEDsOut();
    digitalWrite(led7Pin, HIGH);
    activePreset = "presetSeven";
    activePresetLED = led7Pin;
    Serial.println(activePreset);
    tapTime = 60000 / presetSeven[0];
    tapSent = 0;
    button7LastReading == HIGH;
  }

  // PRESET EIGHT
  if (buttonEightState == HIGH && button8LastReading == LOW && manualMode == 0)
  {
    relay1State(presetEight[1]);
    relay2State(presetEight[2]);
    relay3State(presetEight[3]);
    relay4State(presetEight[4]);
    relay5State(presetEight[5]);
    relay6State(presetEight[6]);
    relay7State(presetEight[7]);
    relay8State(presetEight[8]);
    relay9State(presetEight[9]);
    relay10State(presetEight[10]);
    allLEDsOut();
    digitalWrite(led8Pin, HIGH);
    activePreset = "presetEight";
    activePresetLED = led8Pin;
    Serial.println(activePreset);
    tapTime = 60000 / presetEight[0];
    tapSent = 0;
    button8LastReading == HIGH;
  }

  // PRESET NINE
  if (buttonNineState == HIGH && button9LastReading == LOW && manualMode == 0)
  {
    relay1State(presetNine[1]);
    relay2State(presetNine[2]);
    relay3State(presetNine[3]);
    relay4State(presetNine[4]);
    relay5State(presetNine[5]);
    relay6State(presetNine[6]);
    relay7State(presetNine[7]);
    relay8State(presetNine[8]);
    relay9State(presetNine[9]);
    relay10State(presetNine[10]);
    allLEDsOut();
    digitalWrite(led9Pin, HIGH);
    activePreset = "presetNine";
    activePresetLED = led9Pin;
    Serial.println(activePreset);
    tapTime = 60000 / presetNine[0];
    tapSent = 0;
    button9LastReading == HIGH;
  }

  // PRESET TEN
  if (buttonTenState == HIGH && button10LastReading == LOW && manualMode == 0)
  {
    relay1State(presetTen[1]);
    relay2State(presetTen[2]);
    relay3State(presetTen[3]);
    relay4State(presetTen[4]);
    relay5State(presetTen[5]);
    relay6State(presetTen[6]);
    relay7State(presetTen[7]);
    relay8State(presetTen[8]);
    relay9State(presetTen[9]);
    relay10State(presetTen[10]);
    allLEDsOut();
    digitalWrite(led10Pin, HIGH);
    activePreset = "presetTen";
    activePresetLED = led10Pin;
    Serial.println(activePreset);
    tapTime = 60000 / presetTen[0];
    tapSent = 0;
    button10LastReading == HIGH;
  }

  // Blinker
  // Flash LED 13 (tapTempoLED) on for 50ms and then off for the tapTime.
  unsigned long currentMillis = millis();
  if (tapTempoPinState == HIGH && (currentMillis - previousMillis) >= 50)
  {
    tapTempoPinState = LOW; 
    digitalWrite(tapTempoPin, tapTempoPinState); // Turn LED off
  }

  if (tapTempoPinState == LOW && (currentMillis - previousMillis) >= tapTime) 
  {
    previousMillis = millis();
    tapTempoPinState = HIGH;
    digitalWrite(tapTempoPin, tapTempoPinState); //Turn LED on
  }

  // Flash activePresetLED and LED 12 on for 50ms and then off for 150ms.
  if (digitalRead(activePresetLED) == HIGH && (currentMillis - previousMillis) >= 50 && editMode == 1)
  {
    digitalWrite(activePresetLED, LOW); // Turn LED off
  }

  if (digitalRead(activePresetLED) == LOW && (currentMillis - previousMillis) >= 150 && editMode == 1) 
  {
    previousMillis = millis();
    digitalWrite(activePresetLED, HIGH); //Turn LED on
  }

  // Tap Tempo Stuff 

  if ((millis() - lastTap) > 2000) 
  {
    tapTempoPresses = 0;
  }

  if (buttonElevenState == HIGH && button11LastReading == LOW)
  {

    if (tapTempoPresses == 0)// reset tap count
    {
      initialTapTime=millis(); // Reset clock
      tapTime = 0;
      tapTime1 = 0;
      tapTime1Millis = millis();
      tapTempoPresses = 1; // Number of times button 11 has been pushed
      Serial.print("TAP #1 - Time= ");
      Serial.println(tapTime);
      Serial.print("Tap #1 - Presses= ");
      Serial.println(tapTempoPresses);
      button11LastReading = HIGH;
      lastTap = millis();
    }

    if (tapTempoPresses == 1 && button11LastReading == LOW && ((millis() - lastTap) > 100)) 
    {
      tapTime2 = millis() - tapTime1Millis;
      tapTime2Millis = millis();
      tapTime = (tapTime + tapTime2);
      tapTempoPresses = 2;
      tapSent = 0;
      Serial.print("TAP #2 - Time= ");
      Serial.print(tapTime);
      Serial.println("Tap #2 - Presses= ");
      Serial.println(tapTempoPresses);
      button11LastReading = HIGH;
      lastTap = millis();
    }

    if (tapTempoPresses == 2 && button11LastReading == LOW && ((millis() - lastTap) > 100))
    {
      tapTime3 = millis() - tapTime2Millis;
      tapTime = ((tapTime + tapTime3) / 2);
      tapTime3Millis = millis();
      tapTempoPresses = 3;
      tapSent = 0;
      Serial.print("TAP #3 - Time= ");
      Serial.print(tapTime);
      Serial.println("Tap #3 - Presses= ");
      Serial.println(tapTempoPresses);
      button11LastReading = HIGH; 
      lastTap = millis(); 
    }

    if (tapTempoPresses == 3 && button11LastReading == LOW && ((millis() - lastTap) > 100))
    {
      tapTime4 = millis() - tapTime3Millis;
      tapTime = ((tapTime + tapTime4) / 3);
      tapTime4Millis = millis();
      tapTempoPresses = 4;
      tapSent = 0;
      Serial.print("TAP #4 - Time= ");
      Serial.print(tapTime);
      Serial.println("Tap #4 - Presses= ");
      Serial.println(tapTempoPresses);
      button11LastReading = HIGH;
      lastTap = millis();
    }

    if (tapTempoPresses > 3 && button11LastReading == LOW && ((millis() - lastTap) > 100))
    {
      tapTime1 = tapTime2; // Move all taps up one and then make tapTime4 the new time
      tapTime1Millis = tapTime2Millis;
      tapTime2 = tapTime3;
      tapTime2Millis = tapTime3Millis;
      tapTime3 = tapTime4;
      tapTime3Millis = tapTime4Millis;
      tapTime4 = millis() - tapTime3Millis;
      tapTime4Millis = millis();
      tapTime = ((tapTime1 + tapTime2 + tapTime3 + tapTime4) / 4);
      tapTempoPresses = tapTempoPresses + 1;
      tapSent = 0;
      Serial.println(tapTime); 
      Serial.println(tapTempoPresses);
      button11LastReading = HIGH;
      lastTap = millis();
    }
  }

  button11LastReading = buttonElevenState; // I dont know if I need this.. can probably delete it.

  if (((millis() - lastTap) > (tapTime + 500)) && tapSent == 0 && tapTime > 100)
  {
    tapTempoPresses = 0;
    Serial.println(relayTaps);
    Serial.println(60000 / tapTime);

    if (relayTaps < 5)
    {
      if (millis() >= (lastTapSend + (tapTime - 150)) && relayTapOn == 0)
      {

        Serial.print("Relay Tap HIGH "); 
        Serial.println(relayTaps);
        digitalWrite(relay11Pin, HIGH);
        lastTapSend = millis();
        relayTapOn = 1;
      }

      if (millis() >= (lastTapSend + 100) && relayTapOn != 0)
      {
        digitalWrite(relay11Pin, LOW);
        Serial.print("Relay Tap LOW "); 
        Serial.println(relayTaps);
        relayTaps = relayTaps + 1;
        lastTapSend = millis();
        relayTapOn = 0;
      }
    }

    if (relayTaps > 4)
    {

      tapSent = 1;
      relayTaps = 0;
      relayTapOn = 0;
    }
  }

  if (((millis() - lastTap) > (tapTime * 5)) && relayTaps < 3 && tapSent == 0)
  { 
    tapSent = 1;
    relayTaps = 0;
    relayTapOn = 0; 
  }


  // Preset Button Hold
  //First Press
  if (buttonTwelveState == HIGH && button12LastReading == LOW)
    button12OnTime = millis();

  if ((millis() - button12OnTime) > holdTime && editMode == 0 && buttonTwelveState == HIGH && button12LastReading == HIGH)
  {
    button12LastReading == HIGH;
    editMode = 1;
    manualMode = 1;
    Serial.println ("This is a Hold.. Going into edit Mode");

  }

  if (buttonTwelveState == LOW && button12LastReading == HIGH && editMode !=1 && manualMode == 1 && millis() > bounceTime)
  {
    // This is a single push
    button12LastReading == LOW;
    Serial.println("Exiting manual mode");
    digitalWrite(led12Pin, LOW);
    bounceTime = millis() + 50;
    manualMode = 0;
  }

  if (buttonTwelveState == LOW && button12LastReading == HIGH && editMode !=1 && manualMode == 0 && millis() > bounceTime)
  {
    // This is a single push
    button12LastReading == LOW;
    Serial.println("This is a single push, going into manual mode");
    manualMode = 1;
    digitalWrite(led12Pin, HIGH);
    bounceTime = millis() + 50;
  }

  // Exiting Edit Mode
  if (buttonTwelveState == HIGH && button12LastReading == LOW && editMode == 1 && millis() > bounceTime)
  {
    Serial.println("Exiting Edit Mode");
    bounceTime = millis() + 50;
    //writeSDSettings();
    manualMode = 0;
    button12LastReading == HIGH;
    editMode = 0;

    // Restore old Preset
    digitalWrite(activePresetLED, HIGH);

    // Save Preset
    for (int x = 1; x <= 10; x++)
    {
      tempString = "L" + x;

      //savePresetToString(activePreset, tempString);
    }
  }



  // These are used to determine when button state changes, must stay at bottom of code. 
  button11LastReading = buttonElevenState;
  button12LastReading = buttonTwelveState; 



  //MANUAL Mode
  // Button 1
  if (buttonOneState == HIGH && digitalRead(relay1Pin) == LOW && button1LastReading == LOW && manualMode == 1)
  {
    button1LastReading = HIGH;
    relay1State(1);
  }

  if (buttonOneState == HIGH && digitalRead(relay1Pin) == HIGH && button1LastReading == LOW && manualMode == 1)
  {
    button1LastReading = HIGH;
    relay1State(0);
  }

  // Button 2
  if (buttonTwoState == HIGH && digitalRead(relay2Pin) == LOW && button2LastReading == LOW && manualMode == 1)
  {
    button2LastReading = HIGH;
    relay2State(1);
  }

  if (buttonTwoState == HIGH && digitalRead(relay2Pin) == HIGH && button2LastReading == LOW && manualMode == 1)
  {
    button2LastReading = HIGH;
    relay2State(0);
  }

  // Button 3
  if (buttonThreeState == HIGH && digitalRead(relay3Pin) == LOW && button3LastReading == LOW && manualMode == 1)
  {
    button3LastReading = HIGH;
    relay3State(1);
  }

  if (buttonThreeState == HIGH && digitalRead(relay3Pin) == HIGH && button3LastReading == LOW && manualMode == 1)
  {
    button3LastReading = HIGH;
    relay3State(0);
  }

  // Button 4
  if (buttonFourState == HIGH && digitalRead(relay4Pin) == LOW && button4LastReading == LOW && manualMode == 1)
  {
    button4LastReading = HIGH;
    relay4State(1);
  }

  if (buttonFourState == HIGH && digitalRead(relay4Pin) == HIGH && button4LastReading == LOW && manualMode == 1)
  {
    button4LastReading = HIGH;
    relay4State(0);
  }

  // Button 5
  if (buttonFiveState == HIGH && digitalRead(relay5Pin) == LOW && button5LastReading == LOW && manualMode == 1)
  {
    button5LastReading = HIGH;
    relay5State(1);
  }

  if (buttonFiveState == HIGH && digitalRead(relay5Pin) == HIGH && button5LastReading == LOW && manualMode == 1)
  {
    button5LastReading = HIGH;
    relay5State(0);
  }

  // Button 6
  if (buttonSixState == HIGH && digitalRead(relay6Pin) == LOW && button6LastReading == LOW && manualMode == 1)
  {
    button6LastReading = HIGH;
    relay6State(1);
  }

  if (buttonSixState == HIGH && digitalRead(relay6Pin) == HIGH && button6LastReading == LOW && manualMode == 1)
  {
    button6LastReading = HIGH;
    relay6State(0);
  }

  // Button 7
  if (buttonSevenState == HIGH && digitalRead(relay7Pin) == LOW && button7LastReading == LOW && manualMode == 1)
  {
    button7LastReading = HIGH;
    relay7State(1);
  }

  if (buttonSevenState == HIGH && digitalRead(relay7Pin) == HIGH && button7LastReading == LOW && manualMode == 1)
  {
    button7LastReading = HIGH;
    relay7State(0);
  }

  // Button 8
  if (buttonEightState == HIGH && digitalRead(relay8Pin) == LOW && button8LastReading == LOW && manualMode == 1)
  {
    button8LastReading = HIGH;
    relay8State(1);
  }


  if (buttonEightState == HIGH && digitalRead(relay8Pin) == HIGH && button8LastReading == LOW && manualMode == 1)
  {
    button8LastReading = HIGH;
    relay8State(0);
  }

  // Button 9
  if (buttonNineState == HIGH && digitalRead(relay9Pin) == LOW && button9LastReading == LOW && manualMode == 1)
  {
    button9LastReading = HIGH;
    relay9State(1);
  }

  if (buttonNineState == HIGH && digitalRead(relay9Pin) == HIGH && button9LastReading == LOW && manualMode == 1)
  {
    button9LastReading = HIGH;
    relay9State(0);
  }

  // Button 10
  if (buttonTenState == HIGH && digitalRead(relay10Pin) == LOW && button10LastReading == LOW && manualMode == 1)
  {
    button10LastReading = HIGH;
    relay10State(1);
  }

  if (buttonTenState == HIGH && digitalRead(relay10Pin) == HIGH && button10LastReading == LOW && manualMode == 1)
  {
    button10LastReading = HIGH;
    relay10State(0);
  }

  button1LastReading = buttonOneState;
  button2LastReading = buttonTwoState;
  button3LastReading = buttonThreeState;
  button4LastReading = buttonFourState;
  button5LastReading = buttonFiveState;
  button6LastReading = buttonSixState;
  button7LastReading = buttonSevenState;
  button8LastReading = buttonEightState;
  button9LastReading = buttonNineState;
  button10LastReading = buttonTenState;

}






