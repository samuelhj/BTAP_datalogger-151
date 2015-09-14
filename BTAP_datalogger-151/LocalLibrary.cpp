//
// LocalLibrary.cpp 
// Library C++ code
// ----------------------------------
// Developed with embedXcode 
// http://embedXcode.weebly.com
//
// Project 		BTAP_datalogger-151
//
// Created by 	Samúel Úlfr Þór Hjaltalín Guðjónsson, 2015.9.6 20:49
// 				Samúel Þór Hjaltalín Guðjónsson
//	
// Copyright 	© Samúel Úlfr Þór Hjaltalín Guðjónsson, 2015
// Licence 		<#license#>
//
// See 			LocalLibrary.cpp.h and ReadMe.txt for references
//


#include "LocalLibrary.h"

void blink(uint8_t pin, uint8_t times, uint16_t ms) {
  for (uint8_t i=0; i<times; i++) {
    digitalWrite(pin, HIGH); 
    delay(ms >> 1);               
    digitalWrite(pin, LOW);  
    delay(ms >> 1);              
  }
}
