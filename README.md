# Alislahish-MAX9814

This library controls a MAX9814 Microphone with AGC and Low-Noise Microphone Bias
by Maxim Integrated.

_Attach it to your **ESP8266/Arduino** directly or using an MCP23017 Expander
as an intermediary._

This library can control the:
* Release/attack ratio (500:1, 2000:1, or 4000:1), and
* Gain level (40dB, 50dB, or 60dB)

Note that all references to A/R (Attack/Release) in the datasheet and on the Adafruit breakout are referred to as RA (Release/Attack) in this library. It is functionally equivalent, however, it made more sense to write it this way.

#### Dependencies:
This library relies upon the Alislahish-ICUsingMCP23017 library:

https://github.com/alislahish/Alislahish-ICUsingMCP23017

...which relies upon the Adafruit-MCP23017-Arduino-Library:

https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library

_Please include them both in your main sketch_

#### Examples:
See the examples folder for code you can run with an oscilloscope and some MAX9814 breakouts to see the difference in waveform characteristics when you use different gain modes. If your oscilloscope displays measurements onscreen, try turning on V<sub>p-p</sub> while running the example sketch.

#### Hardware:

###### Arduino:
https://www.arduino.cc/

###### ESP8266
http://www.esp8266.com

###### MAX9814
Consult the datasheet found at the following link to see usage examples:

http://www.maximintegrated.com/en/products/analog/audio/MAX9814.html

Or, obtain this IC (with microphone) on a breakout board from Adafruit:

https://www.adafruit.com/products/1713

###### MCP23017
https://www.adafruit.com/products/732

http://www.microchip.com/wwwproducts/Devices.aspx?dDocName=en023499

###### _Reference:_


by anwarhahjjeffersongeorge
