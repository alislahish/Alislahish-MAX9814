
/**
* This sketch tests the Alislahish_MAX9814 library.
* It just toggles the gain and release/attack ratio of a single MAX9814
* if you attach two as instructed and breadboard them next to each other, 
* you should see a difference in their signals. 
*
* The library lets you control the Release/Attack ratio and gain of the MAX9814:
* http://www.maximintegrated.com/en/products/analog/audio/MAX9814.html
*
* It was tested with this breakout board from Adafruit: *
* https://www.adafruit.com/products/1713
*
* Note that the data sheet gives the attack/release ratio; while the library
* writes this as release/attack ratio, this difference is solely for readability;
* it is functionally identical,
*
* This library requires the ICUsingMCP23017 library, Adafruit_MCP23017 library, Wire.h, Arduino.h
*
* In this example, an ESP8266 was connected to the MAX9814 via an MCP23017,
* but you can do it with an Arduino and/or omit the MCP23017 gpio expander
* connections are as follows:
*
*    ESP8266    ->    MCP23017
*    GPIO 4(SDA)->    Pin 13
*    GPIO 5(SCL)->    Pin 12
*
*    MCP23017
*    Pin 9 -> 3.3V, Pin 10 -> GND,
*    Pin 15, 16, 17 (A0, A1, A2) -> GND, Pin 18 (!RESET) -> Vcc via 10K resistor
*
*    MCP23017        ->    first MAX9814 Adafruit breakout (ch0)
*    Pin 21(GPA0)    ->    A/R Pin
*    Pin 22(GPA1)    ->    GAIN Pin
*    
*    MCP23017        ->    second MAX9814 Adafruit breakout (ch1)
*    Pin 23(GPA2)    ->    A/R Pin
*    Pin 24(GPA3)    ->    GAIN Pin
*
*    MAX9814 Adafruit breakout (both channels)
*    Vcc             ->     Vcc
*    GND             ->     GND
*    OUT             ->     Oscilloscope
*
*
*    Hook up one channel of your oscilloscope
*    to the OUT on the MAX9814
*    to see how it changes
*/
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <ICUsingMCP23017.h>
#include <Alislahish_MAX9814.h>

// MAX9814 control pins
// ...you could add more audio channels
// by duplicating the following
// and changing accordingly
#define CH_0_RA_PIN 0 //GPA0
#define CH_0_GAIN_PIN 1 //GPA1

#define CH_1_RA_PIN 2 //GPA2
#define CH_1_GAIN_PIN 3 //GPA3

//how long should we remain in a specific mode before changing?
#define HOLD_TIME 1597

//define MAX9814 audio channels 
//constructor sets default gain to 40dB 
//and default release/attack to 500:1
Alislahish_MAX9814 ch0(CH_0_GAIN_PIN, CH_0_RA_PIN);
Alislahish_MAX9814 ch1(CH_1_GAIN_PIN, CH_1_RA_PIN);

Adafruit_MCP23017 mcp;
long lastMillis = 0L;
uint8_t ra = 0;
uint8_t gain = 0;
uint8_t mcpAddr = 0;
uint8_t led=LOW;

void setup() {
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    mcp.begin(mcpAddr);
    //make the MAX9814s use the same MCP23017
    ch0.setMCP23017(true, &mcp, mcpAddr);
    ch1.setMCP23017(true, &mcp, mcpAddr);
    //set led
    pinMode(BUILTIN_LED, OUTPUT);
    digitalWrite(BUILTIN_LED, led);
}



void loop() {
    //change settings of audio ch0 if we've waited long enough
    if (millis() >= (lastMillis + HOLD_TIME)) {
        lastMillis=millis();
        ra++;
        ra %= 3;
        if (ra == 0) {
            gain++;
            gain %= 3;
        }
        ch0.setGain(static_cast<MAX9814Gain>(gain));
        ch0.setRA(static_cast<MAX9814RA>(ra));
        
        //reveal settings
        Serial.print("Gain: ");
        Serial.println(ch0.printGain());
        
        Serial.print("Release/Attack: ");
        Serial.println(ch0.printRA()); 

        //indicator led
        if(led==HIGH){
            led=LOW;
        } else {
            led=HIGH;
        }
        digitalWrite(BUILTIN_LED, led);
    }
}
