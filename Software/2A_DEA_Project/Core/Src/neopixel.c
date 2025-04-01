/*
 * neopixel.c
 *
 *  Created on: Nov 12, 2024
 *      Author: administrateur
 */

#include "neopixel.h"
#include "stm32g4xx_hal.h"

extern TIM_HandleTypeDef htim4;

h_ledstring_t h_ledstring = {
		.htim = &htim4,
		.tim_channel = TIM_CHANNEL_1
};

int ledstringInit(h_ledstring_t *h_ledstring) {
	for (int i = 0 ; i < TOTAL_DATA_LENGTH ; i++) {
		h_ledstring->data[i] = 32;
	}
	h_ledstring->data[TOTAL_DATA_LENGTH-1] = 0;

	int status = ledstringRepaint(h_ledstring);
	return status;
}

int ledstringSetHexColor(h_ledstring_t *h_ledstring, uint16_t index, uint32_t hex) {
	uint8_t red = (hex & 0xFF0000) >> 16;
	uint8_t green = (hex & 0x00FF00) >> 8;
	uint8_t blue = (hex & 0x0000FF);

	ledstringSetRGBColor(h_ledstring, index, red, green, blue);
	return -1;
}

int ledstringSetRGBColor(h_ledstring_t *h_ledstring, uint16_t index, uint8_t red, uint8_t green, uint8_t blue) {
	// neopixel color encoding is GRB
	uint32_t hex = (blue << 16) + (red << 8) + (green);

	if (index < NUMBER_OF_LEDS) {
		for (int j = 0 ; j < 24 ; j++) {
			if (hex & (1<<j)) {
				h_ledstring->data[j + 24*index] = 13;
			}
			else {
				h_ledstring->data[j + 24*index] = 6;
			}
		}

		return 0;
	}
	return 0;
}

int ledstringRepaint(h_ledstring_t *h_ledstring) {
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_11);
	if (HAL_TIM_PWM_Start_DMA(h_ledstring->htim, h_ledstring->tim_channel, (uint32_t *) h_ledstring->data, TOTAL_DATA_LENGTH) == HAL_OK) {
		return 0;
	}
	else {
		return -1;
	}
}

void animateInit() {
	ledstringInit(&h_ledstring);
}

void animateChaserFwd(uint32_t color, uint32_t delay) {
	for (int i = 0 ; i < NUMBER_OF_LEDS ; i++) {
			ledstringSetHexColor(&h_ledstring, i, color);
			ledstringRepaint(&h_ledstring);
			HAL_Delay(delay);
		}

		for (int i = 0 ; i < NUMBER_OF_LEDS ; i++) {
			ledstringSetHexColor(&h_ledstring, i, 0x000000);
			ledstringRepaint(&h_ledstring);
			HAL_Delay(delay);
		}
}

void animateChaserBckwd(uint32_t color, uint32_t delay) {
	for (int i = 0 ; i < NUMBER_OF_LEDS ; i++) {
		ledstringSetHexColor(&h_ledstring, NUMBER_OF_LEDS-i-1, color);
		ledstringRepaint(&h_ledstring);

		HAL_Delay(delay);
	}

	for (int i = 0 ; i < NUMBER_OF_LEDS ; i++) {
		ledstringSetHexColor(&h_ledstring, NUMBER_OF_LEDS-i-1, 0x000000);
		ledstringRepaint(&h_ledstring);

		HAL_Delay(delay);
	}
}

void animateChaserKudari(uint32_t color, uint32_t delay) {
	uint16_t center = NUMBER_OF_LEDS/2;

		for (int i = 0 ; i < center ; i++) {
			ledstringSetHexColor(&h_ledstring, center+i, color);
			ledstringSetHexColor(&h_ledstring, center-i-1, color);

			ledstringRepaint(&h_ledstring);

			HAL_Delay(delay);
		}

		for (int i = 0 ; i < center ; i++) {
			ledstringSetHexColor(&h_ledstring, center+i, 0);
			ledstringSetHexColor(&h_ledstring, center-i-1, 0);

			ledstringRepaint(&h_ledstring);

			HAL_Delay(delay);
		}
}

void animateChaserNobori(uint32_t color, uint32_t delay) {
	uint16_t center = NUMBER_OF_LEDS/2;

		for (int i = 0 ; i < center ; i++) {
			ledstringSetHexColor(&h_ledstring, i, color);
			ledstringSetHexColor(&h_ledstring, NUMBER_OF_LEDS-i-1, color);

			ledstringRepaint(&h_ledstring);

			HAL_Delay(delay);
		}

		for (int i = 0 ; i < center ; i++) {
			ledstringSetHexColor(&h_ledstring, i, 0);
			ledstringSetHexColor(&h_ledstring, NUMBER_OF_LEDS-i-1, 0);

			ledstringRepaint(&h_ledstring);

			HAL_Delay(delay);
		}
}

void animateBlink(uint32_t color, uint32_t delay) {
	for (int i = 0 ; i < NUMBER_OF_LEDS ; i++) {
			ledstringSetHexColor(&h_ledstring, i, color);
		}

		ledstringRepaint(&h_ledstring);

		HAL_Delay(delay);

		for (int i = 0 ; i < NUMBER_OF_LEDS ; i++) {
			ledstringSetHexColor(&h_ledstring, i, 0);
		}

		ledstringRepaint(&h_ledstring);

		HAL_Delay(delay);
}

