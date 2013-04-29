/*
 Author: Kamal Chaya
 Filename: ItoA.c
 Date DUE: 4.21.2013
 Description: Converts an int to a string without
 any predef. functions.
 Input: The number the user wants to convert to 
 a string.
 Output: The number in string form.
*/


#include <stdio.h>
#include <stdlib.h> /*malloc, */

//Macros (boolean's cant be used in C).
#define TRUE 1
#define FALSE 0

void determineDigits (int n, int * numDigits, int base);
void myItoA (int n, int base, char * str);
void revCstr (char str[], int numDigits);

int main() {
	int redo = TRUE, numDigits = 0;
	while (redo == TRUE) {
		int n, base;

		//Prompt the user to enter the base
		printf("Enter the base you want the number to be in as a Cstring.\n");
		printf("Binary, hex, octal, and decimal are supported.\n");
		scanf(" %d", &base);
	
		//Prompt the user to enter the int to convert.
		printf("Enter the integer you want to convert to a Cstring.\n");
		printf("--PLEASE DO NOT ENTER ANY LEADING ZEROS--\n");
		printf("--NEGATIVE NUMBERS ONLY PERMITTED FOR BASE 10--\n");
		scanf(" %i", &n);

		//Call the function to determine the number of digits in the number. 
		/*
		IN order to make a dynamic array of the appropriate size, we need to
		know how many digits the number has.
		*/
		determineDigits(n, &numDigits, base);

		//Make a pointer to a char; needed to malloc our array.
		char * str;

		//Create the dynamic array.
		if (n >= 0)
			str = (char*) malloc(sizeof(int) * (numDigits + 1));

		/*
		 If the number is negative, the array needs to be able to 
		 store 1 extra element because of the negative sign.
		*/
		else
			str = (char*) malloc(sizeof(int) * (numDigits + 2));

		//Call the itoa function we made to convert the int to a C string.
		myItoA(n, base, str);
		
		//Call the function to reverse the C string.
		revCstr(str, numDigits);

		/*
		 Display C string: (if positive)
			-we do not want to display the null char, so we start at index = 1.
		 */
		int i = 0;
		printf("Converted C string:\n");

		if (n > 0) {
			for (i = 1; i <= numDigits; i++) {
				printf("%c", str[i]);

				if (i == numDigits)
					printf("\n");
			}
		}

		/*If negative, we start at index=0 to print the negative sign.
		  It should be noted that we only display the negative sign
		  when in base 10. 
		 */
		else if ((n < 0) && (base == 10)) {
			for (i = 0; i <= numDigits; i++) {
				printf("%c", str[i]);

				if (i == numDigits)
					printf("\n");
			}
		}


		//free the memory allocated by malloc.
		free(str);

		//Ask user for redo
		while (1) {
			char yOrN = 'y';
			printf("Do you want to convert another int? (y/n)\n");
			scanf(" %c", &yOrN);

			if (yOrN == 'y') {
				redo = TRUE;
				break;
			}

			else if (yOrN == 'n') {
				redo = FALSE;
				break;
			}

			else 
				printf("You did not enter a valid char; please re-enter.\n");
		}
	}
	return 0;
}

/*
 Function: void determineDigits ()
 Parameters:
	-int n (the integer that we want to calculate the # of digits for).
	-int *numDigits (pointer to the var that will hold the # of digits).
 Description: Calculates the number of digits for a integer.
	 The variable which holds the number of digits is passed by pointer.
 Pre Conditions: None
 Post Conditions: None
 */
void determineDigits (int n, int *numDigits, int base) {
	if (n < 0)
		n = -n;

	(*numDigits) = 0;
	while (n > 0) {
		n /= base;
		(*numDigits)++;
	}
}

/*
 Function: myItoA ();
 Description: Converts a integer to a Cstring.
 Parameters:
	-int n (number to convert to a Cstring)
	-base (the base the number is in)
	-char* s[] (pointer to the array which holds the Cstring)
 PreConditions: 
	-The dynamic char array to store the Cstring has already been created.
 PostConditions:
	-None
 */
void myItoA (int n, int base, char * str) {
	int signOfN = n;
	if (signOfN < 0)
		n = -n; //make the number positive if it is negative.

	/*
	 We need to calculate the # of digits AGAIN as I am not allowed
	 to pass in an int to this function w/ the number of digits
	 from the determineDigits function.
	 The first time we calculated the # of digits, that was simply
	 so that we could malloc an array of the correct size.
	 */
	//Make a copy of n (called x) so that we dont divide n yet.
	int x = n, length = 0, i = 0;

	while (x > 0) {
		x /= base;
		length++;
	}

	if ((base == 10) && (signOfN < 0)) {
		while (i < length) {
			str[i] = "0123456789abcdef"[n % base];
			n /= base;
			i++;
		}
	}

	else {
		while (i <= length) {
			str[i] = "0123456789abcdef"[n % base];
			n /= base;
			i++;
		}
	}

	//If it is a decimal number and negative, put a negative sign infront.
	if ((signOfN < 0) && (base == 10)) {
		str[i] = '-';
		i++;
	}

	str[i++] = '\0';
}

/*
 Function: revCstr()
 Description: Reverses the C string.
 Parameters: 
	-char str[] (the C string to reverse)
	-int numDigits (the # of characters in the array; used to
	 get the length of the c string).
 PreConditions: We have determined the # of digits 
 with the determineDigits function.
 PostConditions: None
 */
void revCstr (char str[], int numDigits) {
	char temp;
	int i, j;

	for (i = 0, j = numDigits; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}





