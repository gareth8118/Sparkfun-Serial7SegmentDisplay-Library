#include <i2c_t3.h>
#include "Sparkfun_Serial7SegmentDisplay.h"

Sparkfun_Serial7SegmentDisplay::Sparkfun_Serial7SegmentDisplay() : _i2cAddress(I2C_DEFAULT_ADDRESS)
{
	;
}

void Sparkfun_Serial7SegmentDisplay::begin()
{
	Wire.begin();
}

void Sparkfun_Serial7SegmentDisplay::startTransfer()
{
	Wire.beginTransmission(_i2cAddress);
}

void Sparkfun_Serial7SegmentDisplay::endTransfer()
{
	Wire.endTransmission();
}

void Sparkfun_Serial7SegmentDisplay::clear()
{
	startTransfer();
	Wire.send(CMD_CLEAR);
	endTransfer();
}

void Sparkfun_Serial7SegmentDisplay::setDecimalPoint(uint8_t data)
{
	startTransfer();
	Wire.send(CMD_SETDECIMALPOINT);
	Wire.send(data);
	endTransfer();
}

void Sparkfun_Serial7SegmentDisplay::cursor(uint8_t position)
{
	startTransfer();
	Wire.send(CMD_CURSOR);
	Wire.send(position);
	endTransfer();
}

void Sparkfun_Serial7SegmentDisplay::sendDigit(uint8_t digit)
{
	startTransfer();
	Wire.send(digit);
	endTransfer();
}

void Sparkfun_Serial7SegmentDisplay::sendDigits(uint8_t digit[])
{
	startTransfer();
	Wire.send(CMD_CURSOR);
	Wire.send(0);
	for (int i = 0; i < 4; i++)
	{
		Wire.send(digit[i]);
	}
	endTransfer();
}
