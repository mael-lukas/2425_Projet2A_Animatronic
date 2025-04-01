/*
 * servo.c
 *
 *  Created on: Mar 11, 2025
 *      Author: administrateur
 */

#include "servo.h"

void servoInit(h_servo_t *servoHandle, TIM_HandleTypeDef *timer, uint32_t timerChannel) {
	servoHandle->timer = timer;
	servoHandle->timerChannel = timerChannel;
	servoHandle->pos0 = 250;
	servoHandle->pos1 = 1250;
	HAL_TIM_PWM_Start(servoHandle->timer, servoHandle->timerChannel);
	__HAL_TIM_SET_COMPARE(servoHandle->timer, servoHandle->timerChannel, servoHandle->pos0);
	servoHandle->currentPos = 0;
}

void turnServo(h_servo_t *servoHandle) {
	if (servoHandle->currentPos == 0) {
		__HAL_TIM_SET_COMPARE(servoHandle->timer, servoHandle->timerChannel, servoHandle->pos1);
	}
	if (servoHandle->currentPos == 1) {
		__HAL_TIM_SET_COMPARE(servoHandle->timer, servoHandle->timerChannel, servoHandle->pos0);
	}
	servoHandle->currentPos = 1 - servoHandle->currentPos;
}
