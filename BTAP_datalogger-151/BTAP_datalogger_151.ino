//
// BTAP_datalogger-151
//
// Data logger for HAB Iceland 151
// Developed with [embedXcode](http://embedXcode.weebly.com)
//
// Author 		Samúel Úlfr Þór Hjaltalín Guðjónsson
// 				Samúel Þór Hjaltalín Guðjónsson
//
// Date			2015.9.6 20:49
// Version		<#version#>
/
/*				Copyright 2015 Bifrost the Aurora Project All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 
 Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer. Modification, or partial use is permitted as long as the original author is NOT mentioned in any way.
 Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY BIFROST THE AURORA PROJECT ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL BIFRÖST THE AURORA PROJECT OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 The views and conclusions contained in the software and documentation are those of the authors and should not be interpreted as representing official policies, either expressed or implied, of Bifröst the Aurora Project
 
 */
// See			ReadMe.txt for references
//

// Core library for code-sense - IDE-based
#if defined(WIRING) // Wiring specific
#include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#elif defined(LITTLEROBOTFRIENDS) // LittleRobotFriends specific
#include "LRF.h"
#elif defined(MICRODUINO) // Microduino specific
#include "Arduino.h"
#elif defined(SPARK) || defined(PARTICLE) // Particle / Spark specific
#include "application.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(REDBEARLAB) // RedBearLab specific
#include "Arduino.h"
#elif defined(ESP8266) // ESP8266 specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif // end IDE

// Include application, user and local libraries
#include "LocalLibrary.h"


// Prototypes


// Define variables and constants
//
#define SERIAL_BAUD_RATE 9600

// SDCARD connections

// LM35 external temperature read.
// define the pins we use to read the temperature sensor - Should explain it self
#define LM35_EXTERNAL_NEGATIVE 0
#define LM35_EXTERNAL_POSITIVE 1



// date
uint8_t current_date;





uint8_t status_led;


//
// Brief	Setup
// Details	Define the pin the LED is connected to
//
// Add setup code
void setup() {

    
    pinMode(status_led, OUTPUT);
}

int_t_sensor_read()
{
    // variables
    float temp_external, read_positive, read_negative;
    
    // Read the positive and negative signal from LM35
    
    read_positive = analogRead(LM35_EXTERNAL_POSITIVE);
    read_negative = analogRead(LM35_EXTERNAL_NEGATIVE);
    
    // *magic* (No just kidding). We divide our signal voltage with 1024 and multiply that by 5000mV.
    read_positive = ((read_positive / 1024.0) * 5000) / 10.0;
    read_negative = ((read_negative / 1024.0) * 5000) / 10.0;
    
    temp_external = read_positive - read_negative;
    
}

//
// Brief	Loop
// Details	Call blink
//
// Add loop code
void loop() {
    blink(status_led, 3, 333);
    delay(1000);
}
