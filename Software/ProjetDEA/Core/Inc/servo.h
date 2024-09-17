/*
 * servo.h
 *
 *  Created on: May 13, 2024
 *      Author: administrateur
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "main.h"

#define NOT_TURNED 250
#define TURNED 1250

typedef struct __Servo_HandleTypeDef
{
	GPIO_TypeDef *btn_port;
	uint16_t btn_pin;
	TIM_HandleTypeDef *timer;
	uint32_t timer_channel;
	uint8_t is_turned;
} __Servo_HandleTypeDef;

void servoInit(__Servo_HandleTypeDef *Servo_Handle, GPIO_TypeDef *btn_port, uint16_t btn_pin, TIM_HandleTypeDef *timer, uint32_t timer_channel);
int btnPressed(void);
void turnServo(__Servo_HandleTypeDef *Servo_Handle);

#endif /* INC_SERVO_H_ */
