#include <Arduino.h>

#include "CppUTestExt/MockSupport.h"

void pinMode(uint8_t pin, uint8_t mode)
{
	mock().actualCall("pinMode").withParameter("pin", pin).withParameter("mode", mode);
}

void digitalWrite(uint8_t pin, uint8_t value)
{
	mock().actualCall("digitalWrite").withParameter("pin", pin).withParameter("value", value);
}

void delayMicroseconds(uint16_t delay)
{
	mock().actualCall("delayMicroseconds").withParameter("delay", delay);
}
