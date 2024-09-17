/*
 * xl430.h
 *
 *  Created on: May 13, 2024
 *      Author: administrateur
 */

#ifndef INC_XL430_H_
#define INC_XL430_H_

#include "main.h"

/////// EEPROM Control Table ///////
#define XL430_REG_MODEL_NUMBER            	0
#define XL430_REG_MODEL_INFO				2
#define XL430_REG_VERSION                 	6
#define XL430_REG_XL_ID                   	7
#define XL430_REG_BAUD_RATE               	8	//valeurs sur la docu
#define XL430_REG_RETURN_DELAY_TIME       	9
#define XL430_REG_DRIVE_MODE				10  //spécifications sur la docu
#define XL430_REG_OPERATING_MODE			11
#define XL430_REG_SHADOW_ID					12
#define XL430_REG_PROTOCOL_TYPE				13
#define XL430_REG_HOMING_OFFSET				20
#define XL430_REG_MOVING_THRESHOLD			24
#define XL430_REG_LIMIT_TEMPERATURE       	31
#define XL430_REG_UPPER_LIMIT_VOLTAGE     	32
#define XL430_REG_LOWER_LIMIT_VOLTAGE     	34
#define XL430_REG_LIMIT_PWM					36
#define XL430_REG_LIMIT_VELOCITY			44
#define XL430_REG_UPPER_LIMIT_POS     		48
#define XL430_REG_LOWER_LIMIT_POS	     	52
#define XL430_REG_STARTUP_CONFIG           	60
#define XL430_REG_ALARM_SHUTDOWN          	63

/////// RAM Control Table ///////
#define XL430_REG_TORQUE_ENABLE           	64
#define XL430_REG_LED                     	65
#define XL430_REG_RETURN_LEVEL            	68
#define XL430_REG_REGISTERED_INSTRUCTION	69
#define XL430_REG_HARDWARE_ERROR_STATUS		70
#define XL430_REG_VELOCITY_I_GAIN         	76
#define XL430_REG_VELOCITY_P_GAIN          	78
#define XL430_REG_POS_D_GAIN                80
#define XL430_REG_POS_I_GAIN         		82
#define XL430_REG_POS_P_GAIN          		84
#define XL430_REG_FEEDFWD_GAIN2				88
#define XL430_REG_FEEDFWD_GAIN1          	90
#define XL430_REG_BUS_WATCHDOG				98
#define XL430_REG_GOAL_PWM              	100
#define XL430_REG_GOAL_VELOCITY            	104
#define XL430_REG_PROFILE_ACCEL				108
#define XL430_REG_PROFILE_VELOCITY			112
#define XL430_REG_GOAL_POS					116
#define XL430_REG_REALTIME_TICK				120
#define XL430_REG_MOVING                  	122
#define XL430_REG_MOVING_STATUS            	123
#define XL430_REG_PRESENT_PWM				124
#define XL430_REG_PRESENT_LOAD            	126
#define XL430_REG_PRESENT_VELOCITY         	128
#define XL430_REG_PRESENT_POSITION        	132
#define XL430_REG_VELOCITY_TRAJECTORY		136
#define XL430_REG_POS_TRAJECTORY			140
#define XL430_REG_PRESENT_VOLTAGE         	144
#define XL430_REG_PRESENT_TEMPERATURE     	146
#define XL430_REG_BACKUP_READY             	147

/////// Instructions ///////
#define XL430_INST_PING                    	1
#define XL430_INST_READ_DATA               	2
#define XL430_INST_WRITE_DATA              	3
#define XL430_INST_REG_WRITE               	4
#define XL430_INST_ACTION                  	5
#define XL430_INST_FACTORY_RESET           	6
#define XL430_INST_REBOOT                  	8
#define XL430_INST_STATUS                  	85
#define XL430_INST_SYNC_READ               	130
#define XL430_INST_SYNC_WRITE              	131
#define XL430_INST_BULK_READ               	146
#define XL430_INST_BULK_WRITE       		147

/////// Headers ///////
#define XL430_HEADER_1						0xFF
#define XL430_HEADER_2						0xFF
#define XL430_HEADER_3						0xFD
#define XL430_RSVD							0x00

/////// Errors ///////
#define ERROR_RESULT						0x01
#define ERROR_INSTR							0x02
#define ERROR_CRC							0x03
#define ERROR_DATA_RANGE					0x04
#define ERROR_DATA_LENGTH					0x05
#define ERROR_DATA_LIMIT					0x06
#define ERROR_ACCESS						0x07

/////// Operating mode ///////
#define XL430_VELOCITY_CONTROL_MODE			1
#define XL430_POS_CONTROL_MODE				3
#define XL430_EXTENDED_POS_CONTROL_MODE		4
#define XL430_PWM_CONTROL_MODE				16

/////// LED ///////
#define XL430_LED_OFF						0
#define XL430_LED_ON						1

/////// XL430 RX-TX///////
#define XL430_UART_RX						0
#define XL430_UART_TX						1

#define XL430_CRC_LENGTH					2
#define MAX_BUFFER_LENGTH					64
#define MAX_BUFFER_DEBUG_LENGTH				256

typedef struct __XL430_HandleTypeDef
{											// Default	Min 	Max
	UART_HandleTypeDef *huart;
	UART_HandleTypeDef *huart_debug;
	uint16_t model_number;					// 1060
	uint32_t model_information;				// -
	uint8_t firmware_version;				// -
	uint8_t error_code;
	uint8_t id;								// 1		0		252
	uint8_t baudrate;						// 1		0		7
	uint8_t	return_delay_time;				// 250		0		254
	uint8_t drive_mode;						// 0        0       5
	uint8_t operating_mode;					// 3		0		16
	uint8_t shadow_id;						// 255		0		252
	uint8_t protocol_type;					// 2        1       2
	uint32_t homing_offset;					// 0		-1044479      1044479
	uint32_t moving_threshold;				// 10       0		1023
	uint8_t temperature_limit;				// 72		0		100
	uint16_t max_voltage_limit;				// 140		60		140
	uint16_t min_voltage_limit;				// 60		60		140
	uint16_t pwm_limit;						// 885		0		885
	uint32_t velocity_limit;				// 265		0		1023
	uint32_t max_pos_limit;					// 4095		0		4095
	uint32_t min_pos_limit;					// 0		0		4095
	uint8_t startup_configuration;			// 0		0		3
	uint8_t shutdown_error_information;		// 52
	uint8_t torque_enable;					// 0		0		1
	uint8_t led;							// 0		0		1
	uint8_t status_return_level;			// 2		0		2
	uint8_t registered_instr;				// 0		0		1
	uint8_t hardware_error_status;			// 0
	uint16_t velocity_I_Gain;				// 1000		0		16383
	uint16_t velocity_P_Gain;				// 100		0		16383
	uint16_t pos_D_Gain;					// 4000		0		16383
	uint16_t pos_I_Gain;					// 0		0		16383
	uint16_t pos_P_Gain;					// 640		0		16383
	uint16_t feedforward_snd_gain;			// 0		0		16383
	uint16_t feedforward_fst_gain;			// 0		0		16383
	uint8_t bus_watchdog;					// 0		1		127
	uint16_t goal_pwm;						// -
	uint32_t goal_velocity;					// -
	uint32_t profile_acceleration;			// 0		0		32767 (rpm²)
	uint32_t profile_velocity;				// 0		0		32767
	uint32_t goal_position;					// -
	uint16_t realtime_tick;					// -		0		32767
	uint8_t is_moving;						// 0		0		1
	uint8_t moving_status;					// 0
	uint16_t present_pwm;					// -
	uint16_t present_load;					// -		-1000	1000
	uint32_t present_velocity;				// -
	uint32_t present_position;				// -
	uint32_t velocity_trajectory;			// -
	uint32_t position_trajectory;			// -
	uint16_t present_input_voltage;			// -
	uint8_t present_temperature;			// -
	uint8_t backup_ready;					// -		0		1
	uint16_t crc;
	uint8_t tx_buffer[MAX_BUFFER_LENGTH];
	uint8_t tx_data_length;
	uint8_t rx_buffer[MAX_BUFFER_LENGTH];
	uint8_t rx_data_length;
	uint8_t tx_buffer_debug[MAX_BUFFER_DEBUG_LENGTH];
	uint8_t tx_data_debug_length;
} __XL430_HandleTypeDef;

extern __XL430_HandleTypeDef hxl430;

void XL430_Init(__XL430_HandleTypeDef *XL430_Handle, UART_HandleTypeDef *huart, uint8_t id, uint8_t baudrate);
void XL430_Init_debug(__XL430_HandleTypeDef *XL430_Handle, UART_HandleTypeDef *huart, UART_HandleTypeDef *huart_debug, uint8_t id, uint8_t baudrate);
HAL_StatusTypeDef XL430_Ping(__XL430_HandleTypeDef *XL430_Handle);
void XL430_Set_UART_RxTxMode(__XL430_HandleTypeDef *XL430_Handle, int mode);
void XL430_Write_Data(__XL430_HandleTypeDef *XL430_Handle, uint16_t Address, uint16_t Value);
//void XL430_ReadData(__XL430_HandleTypeDef *XL430_Handle);
void XL430_Set_Position(__XL430_HandleTypeDef *XL430_Handle, uint16_t position);
void XL430_Set_Speed(__XL430_HandleTypeDef *XL430_Handle, uint16_t speed);
void XL430_Set_Operating_Mode(__XL430_HandleTypeDef *XL430_Handle, uint16_t operating_mode);
void XL430_Set_Profile_Speed(__XL430_HandleTypeDef *XL430_Handle, uint16_t profile_speed);
void XL430_Set_Profile_Accel(__XL430_HandleTypeDef *XL430_Handle, uint16_t profile_accel);
void XL430_Led_OnOff(__XL430_HandleTypeDef *XL430_Handle, uint16_t state);
//void XL430_Set_ID(__XL430_HandleTypeDef *XL430_Handle, uint8_t ID);
//void XL430_Set_Baudrate(__XL430_HandleTypeDef *XL430_Handle, uint8_t baudrate);
void XL430_Update_CRC(__XL430_HandleTypeDef *XL430_Handle);
HAL_StatusTypeDef XL430_Check_CRC(__XL430_HandleTypeDef *XL430_Handle);


#endif /* INC_XL430_H_ */
