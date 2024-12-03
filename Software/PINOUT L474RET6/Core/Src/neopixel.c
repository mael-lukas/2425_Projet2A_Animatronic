/*
 * neopixel.c
 *
 *  Created on: Nov 12, 2024
 *      Author: administrateur
 */

#include "neopixel.h"
#include "stm32g4xx_hal.h"

void neopixelSendResetState(){
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0);
	for(int i=1;i<1200;i++); // required delay for neopixel protocol
	//HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);
}

void neopixelSendColor(uint8_t r, uint8_t g, uint8_t b) {
	uint8_t grb[3] = {g, r, b};
	for(int j = 0; j < 3; j++) {
		for(int i = 0; i < 8; i++) {
			if ((grb[j]&0x1)==0) {
				GPIOA->ODR |= (1 << 7);
				for(int i=1;i<2;i++); // required delay for neopixel protocol
				GPIOA->ODR &= ~(1 << 7);
				for(int i=1;i<4;i++); // required delay for neopixel protocol
	        }
			else {
				GPIOA->ODR |= (1 << 7);
				for(int i=1;i<4;i++); // required delay for neopixel protocol
				GPIOA->ODR &= ~(1 << 7);
				for(int i=1;i<2;i++); // required delay for neopixel protocol
			}
			grb[j] = grb[j]>>1;
		}
	}
}

void neopixelResetAll() {
	neopixelSendResetState();
	for(int i=0;i<NUMBER_OF_LEDS;i++) {
		neopixelSendColor(0,0,0);
	}
	neopixelSendResetState();
}

void neopixelSendToLED(uint32_t ledIndex, uint8_t r, uint8_t g, uint8_t b) {
	if(ledIndex < NUMBER_OF_LEDS) {
		neopixelSendResetState();
		for(int i = 0; i < (ledIndex); i++) {
			neopixelSendColor(0,0,0);
		}
		neopixelSendColor(r,g,b);
		neopixelSendResetState();
	}
}

void arraySetColor(uint32_t ledIndex, uint8_t r, uint8_t g, uint8_t b) {
	if(ledIndex < NUMBER_OF_LEDS) {
		ledString[ledIndex].red = r;
		ledString[ledIndex].green = g;
		ledString[ledIndex].blue = b;
	}
}

void arrayResetAll() {
	for(int i = 0; i < NUMBER_OF_LEDS; i++) {
		arraySetColor(i,0,0,0);
	}
}

void arrayRepaint() {
	neopixelSendResetState();
	for(int i = 0; i < NUMBER_OF_LEDS; i++) {
		neopixelSendColor(ledString[i].red, ledString[i].green, ledString[i].blue);
	}
	neopixelSendResetState();
}

void rainbowWalk() {
	for(int i= 0; i < (NUMBER_OF_LEDS/7 - 1); i++){
		arrayResetAll();
		arraySetColor(7*i,255,0,0);
		arraySetColor(7*i+1,230,200,0);
		arraySetColor(7*i+2,220,220,0);
		arraySetColor(7*i+3,0,255,0);
		arraySetColor(7*i+4,0,255,1);
		arraySetColor(7*i+5,0,0,250);
		arraySetColor(7*i+6,100,0,50);
		arrayRepaint();
		HAL_Delay(25);
	}
}
