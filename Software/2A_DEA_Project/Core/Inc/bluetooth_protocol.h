/*
 * bluetooth_protocol.h
 *
 *  Created on: Feb 24, 2025
 *      Author: administrateur
 */

#ifndef INC_BLUETOOTH_PROTOCOL_H_
#define INC_BLUETOOTH_PROTOCOL_H_

#define INTEGER_PART 0
#define FRACTIONAL_PART 1

#define READ_LABEL 0
#define READ_VALUE 1
#define END_OF_READ 2

#define SEARCH_FOR_BEGINNING 0
#define READING 1

typedef struct labelValue_struct {
	char label[100];
	float value;
} labelValue_t;

typedef struct labelValueArray_struct {
	labelValue_t instructions[100];
	int n;
} labelValueArray_t;

typedef struct dictOfVariables_struct {
	int n;
	char** variableNames;
	float** variables;
} dictOfVariables_t;

int isInString(char c, char* str);
int isAFloat(char* str);
void printLabelValue(labelValue_t lv);
labelValue_t checkInstruction(char* instruction);
labelValueArray_t checkFrameForInstructions(char* frame, char beginning, char end);
int applyLabelValue(labelValue_t lv, dictOfVariables_t dictOfVars);

#endif /* INC_BLUETOOTH_PROTOCOL_H_ */
