/*
 * Test suite for SevenSegment
 */


#include "Sparkfun_Serial7SegmentDisplay.h"
#include "Wire.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"


TEST_GROUP(Sparkfun_Serial7SegmentDisplay)
{
	Sparkfun_Serial7SegmentDisplay *display;

	static const uint8_t I2C_ADDRESS = 0x71;

	void setup()
	{
		display = new Sparkfun_Serial7SegmentDisplay();
	}

	void teardown()
	{
		delete display;
		mock().clear();
	}

	void mockExpectStartWire()
	{
		mock().expectOneCall("Wire.beginTransmission").withParameter("address", I2C_ADDRESS);
	}

	void mockExpectEndWire()
	{
		mock().expectOneCall("Wire.endTransmission");
	}

};

TEST(Sparkfun_Serial7SegmentDisplay, ObjectCreation)
{
	CHECK(display);
}

TEST(Sparkfun_Serial7SegmentDisplay, Initialization)
{
	mock().expectOneCall("Wire.begin");
	display->begin();
	mock().checkExpectations();
}

TEST(Sparkfun_Serial7SegmentDisplay, ClearDisplay)
{
	mockExpectStartWire();
	mock().expectOneCall("Wire.send").withParameter("data", 0x76);
	mockExpectEndWire();
	display->clear();
	mock().checkExpectations();	
}

TEST(Sparkfun_Serial7SegmentDisplay, SetDecimalPoint)
{
	mockExpectStartWire();
	mock().expectOneCall("Wire.send").withParameter("data", 0x77);
	mock().expectOneCall("Wire.send").withParameter("data", 0x04);
	mockExpectEndWire();
	display->setDecimalPoint(0x04);
	mock().checkExpectations();
}

TEST(Sparkfun_Serial7SegmentDisplay, CursorControl)
{
	mockExpectStartWire();
	mock().expectOneCall("Wire.send").withParameter("data", 0x79);
	mock().expectOneCall("Wire.send").withParameter("data", 0x0);
	mockExpectEndWire();
	display->cursor(0);
	mock().checkExpectations();
}

TEST(Sparkfun_Serial7SegmentDisplay, SendDigit)
{
	mockExpectStartWire();
	mock().expectOneCall("Wire.send").withParameter("data", 1);
	mockExpectEndWire();
	display->sendDigit(1);
	mock().checkExpectations();
}

TEST(Sparkfun_Serial7SegmentDisplay, SendDigits)
{
	uint8_t digits[] = { 0x20, 8, 0, 0 };

	mockExpectStartWire();
	mock().expectOneCall("Wire.send").withParameter("data", 0x79);
	mock().expectOneCall("Wire.send").withParameter("data", 0x0);
	for (int i = 0; i < 4; i++)
	{
		mock().expectOneCall("Wire.send").withParameter("data", digits[i]);
	}
	mockExpectEndWire();
	display->sendDigits(digits);
	mock().checkExpectations();
}

