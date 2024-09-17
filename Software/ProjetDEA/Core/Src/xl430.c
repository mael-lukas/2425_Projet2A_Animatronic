/*
 * xl430.c
 *
 *  Created on: May 13, 2024
 *      Author: administrateur
 */


#include "xl430.h"

__XL430_HandleTypeDef hxl430;

const uint16_t crc_table[256] = {
				0x0000, 0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011,
				0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027, 0x0022,
				0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D, 0x8077, 0x0072,
				0x0050, 0x8055, 0x805F, 0x005A, 0x804B, 0x004E, 0x0044, 0x8041,
				0x80C3, 0x00C6, 0x00CC, 0x80C9, 0x00D8, 0x80DD, 0x80D7, 0x00D2,
				0x00F0, 0x80F5, 0x80FF, 0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1,
				0x00A0, 0x80A5, 0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1,
				0x8093, 0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082,
				0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197, 0x0192,
				0x01B0, 0x81B5, 0x81BF, 0x01BA, 0x81AB, 0x01AE, 0x01A4, 0x81A1,
				0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB, 0x01FE, 0x01F4, 0x81F1,
				0x81D3, 0x01D6, 0x01DC, 0x81D9, 0x01C8, 0x81CD, 0x81C7, 0x01C2,
				0x0140, 0x8145, 0x814F, 0x014A, 0x815B, 0x015E, 0x0154, 0x8151,
				0x8173, 0x0176, 0x017C, 0x8179, 0x0168, 0x816D, 0x8167, 0x0162,
				0x8123, 0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132,
				0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104, 0x8101,
				0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D, 0x8317, 0x0312,
				0x0330, 0x8335, 0x833F, 0x033A, 0x832B, 0x032E, 0x0324, 0x8321,
				0x0360, 0x8365, 0x836F, 0x036A, 0x837B, 0x037E, 0x0374, 0x8371,
				0x8353, 0x0356, 0x035C, 0x8359, 0x0348, 0x834D, 0x8347, 0x0342,
				0x03C0, 0x83C5, 0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1,
				0x83F3, 0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2,
				0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7, 0x03B2,
				0x0390, 0x8395, 0x839F, 0x039A, 0x838B, 0x038E, 0x0384, 0x8381,
				0x0280, 0x8285, 0x828F, 0x028A, 0x829B, 0x029E, 0x0294, 0x8291,
				0x82B3, 0x02B6, 0x02BC, 0x82B9, 0x02A8, 0x82AD, 0x82A7, 0x02A2,
				0x82E3, 0x02E6, 0x02EC, 0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2,
				0x02D0, 0x82D5, 0x82DF, 0x02DA, 0x82CB, 0x02CE, 0x02C4, 0x82C1,
				0x8243, 0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252,
				0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264, 0x8261,
				0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E, 0x0234, 0x8231,
				0x8213, 0x0216, 0x021C, 0x8219, 0x0208, 0x820D, 0x8207, 0x0202
};

const uint8_t msg_ping_correct[]="Ping request successful\r\n";
const uint8_t msg_ping_error[]="No response from ping request\r\n";
const uint8_t msg_ping_crc_error[]="Incorrect CRC in ping answer\r\n";

// passer en wheel mode pcq on tourne plus que 1 tour

void XL430_Init(__XL430_HandleTypeDef *XL430_Handle, UART_HandleTypeDef *huart, uint8_t id, uint8_t  baudrate){
	XL430_Handle->huart = huart;
	XL430_Handle->id = id;
	XL430_Handle->baudrate = baudrate;
	XL430_Handle->operating_mode = 3;
	XL430_Handle->drive_mode = 0;
	XL430_Handle->max_pos_limit = 4095;
	XL430_Handle->min_pos_limit = 0;
	XL430_Handle->velocity_limit = 1023;
	// Set in RX mode
	XL430_Set_UART_RxTxMode(XL430_Handle, XL430_UART_RX);
}

void XL430_Init_debug(__XL430_HandleTypeDef *XL430_Handle, UART_HandleTypeDef *huart, UART_HandleTypeDef *huart_debug, uint8_t id, uint8_t baudrate){
	XL430_Handle->huart = huart;
	XL430_Handle->huart_debug = huart_debug;
	XL430_Handle->id = id;
	XL430_Handle->baudrate = baudrate;
	XL430_Handle->operating_mode = 3;
	XL430_Handle->drive_mode = 0;
	XL430_Handle->max_pos_limit = 4095;
	XL430_Handle->min_pos_limit = 0;
	XL430_Handle->velocity_limit = 1023;
	// Set in RX mode
	XL430_Set_UART_RxTxMode(XL430_Handle, XL430_UART_RX);
}

HAL_StatusTypeDef XL430_Ping(__XL430_HandleTypeDef *XL430_Handle){
	// Header & Reserved
	XL430_Handle->tx_buffer[0] = XL430_HEADER_1;
	XL430_Handle->tx_buffer[1] = XL430_HEADER_2;
	XL430_Handle->tx_buffer[2] = XL430_HEADER_3;
	XL430_Handle->tx_buffer[3] = XL430_RSVD;
	// ID
	XL430_Handle->tx_buffer[4] = XL430_Handle->id;
	// Length (Nb param + Instru + CRC)
	XL430_Handle->tx_buffer[5] = 0x03;   // Low
	XL430_Handle->tx_buffer[6] = 0x00;   // High
	// Instruction : ping
	XL430_Handle->tx_buffer[7] = XL430_INST_PING;

	XL430_Handle->tx_data_length = 8;

	// CRC
	XL430_Update_CRC(XL430_Handle);
	XL430_Handle->tx_buffer[8] = (XL430_Handle->crc) & 0x00FF;
	XL430_Handle->tx_buffer[9] = (XL430_Handle->crc >> 8) & 0x00FF;

	XL430_Set_UART_RxTxMode(XL430_Handle, XL430_UART_TX);
	HAL_UART_Transmit(XL430_Handle->huart, XL430_Handle->tx_buffer,  XL430_Handle->tx_data_length + XL430_CRC_LENGTH, 10);
	XL430_Set_UART_RxTxMode(XL430_Handle, XL430_UART_RX);

	if(HAL_ERROR == HAL_UART_Receive(XL430_Handle->huart, XL430_Handle->rx_buffer, 14, 10)){
		HAL_UART_Transmit(XL430_Handle->huart_debug, msg_ping_error, sizeof(msg_ping_error), 10);
		return HAL_ERROR;
	}

	XL430_Handle->rx_data_length = XL430_Handle->rx_buffer[5]+(XL430_Handle->rx_buffer[6] << 8);

	if(XL430_Check_CRC(XL430_Handle) == HAL_ERROR){
		HAL_UART_Transmit(XL430_Handle->huart_debug, msg_ping_crc_error, sizeof(msg_ping_crc_error), 10);
		return HAL_ERROR;
	}
	HAL_UART_Transmit(XL430_Handle->huart_debug, msg_ping_correct, sizeof(msg_ping_correct), 10);

	XL430_Handle->error_code = XL430_Handle->rx_buffer[8]; // ERR Code
	XL430_Handle->model_number = XL430_Handle->rx_buffer[9] + (XL430_Handle->rx_buffer[10]<<8);
	XL430_Handle->firmware_version = XL430_Handle->rx_buffer[11];

	XL430_Handle->tx_data_debug_length = snprintf(XL430_Handle->tx_buffer_debug, MAX_BUFFER_DEBUG_LENGTH,
				"Model number :     %d \r\n"
				"Firmware version : %d \r\n"
				"Error code :       %d \r\n"
				"ID :               %d \r\n",
				XL430_Handle->model_number, XL430_Handle->firmware_version, XL430_Handle->error_code, XL430_Handle->id);
	HAL_UART_Transmit(XL430_Handle->huart_debug, XL430_Handle->tx_buffer_debug, XL430_Handle->tx_data_debug_length, 10);

	return HAL_OK;
}

void XL430_Set_UART_RxTxMode(__XL430_HandleTypeDef *XL430_Handle, int mode){
	if(mode==0){
		HAL_StatusTypeDef status = HAL_HalfDuplex_EnableReceiver(XL430_Handle->huart);
	}
	if(mode==1){
		HAL_StatusTypeDef status = HAL_HalfDuplex_EnableTransmitter(XL430_Handle->huart);
	}
}

void XL430_Write_Data(__XL430_HandleTypeDef *XL430_Handle, uint16_t Address, uint16_t Value){
	// Header + reserved
	XL430_Handle->tx_buffer[0] = XL430_HEADER_1;
	XL430_Handle->tx_buffer[1] = XL430_HEADER_2;
	XL430_Handle->tx_buffer[2] = XL430_HEADER_3;
	XL430_Handle->tx_buffer[3] = XL430_RSVD;
	// ID
	XL430_Handle->tx_buffer[4] = XL430_Handle->id;
	// Length (Nb param + Instru + CRC)
	XL430_Handle->tx_buffer[5] = 0x07;   // Length (Low)
	XL430_Handle->tx_buffer[6] = 0x00;   // Length (High)
	// Instruction : write
	XL430_Handle->tx_buffer[7] = XL430_INST_WRITE_DATA;
	// Register Address
	XL430_Handle->tx_buffer[8] = Address & 0x00FF;			// Addr (Low)
	XL430_Handle->tx_buffer[9] = (Address >> 8) & 0x00FF;	// Addr (High)
	// Register Value
	XL430_Handle->tx_buffer[10] = Value & 0x00FF;			// Val (Low)
	XL430_Handle->tx_buffer[11] = (Value >> 8) & 0x00FF;	// Val (High)

	XL430_Handle->tx_data_length = 12;

	// CRC
	XL430_Update_CRC(XL430_Handle);
	XL430_Handle->tx_buffer[12] = (XL430_Handle->crc) & 0x00FF;
	XL430_Handle->tx_buffer[13] = (XL430_Handle->crc >> 8) & 0x00FF;

	XL430_Set_UART_RxTxMode(XL430_Handle, XL430_UART_TX);
	HAL_UART_Transmit(XL430_Handle->huart, XL430_Handle->tx_buffer, XL430_Handle->tx_data_length + XL430_CRC_LENGTH, 10);
	XL430_Set_UART_RxTxMode(XL430_Handle, XL430_UART_RX);
}

void XL430_Set_Position(__XL430_HandleTypeDef *XL430_Handle, uint16_t position){ //
	position = (position < XL430_Handle->max_pos_limit)?position:XL430_Handle->max_pos_limit;
	position = (position > XL430_Handle->min_pos_limit)?position:XL430_Handle->min_pos_limit;
	XL430_Write_Data(XL430_Handle, XL430_REG_GOAL_POS, position);
}

void XL430_Set_Speed(__XL430_HandleTypeDef *XL430_Handle, uint16_t speed){ //vérifier qu'on est en wheel mode avant de changer la vitesse
	speed = (speed < XL430_Handle->velocity_limit)?speed:XL430_Handle->velocity_limit;
	speed = (speed > (-1*XL430_Handle->velocity_limit))?speed:(-1*XL430_Handle->velocity_limit);
	XL430_Write_Data(XL430_Handle, XL430_REG_GOAL_VELOCITY, speed);
}

void XL430_Set_Operating_Mode(__XL430_HandleTypeDef *XL430_Handle, uint16_t operating_mode){
	if(operating_mode == XL430_VELOCITY_CONTROL_MODE) XL430_Write_Data(XL430_Handle, XL430_REG_OPERATING_MODE, XL430_VELOCITY_CONTROL_MODE);
	if(operating_mode == XL430_POS_CONTROL_MODE) XL430_Write_Data(XL430_Handle, XL430_REG_OPERATING_MODE, XL430_POS_CONTROL_MODE);
	if(operating_mode == XL430_EXTENDED_POS_CONTROL_MODE) XL430_Write_Data(XL430_Handle, XL430_REG_OPERATING_MODE, XL430_EXTENDED_POS_CONTROL_MODE);
	if(operating_mode == XL430_PWM_CONTROL_MODE) XL430_Write_Data(XL430_Handle, XL430_REG_OPERATING_MODE, XL430_PWM_CONTROL_MODE);
}

void XL430_Set_Profile_Speed(__XL430_HandleTypeDef *XL430_Handle, uint16_t profile_speed){
	profile_speed = (profile_speed < 32767)?profile_speed:32767;
	profile_speed = (profile_speed > 0)?profile_speed:0;
	XL430_Write_Data(XL430_Handle, XL430_REG_PROFILE_VELOCITY, profile_speed);
}

void XL430_Set_Profile_Accel(__XL430_HandleTypeDef *XL430_Handle, uint16_t profile_accel){
	profile_accel = (profile_accel < 32767)?profile_accel:32767;
	profile_accel = (profile_accel > 0)?profile_accel:0;
	XL430_Write_Data(XL430_Handle, XL430_REG_PROFILE_ACCEL, profile_accel);
}

void XL430_Led_OnOff(__XL430_HandleTypeDef *XL430_Handle, uint16_t state){
	XL430_Write_Data(XL430_Handle, XL430_REG_LED, state);
}

void XL430_Update_CRC(__XL430_HandleTypeDef *XL430_Handle){
	uint16_t i,j;
	uint16_t crc_accum = 0;

	for(j=0; j<XL430_Handle->tx_data_length; j++){
		i = ((uint16_t)(crc_accum >> 8) ^ XL430_Handle->tx_buffer[j]) & 0xFF;
		crc_accum = (crc_accum << 8) ^ crc_table[i];
	}
	XL430_Handle->crc = crc_accum;
}

HAL_StatusTypeDef XL430_Check_CRC(__XL430_HandleTypeDef *XL430_Handle){
	uint16_t i,j;
	uint16_t crc_accum = 0;
	uint16_t crc_read = XL430_Handle->rx_buffer[XL430_Handle->rx_data_length+5] + (((uint16_t)XL430_Handle->rx_buffer[XL430_Handle->rx_data_length+6]) << 8);

	for(j=0; j<XL430_Handle->rx_data_length+5; j++){
		i = ((uint16_t)(crc_accum >> 8) ^ XL430_Handle->rx_buffer[j]) & 0xFF;
		crc_accum = (crc_accum << 8) ^ crc_table[i];
	}
	if(crc_accum == crc_read) return HAL_OK;
	else return HAL_ERROR;
}
