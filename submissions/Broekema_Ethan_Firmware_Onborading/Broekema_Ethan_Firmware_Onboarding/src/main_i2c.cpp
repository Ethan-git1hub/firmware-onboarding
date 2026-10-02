#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

LEDController ledController;

void setup()
{
    Serial.begin(115200);
    BMEI2CInterfaceInstance::create();

    if (BMEI2CInterfaceInstance::instance().begin())
    {
        Serial.println("BME280 sensor initialized successfully.");
    }
    else
    {
        Serial.println("Failed to initialize BME280 sensor.");
    }
}

void loop()
{
    float temperature = BMEI2CInterfaceInstance::instance().readTemperature();
    if (temperature >= BMEConstants::MAX_TEMPERATURE)
    {
        Serial.print("ERROR: Temperature is too high: ");
        Serial.print(temperature, 2);
        Serial.println(" °C");
        Serial.print("Maximum temperature allowed: ");
        Serial.print(BMEConstants::MAX_TEMPERATURE, 2);
        Serial.println(" °C");

        while(true)
        {
        }
    }
    
    Serial.print("Temperature: ");
    Serial.print(temperature, 2);
    Serial.println(" °C");
    
    ledController.update(temperature);
}