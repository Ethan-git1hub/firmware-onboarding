#pragma once
#include <Arduino.h>
#include "BMEConstants.h"

class LEDController
{
public:

    LEDController();
    
    void update(float temperature);
    

private: 

    unsigned long lastBlinkTime = 0;
    bool ledState = false;

};