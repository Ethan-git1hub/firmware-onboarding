#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface():bme(BMEConstants::SPI_CS_PIN, &SPI)
{
}

bool BMESPIInterface::begin()
{
    return bme.begin();
}

float BMESPIInterface::readTemperature()
{
    return bme.readTemperature();
}