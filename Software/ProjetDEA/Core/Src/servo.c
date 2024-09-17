/*
 * servo.c
 *
 *  Created on: May 13, 2024
 *      Author: administrateur
 */

#include "servo.h"

void servoInit(__Servo_HandleTypeDef *Servo_Handle, GPIO_TypeDef *btn_port, uint16_t btn_pin, TIM_HandleTypeDef *timer, uint32_t timer_channel){
	Servo_Handle->btn_port = btn_port;
	Servo_Handle->btn_pin = btn_pin;
	Servo_Handle->timer = timer;
	Servo_Handle->timer_channel = timer_channel;
	__HAL_TIM_SET_COMPARE(Servo_Handle->timer, Servo_Handle->timer_channel, NOT_TURNED);
	Servo_Handle->is_turned = 0;
}

int btnPressed(void){
	int btnNumber = 0;
	if (HAL_GPIO_ReadPin(GPIOB, BTN_1_Pin) == 0) btnNumber = 1;
	if (HAL_GPIO_ReadPin(GPIOB, BTN_2_Pin) == 0) btnNumber = 2;
	if (HAL_GPIO_ReadPin(GPIOA, BTN_3_Pin) == 0) btnNumber = 3;
	if (HAL_GPIO_ReadPin(GPIOA, BTN_4_Pin) == 0) btnNumber = 4;
	if (HAL_GPIO_ReadPin(GPIOA, BTN_5_Pin) == 0) btnNumber = 5;
	//if (HAL_GPIO_ReadPin(GPIOA, BTN_6_M_Pin) == 0) btnNumber = 6;
	//if (HAL_GPIO_ReadPin(GPIOA, BTN_7_M_Pin) == 0) btnNumber = 7;
	return btnNumber;
}

void turnServo(__Servo_HandleTypeDef *Servo_Handle){
	if(Servo_Handle->is_turned == 0){
		__HAL_TIM_SET_COMPARE(Servo_Handle->timer, Servo_Handle->timer_channel, TURNED);
		Servo_Handle->is_turned = 1;
		HAL_Delay(250);
	}
	else{
		__HAL_TIM_SET_COMPARE(Servo_Handle->timer, Servo_Handle->timer_channel, NOT_TURNED);
		Servo_Handle->is_turned = 0;
		HAL_Delay(250);
	}
}
