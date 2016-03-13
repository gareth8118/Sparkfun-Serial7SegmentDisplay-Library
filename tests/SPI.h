/*
 * Mock SPI objects
 */

#ifndef __SPI_H
#define __SPI_H

#include <stdint.h>

#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

#define LSBFIRST 0
#define MSBFIRST 1


class SPISettings
{
public:
	SPISettings(int speedMaximum, int dataOrder, int dataMode) : 
		_speedMaximum(speedMaximum), _dataOrder(dataOrder), _dataMode(dataMode)
		{ }

	int _speedMaximum;
	int _dataOrder;
	int _dataMode;
};

class SPIClass
{
public:
	void begin();
	void beginTransaction(SPISettings settings);
	void endTransaction();
	void transfer(uint8_t data);
};

extern SPIClass SPI;

#endif