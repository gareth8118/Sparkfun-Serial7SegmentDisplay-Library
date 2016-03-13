#include "SPI.h"
#include "CppUTestExt/MockSupport.h"

SPIClass SPI;

void SPIClass::begin()
{

	mock().actualCall("SPI.begin");
}

void SPIClass::beginTransaction(SPISettings settings)
{
	mock().actualCall("SPI.beginTransaction").withParameter("speed", settings._speedMaximum).withParameter("order", settings._dataOrder).withParameter("mode", settings._dataMode);
}

void SPIClass::transfer(uint8_t data)
{
	mock().actualCall("SPI.transfer").withParameter("data", data);
}

void SPIClass::endTransaction()
{
	mock().actualCall("SPI.endTransaction");
}