#include "Alislahish_MAX9814.h"


Alislahish_MAX9814::Alislahish_MAX9814()
{}

Alislahish_MAX9814::Alislahish_MAX9814(uint8_t raPin, uint8_t gainPin)
	: 	_gainPin(gainPin),
		_raPin(raPin)
{
	_ra = MAX9814RA::RA500;	
	_gain = MAX9814Gain::DB40;
}

/**
* set the gain for this MAX9814
*/
void Alislahish_MAX9814::setGain(MAX9814Gain gain){
	_gain = gain;
	setPins();
}

/**
* set the release/attack ratio for this MAX9814
*/
void Alislahish_MAX9814::setRA(MAX9814RA ra){
	_ra = ra;
	setPins();
}

/**
* getter for _ra
*/
MAX9814Gain  Alislahish_MAX9814::getGain(){
	return _gain;
}
/**
* getter for _gain
*/
MAX9814RA  Alislahish_MAX9814::getRA(){
	return _ra;
}

/**
* return human readable gain
*/
char* Alislahish_MAX9814::printGain(){
	return (char*)MAX9814GainTypes[static_cast<int>(_gain)];
}


/**
* return human readable release/attack ratio
*/
char* Alislahish_MAX9814::printRA(){
	return (char*)MAX9814RATypes[static_cast<int>(_ra)];
}

void Alislahish_MAX9814::setPins(){
	//set gain
	switch(_gain){
		case MAX9814Gain::DB40:
			ICUsingMCP23017::pinMode(_gainPin, OUTPUT);
			ICUsingMCP23017::digitalWrite(_gainPin, HIGH);
			break;
		case MAX9814Gain::DB50:
			ICUsingMCP23017::pinMode(_gainPin, OUTPUT);
			ICUsingMCP23017::digitalWrite(_gainPin, LOW);
			break;
		case MAX9814Gain::DB60:
			ICUsingMCP23017::pinMode(_gainPin, INPUT); //float?
			break;
	}

	//set RA
	switch(_ra){
		case MAX9814RA::RA500:
			ICUsingMCP23017::pinMode(_raPin, OUTPUT);
			ICUsingMCP23017::digitalWrite(_raPin, LOW);
			break;
		case MAX9814RA::RA2000:
			ICUsingMCP23017::pinMode(_raPin, OUTPUT);
			ICUsingMCP23017::digitalWrite(_raPin, HIGH);
			break;
		case MAX9814RA::RA4000:
			ICUsingMCP23017::pinMode(_raPin, INPUT);
			break;
	}

}