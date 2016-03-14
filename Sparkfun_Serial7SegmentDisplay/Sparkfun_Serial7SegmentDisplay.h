/*
 * Teensy driver for the Sparkfun Seven Segment Serial Display
 */

#include "Arduino.h"

class Sparkfun_Serial7SegmentDisplay
{
public:
	Sparkfun_Serial7SegmentDisplay();
	void begin();
	void clear();
	void sendDigit(uint8_t digit);
	void sendDigits(uint8_t digits[]);
	void setDecimalPoint(uint8_t data);
	void cursor(uint8_t data);
private:
	static const uint8_t I2C_DEFAULT_ADDRESS = 0x71;
	static const uint8_t CMD_CLEAR = 0x76;
	static const uint8_t CMD_SETDECIMALPOINT = 0x77;
	static const uint8_t CMD_CURSOR = 0x79;
	uint8_t _ssPin;
	uint8_t _i2cAddress;

	void startTransfer();
	void endTransfer();
};