/*
 * Test suite for SevenSegment
 */


#include "Sparkfun_Serial7SegmentDisplay.h"
#include "SPI.h"
#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(Sparkfun_Serial7SegmentDisplay)
{
	Sparkfun_Serial7SegmentDisplay *display;

	void setup()
	{
		display = new Sparkfun_Serial7SegmentDisplay(SS);
	}

	void teardown()
	{
		delete display;
		mock().clear();
	}

	void mockExpectStartSPI()
	{
		mock().expectOneCall("digitalWrite").withParameter("pin", SS).withParameter("value", 0);
		mock().expectOneCall("SPI.beginTransaction").withParameter("speed", 250000).withParameter("order", MSBFIRST).withParameter("mode", SPI_MODE0);
	}

	void mockExpectEndSPI()
	{
		mock().expectOneCall("SPI.endTransaction");
		mock().expectOneCall("delayMicroseconds").withParameter("delay", 10);
		mock().expectOneCall("digitalWrite").withParameter("pin", SS).withParameter("value", 1);
	}

};

TEST(Sparkfun_Serial7SegmentDisplay, ObjectCreation)
{
	CHECK(display);
}

TEST(Sparkfun_Serial7SegmentDisplay, Initialization)
{
	mock().expectOneCall("pinMode").withParameter("pin", SS).withParameter("mode", OUTPUT);
	mock().expectOneCall("digitalWrite").withParameter("pin", SS).withParameter("value", 1);
	mock().expectOneCall("SPI.begin");

	display->begin();
	mock().checkExpectations();
}

TEST(Sparkfun_Serial7SegmentDisplay, ClearDisplay)
{
	mockExpectStartSPI();
	mock().expectOneCall("SPI.transfer").withParameter("data", 0x76);
	mockExpectEndSPI();
	display->clear();
	mock().checkExpectations();	
}

TEST(Sparkfun_Serial7SegmentDisplay, SetDecimalPoint)
{
	mockExpectStartSPI();
	mock().expectOneCall("SPI.transfer").withParameter("data", 0x77);
	mock().expectOneCall("SPI.transfer").withParameter("data", 0x04);
	mockExpectEndSPI();
	display->setDecimalPoint(0x04);
	mock().checkExpectations();
}

TEST(Sparkfun_Serial7SegmentDisplay, CursorControl)
{
	mockExpectStartSPI();
	mock().expectOneCall("SPI.transfer").withParameter("data", 0x79);
	mock().expectOneCall("SPI.transfer").withParameter("data", 0x0);
	mockExpectEndSPI();
	display->cursor(0);
	mock().checkExpectations();
}

TEST(Sparkfun_Serial7SegmentDisplay, SendDigit)
{
	mockExpectStartSPI();
	mock().expectOneCall("SPI.transfer").withParameter("data", 1);
	mockExpectEndSPI();
	display->sendDigit(1);
	mock().checkExpectations();
}

TEST(Sparkfun_Serial7SegmentDisplay, SendDigits)
{
	uint8_t digits[] = { 0x20, 8, 0, 0 };

	mockExpectStartSPI();
	mock().expectOneCall("SPI.transfer").withParameter("data", 0x79);
	mock().expectOneCall("SPI.transfer").withParameter("data", 0x0);
	for (int i = 0; i < 4; i++)
	{
		mock().expectOneCall("SPI.transfer").withParameter("data", digits[i]);
	}
	mockExpectEndSPI();
	display->sendDigits(digits);
	mock().checkExpectations();
}

