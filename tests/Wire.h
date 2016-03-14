/*
 * Mock header for Arduino Wire library
 */

#ifndef __WIRE_H
 #define __WIRE_H
#include <stdint.h>

class WireClass
{
public:
	void begin();
	void beginTransmission(uint8_t address);
	void send(uint8_t data);
	void endTransmission();
};

extern WireClass Wire;

#endif // __WIRE_H
