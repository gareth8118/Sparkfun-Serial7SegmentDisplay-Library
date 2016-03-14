/*
 * Mock Arduino Wire library
 */

#include "Wire.h"
#include "CppUTestExt/MockSupport.h"

WireClass Wire;

void WireClass::begin()
{
	mock().actualCall("Wire.begin");
}

void WireClass::beginTransmission(uint8_t address)
{
	mock().actualCall("Wire.beginTransmission").withParameter("address", address);
}

void WireClass::send(uint8_t data)
{	
	mock().actualCall("Wire.send").withParameter("data", data);
}

void WireClass::endTransmission()
{
	mock().actualCall("Wire.endTransmission");
}

