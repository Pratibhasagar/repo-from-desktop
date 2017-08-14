/*
 * SpellNumber.c
 *
 *  Created on: 27-Jul-2017
 *      Author: Pratibhasagar V.
 */

#include <stdio.h>
#include <stdlib.h>

#define SETDIVIDER 1000

const char *ones[20] = { "", "one", "two", "three", "four", "five", "six",
		"seven", "eight", "nine", "ten", "eleven", "twelve",
		"thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
		"eighteen", "nineteen" };

const char *tens[10] = { "", "", "twenty", "thirty", "forty", "fifty",
		"sixty", "seventy", "eighty", "ninety" };
		
int numPresentBefore=0;

/*
 * Spells a numeric set of 3 digits
 */
int spellNumberSet(int const num){

	int dupNum = num, digit = 0, result = 0;

	// Extract hundredth digit
	digit = dupNum / 100;
	if (digit) {
		if(numPresentBefore){
			printf(", ");
		}
		printf("%s hundred", ones[digit]);
		result = 1;
	}

	dupNum = num % 100;

	int alreadyAnd=0;
	// Extract tens' digit
	digit = dupNum / 10;
	if (digit) {
		if (result) {
			printf(" and ");
			 alreadyAnd=1;
		}
		// For twenty onwards
		if (digit > 1) {
			if(!result && numPresentBefore){
				printf(", ");
			}
			printf ("%s", tens[digit]);
			result = 0;
		} else if (digit == 1) {
			if(!result && numPresentBefore){
				printf(", ");
			}
			// For handling the range of 11 to 19
			printf ("%s", ones[dupNum]);		
			result = 1;			
			goto out;
		}else{
			result = 1;
		}
	}

	// Extract ones' digit
	digit = dupNum % 10;
	if (digit) {
		if (! alreadyAnd && (result || numPresentBefore)) {
			printf(" and");
		}
		printf (" %s", ones[digit]);
		result = 1;
	}
out:
	return result;
}

int main(void) {

	// Input as entered by user
	int inputNum = 0;
	/*
	 * Each number would be divided in sets of 3 digits.
	 * Eg. 123456789 = {123} {456} {789}
	 * And named respectively as setMillion, setThousand, setHundred
	 */
	int setMiln = 0 , setThou = 0, setHund = 0;

	setvbuf(stdout, NULL, _IONBF, 0);

	printf("This program would spell a number of 9 digits.\n");
	printf("Enter number '-1' to exit.");

	printf("\nEnter the number : ");
	scanf("%d", &inputNum);

	while (inputNum > 0) {
		if (inputNum / (SETDIVIDER * SETDIVIDER * SETDIVIDER)) {
			printf("Number exceeds 9 digits. Try again.");
			printf("\nEnter the number : ");
			scanf("%d", &inputNum);
		}

		setHund = inputNum % SETDIVIDER; inputNum /= SETDIVIDER;
		setThou = inputNum % SETDIVIDER; inputNum /= SETDIVIDER;
		setMiln = inputNum % SETDIVIDER; inputNum /= SETDIVIDER;

		numPresentBefore=0;
		if (spellNumberSet(setMiln)){
			printf(" million");
			numPresentBefore=1;
		}
		if (spellNumberSet(setThou)) {
			printf(" thousand");
			numPresentBefore=1;
		}
		spellNumberSet(setHund);

		printf("\nEnter the number : ");
		scanf("%d", &inputNum);
	}
	return EXIT_SUCCESS;
}
