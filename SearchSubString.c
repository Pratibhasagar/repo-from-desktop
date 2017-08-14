/*
 * SearchSubString.c
 *
 *  Created on: 28-Jul-2017
 *      Author: Pratibhasagar V.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INPUT_SZ	20

void searchSubString(char str[], char output[]) {
	int size = strlen(str);
	int midLen = size/2;
	int i , j, middle = midLen, count = 0;

	for(i = 0, j = middle; i < midLen && j<size; j++){
		if(str[i] == str[j]){
			output[count] = str[i];
			count++;
			i++;
		} else {
			if(i > 0 && str[i-1] != str[j]){
				count = 0;
				i = 0;
				memset(output,0,strlen(output));;
			}
		}
	}
}

int main(void){

	char inputStr[INPUT_SZ] = "";
	char str[INPUT_SZ / 2] = "";

	setvbuf(stdout, NULL, _IONBF, 0);

	printf("Given a string the program would return the longest substring that appears " \
			"at both the beginning and end of the string without overlapping.\n" \
			"Enter 0 (i.e. zero) to exit.\n");

	printf("\nEnter a string : ");
	scanf("%s", inputStr);

	while (!isdigit(inputStr[0])) {

		if (strlen(inputStr) > (INPUT_SZ - 1)) {
			printf("String longer than 20 characters. Try again.");
			printf("\nEnter a string : ");
			memset(inputStr,0,strlen(inputStr));
			memset(str,0,strlen(str));
			scanf("%s", inputStr);
		}
		searchSubString(inputStr, str);
		printf("The longest substring is %s", str);
		// Reset for reEntry
		memset(inputStr,0,strlen(inputStr));
		memset(str,0,strlen(str));
		printf("\nEnter a string : ");
		scanf("%s", inputStr);
	}
	return EXIT_SUCCESS;
}
