#ifndef __ARDUINO_H
#define __ARDUINO_H

#include <stdint.h>

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define HIGH 0x1
#define LOW  0x0

static const uint8_t SS = 10;

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin , uint8_t value);

void delayMicroseconds(uint16_t delay);

#endif