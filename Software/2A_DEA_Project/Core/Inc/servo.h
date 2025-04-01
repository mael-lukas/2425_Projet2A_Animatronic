/*
 * servo.h
 *
 *  Created on: Mar 11, 2025
 *      Author: administrateur
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "main.h"

typedef struct h_servo_struct {
	TIM_HandleTypeDef *timer;
	uint32_t timerChannel;
	uint16_t pos0;
	uint16_t pos1;
	int currentPos;
} h_servo_t;

void servoInit(h_servo_t *servoHandle, TIM_HandleTypeDef *timer, uint32_t timerChannel);
void turnServo(h_servo_t *servoHandle);

#endif /* INC_SERVO_H_ */
