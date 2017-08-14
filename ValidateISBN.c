/*
 * ValidateISBN.c
 *
 *  Created on: 22-Jul-2017
 *      Author: Pratibhasagar
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SZ	20
#define ISBN_SZ			13

/*
 * Clears the formatting (if any) like spaces or hyphen
 */
void unformatISBN(char str[], int isbn[]) {

	int i = 0, j = 0;

	for (; i < strlen(str); i++){
		if( str[i] == 45 || str[i] == 32)
			continue;
		else
			isbn[j++] = str[i] - 48;
	}
}

/*
 * Generates the check digit for the provided ISBN
 * and prints out the result for ISBN's validity
 */
void checkISBNIsValid(int isbn[const]) {

	int i = 0, chkDgt = 0, sum = 0;

	for (i = 0; i < 12; i++) {
		if ( i % 2) {
			sum += ( isbn[i] * 3);
		} else {
			sum += isbn[i];
		}
	}
	sum %= 10;
	chkDgt = 10 - sum;
	chkDgt %= 10;
	if (chkDgt == isbn[12])
		printf("The entered ISBN is valid.\n");
	else
		printf("The entered ISBN is invalid.\n");
}

int main(void) {

	setvbuf(stdout, NULL, _IONBF, 0);

	char strPtr[MAX_INPUT_SZ];
	int unformattedISBN[ISBN_SZ] = {0};

	printf("Given an ISBN, the program would verify if it is valid.\n");
	printf("Enter X to quit.\n");

	printf("Kindly enter the ISBN : ");
	if (scanf("%20[0-9 -^\n]", strPtr) != 1 ) {
		goto out;
	} else if (strlen(strPtr) > (MAX_INPUT_SZ - 1)) {
		printf("String longer than 20 characters. Try again.");
		goto out;
	} else if (strlen(strPtr) < ISBN_SZ) {
		printf("ISBN length is less than 13 characters. Try again.");
		goto out;
	}
	// Remove the formatting
	unformatISBN(strPtr, unformattedISBN);

	// Validate the ISBN
	checkISBNIsValid(unformattedISBN);
	out:
	return EXIT_SUCCESS;
}
