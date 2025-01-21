/*
 * neopixel.h
 *
 *  Created on: Nov 12, 2024
 *      Author: administrateur
 */

#ifndef INC_NEOPIXEL_H_
#define INC_NEOPIXEL_H_

#include "main.h"
#define NUMBER_OF_LEDS 143

typedef struct {
	uint8_t red;
	uint8_t green;
	uint8_t blue;
} Color;

extern Color ledString[NUMBER_OF_LEDS];

void neopixelSendColor(uint8_t r, uint8_t g, uint8_t b);
void neopixelSendToLED(uint32_t ledIndex, uint8_t r, uint8_t g, uint8_t b);
void neopixelSendResetState();
void neopixelResetAll();

void arraySetColor(uint32_t ledIndex, uint8_t r, uint8_t g, uint8_t b);
void arrayResetAll();
void arrayRepaint();

void rainbowWalk();

#endif /* INC_NEOPIXEL_H_ */
