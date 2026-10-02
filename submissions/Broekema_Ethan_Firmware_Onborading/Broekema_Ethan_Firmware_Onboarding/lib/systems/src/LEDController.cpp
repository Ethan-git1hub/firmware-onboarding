#include "LEDController.h"

LEDController::LEDController()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
}

void LEDController::update(float temperature)
{
    unsigned long blinkInterval = 2000 - (temperature * 25);
    if (blinkInterval < 250)
    {
        blinkInterval = 250;
    }
    
    if (millis() - lastBlinkTime >= blinkInterval)
    {
        lastBlinkTime = millis();

        ledState = !ledState;

        digitalWrite(BMEConstants::LED_PIN, ledState);
    }
}

    