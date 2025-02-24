/*
 * bluetooth_protocol.c
 *
 *  Created on: Feb 24, 2025
 *      Author: administrateur
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bluetooth_protocol.h"

// returns 1 if c is in str and 0 otherwise
int isInString(char c, char* str) {
	char* currentChar = str;
	while(*currentChar != '\0') {
		if (*currentChar == c) {
			return 1;
		}
		currentChar++;
	}

	return 0;
}

// returns 1 if str represents a float and 0 otherwise
int isAFloat(char* str) {
	char* currentChar = str;
	char* numbers = "0123456789";
	int state = INTEGER_PART;

	while(*currentChar != '\0') {
		switch(state) {
		case INTEGER_PART:
			if (*currentChar == '.') {
				state = FRACTIONAL_PART;
			}
			else if (isInString(*currentChar, numbers)) {
				// it is a number, no problem, resume reading
			}
			else {
				return 0;
			}
			break;

		case FRACTIONAL_PART:
			if (isInString(*currentChar, numbers)) {
				// it is a number, no problem, resume reading
			}
			else {
				return 0;
			}
			break;
		}
		currentChar++;
	}
	return 1;
}

void printLabelValue(labelValue_t lv) {
	printf("labelValue_t structure instance. Label: %s, Value: %f", lv.label, lv.value);
}

// read instruction sent as a string and return a labelValue_struct with corresponding target label and value
labelValue_t checkInstruction(char* instruction) {
	char* i = instruction;
	char* allowedCharForLabel = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	char* allowedCharForValue = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.";
	char delimitation = '=';
	char label[100];
	char value[100];

	int labelIndex = 0;
	int valueIndex = 0;
	int state = READ_LABEL;

	while(state != END_OF_READ) {
		switch(state) {
		case READ_LABEL:
			if (*i == '\0') {
				// error case: string is not an instruction
			}
			else if (*i == delimitation) {
				state = READ_VALUE;
				label[labelIndex] = '\0'; // if '=' then the 'label' part of instruction is finished
			}
			else if (isInString(*i, allowedCharForLabel)) {
				// no problem, keep reading the label
				label[labelIndex] = *i;
				labelIndex++;
			}
			else {
				// error case: found not allowed characters in label
			}
			break;

		case READ_VALUE:
			if(*i == '\0') {
				state = END_OF_READ;
				value[valueIndex] = '\0';
			}
			else if(*i == delimitation) {
				//error case: found another '=' in value
			}
			else if (isInString(*i, allowedCharForValue)) {
				// no problem, keep reading value
				value[valueIndex] = *i;
				valueIndex++;
			}
			else {
				//error case: found not allowed characters in value
			}
			break;
		}
		i++;
	}
	if (state == END_OF_READ) {
		if (isAFloat(value)) {
			labelValue_t result;
			strcpy(result.label, label);
			result.value = strtof(value, NULL);
			return result;
		}
		else {
			labelValue_t result;
			strcpy(result.label, "LABELVALUE ERROR: VALUE FIELD IS NOT A FLOAT");
			result.value = NAN;
			return result;
		}
	}
	else {
		labelValue_t result = {
				.label = "LABELVALUE ERROR: INPUT DOES NOT FIT INSTRUCTION FORMAT",
				.value = NAN
		};
		return result;
	}
}

// read whole frame, looks for every instruction delimited by beginning and end and fills a labelValueArray_struct
// with every instruction found
labelValueArray_t checkFrameForInstructions(char* frame, char beginning, char end) {
	int i = 0; // cursor for the whole frame
	int state = SEARCH_FOR_BEGINNING;
	char instruction[200];
	int currentInstructionIndex = 0; // cursor for currently found and read instruction (inside the whole frame)
	labelValue_t instructions[100];
	int numberOfInstructions = 0;

	while (frame[i] != '\0') {
		if (state == SEARCH_FOR_BEGINNING) {
			if (frame[i] == beginning) {
				state = READING;
			}
		}
		else if (state == READING) {
			if (frame[i] == end) {
				// instruction read from beginning to end: make a labelValue_struct out of it and adds it to and array
				instruction[currentInstructionIndex] = '\0';
				currentInstructionIndex = 0;
				state = SEARCH_FOR_BEGINNING;

				labelValue_t contentsOfInstruction = checkInstruction(instruction);
				instructions[numberOfInstructions] = contentsOfInstruction;
				numberOfInstructions++;
			}
			else {
				instruction[currentInstructionIndex] = frame[i];
				currentInstructionIndex++;
			}
		}
		i++;
	}
	labelValueArray_t arrayOfInstructions;
	memcpy(arrayOfInstructions.instructions, instructions, sizeof(labelValue_t) * numberOfInstructions);
	arrayOfInstructions.n = numberOfInstructions;

	return arrayOfInstructions;
}

// changes the value of variable with name lv.label to lv.value in the dict of available variables
// returns 1 for a successful change and 0 otherwise
int applyLabelValue(labelValue_t lv, dictOfVariables_t dictOfVars) {
	 char * nameOfVariableToBeChanged = lv.label;
	 float newValue = lv.value;
	 int i = 0;

	 // searches for variable corresponding to received label
	 // strcmp return 0 if strings are the same and 1 otherwise
	 while (i < dictOfVars.n && strcmp(nameOfVariableToBeChanged, dictOfVars.variableNames[i])) {
		 i++;
	 }
	 if (i >= dictOfVars.n) {
		 // error case: found no variables with corresponding label
		 return 0;
	 }
	 else {
		 float* pointerToVariableAddress = dictOfVars.variables[i];
		 *pointerToVariableAddress = newValue;
	 }
	 return 1;
 }
