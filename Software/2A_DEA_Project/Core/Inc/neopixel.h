/*
 * neopixel.h
 *
 *  Created on: Nov 12, 2024
 *      Author: administrateur
 */

#ifndef INC_NEOPIXEL_H_
#define INC_NEOPIXEL_H_Nobori

#include "main.h"
#define NUMBER_OF_LEDS 138
#define TOTAL_DATA_LENGTH NUMBER_OF_LEDS * 24 + 1

typedef struct h_ledstring_struct {
	TIM_HandleTypeDef * htim;
	uint32_t tim_channel;
	uint16_t data[TOTAL_DATA_LENGTH];
} h_ledstring_t;

int ledstringInit(h_ledstring_t *h_ledstring);
int ledstringSetHexColor(h_ledstring_t *h_ledstring, uint16_t index, uint32_t hex);
int ledstringSetRGBColor(h_ledstring_t *h_ledstring, uint16_t index, uint8_t red, uint8_t green, uint8_t blue);
int ledstringRepaint(h_ledstring_t *h_ledstring);

void animateInit();
void animateChaserFwd(uint32_t color, uint32_t delay);
void animateChaserBckwd(uint32_t color, uint32_t delay);
void animateChaserKudari(uint32_t color, uint32_t delay);
void animateChaserNobori(uint32_t color, uint32_t delay);
void animateBlink(uint32_t color, uint32_t delay);

//typedef struct {
//	uint8_t red;
//	uint8_t green;
//	uint8_t blue;
//} Color;
//
//extern Color ledString[NUMBER_OF_LEDS];
//
//void neopixelSendColor(uint8_t r, uint8_t g, uint8_t b);
//void neopixelSendToLED(uint32_t ledIndex, uint8_t r, uint8_t g, uint8_t b);
//void neopixelSendResetState();
//void neopixelResetAll();
//
//void arraySetColor(uint32_t ledIndex, uint8_t r, uint8_t g, uint8_t b);
//void arrayResetAll();
//void arrayRepaint();
//
//void rainbowWalk();

#endif /* INC_NEOPIXEL_H_ */
