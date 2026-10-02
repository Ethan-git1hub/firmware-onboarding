#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"
#include <SPI.h>

class BMESPIInterface
{
public:

    BMESPIInterface();

    bool begin();

    float readTemperature();

private:

    Adafruit_BME280 bme;

};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;