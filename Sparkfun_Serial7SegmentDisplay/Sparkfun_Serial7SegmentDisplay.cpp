#include <SPI.h>
#include "Sparkfun_Serial7SegmentDisplay.h"

// SPI configuration for the display
SPISettings settings_7seg(250000,  MSBFIRST, SPI_MODE0);

Sparkfun_Serial7SegmentDisplay::Sparkfun_Serial7SegmentDisplay(uint8_t ssPin) : _ssPin(ssPin)
{
	;
}

void Sparkfun_Serial7SegmentDisplay::begin()
{
	pinMode(_ssPin, OUTPUT);
	digitalWrite(_ssPin, HIGH);
	SPI.begin();
}

void Sparkfun_Serial7SegmentDisplay::startTransfer()
{
	digitalWrite(_ssPin, LOW);
	SPI.beginTransaction(settings_7seg);
}

void Sparkfun_Serial7SegmentDisplay::endTransfer()
{
	SPI.endTransaction();
	delayMicroseconds(10);
	digitalWrite(_ssPin, HIGH);
}

void Sparkfun_Serial7SegmentDisplay::clear()
{
	startTransfer();
	SPI.transfer(CMD_CLEAR);
	endTransfer();
}

void Sparkfun_Serial7SegmentDisplay::setDecimalPoint(uint8_t data)
{
	startTransfer();
	SPI.transfer(CMD_SETDECIMALPOINT);
	SPI.transfer(data);
	endTransfer();
}

void Sparkfun_Serial7SegmentDisplay::cursor(uint8_t position)
{
	startTransfer();
	SPI.transfer(CMD_CURSOR);
	SPI.transfer(position);
	endTransfer();
}

void Sparkfun_Serial7SegmentDisplay::sendDigit(uint8_t digit)
{
	startTransfer();
	SPI.transfer(digit);
	endTransfer();
}

void Sparkfun_Serial7SegmentDisplay::sendDigits(uint8_t digit[])
{
	startTransfer();
	SPI.transfer(CMD_CURSOR);
	SPI.transfer(0);
	for (int i = 0; i < 4; i++)
	{
		SPI.transfer(digit[i]);
	}
	endTransfer();
}
