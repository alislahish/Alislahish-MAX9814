/**
*
* Alislahish_MAX9814.h
* by anwar hahj jefferson-george
*
* This file can be used to represent the functions and settings of the
*
*  MAX9814 Electret Microphone Amplifier with Auto Gain Control
*  It is available from Adafruit
*
*  Breakout board:
*  https://www.adafruit.com/products/1713
*
*  Manufacturer Page:
*  http://www.maximintegrated.com/en/products/analog/audio/MAX9814.html
*
*  Alternate Datasheet source (Rev. A):
*  http://datasheets.maximintegrated.com/en/ds/MAX9814.pdf
*
**********************************************************************
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Arduino.h"
#include "ICUsingMCP23017.h"

//only include this library description once
#ifndef ALISLAHISH_MAX9814_H
#define ALISLAHISH_MAX9814_H

//allowable gain settings for max9814
enum class MAX9814Gain{
	DB40,//0x28,
	DB50,//0x32,
	DB60//0x3C
};
#define NUM_MAX9814_GAIN_LEVELS 3
//human-readable gain types
static const char* MAX9814GainTypes[NUM_MAX9814_GAIN_LEVELS] = {
	"40 dB",
	"50 dB",
	"60 dB"
};

//allowable release/attack ratios for MAX9814
enum class  MAX9814RA{
	RA500, //0x1F4,
	RA2000,//0x7D0,
	RA4000 //0xFA0  
};
#define NUM_MAX9814_RA_RATIOS 3
//human-readable RA types
static const char* MAX9814RATypes[NUM_MAX9814_RA_RATIOS]= {
	"500:1",
	"2000:1",
	"4000:1"
};

//human-readable release/attack ratio
//String MAX9814RATypes[3];

class Alislahish_MAX9814 : public ICUsingMCP23017 {
	public:
		Alislahish_MAX9814();
		Alislahish_MAX9814(uint8_t raPin, uint8_t gainPin);
		void setGain(MAX9814Gain gain);
		void setRA(MAX9814RA ra);
		char* printGain();
		char* printRA();
	private:
		MAX9814Gain _gain;
		MAX9814RA _ra;
		uint8_t _gainPin;
		uint8_t _raPin;

		void setPins();
};

#endif