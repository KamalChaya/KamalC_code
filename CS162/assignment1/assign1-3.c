/**********************************************************
 ** Filename: assign1-3.c
 ** Author: Kamal Chaya
 ** Date: DUE 4.13.2013
 ** Description: Finds the sum of all the multiples
of 3 and 5 below 1000 (makes a function to
return this value).
 ** Input: None
 ** Output: The sum of all the multiples of 3 & 5 below
1000.
 *********************************************************/

#include <stdio.h>

unsigned int multipleSum();

int main() {
	printf("Sum: %d \n", multipleSum());
	
	return 0;
}

/***************************************************
 ** Function: multipleSum()
 ** Description: Finds the sum of all the multiples
of 3 and 5 below 1000, returns the value.
 ** Parameters: None
 ** Pre Conditions: None
 ** Post Conditions: None
 **************************************************/
unsigned  int multipleSum() {
    unsigned int sum = 0;
    int i = 0;
	for (i = 3; i < 1000; i++) {
		if ((i % 3 == 0) || (i % 5 == 0)) {
			sum += i;
		}
	}

	return sum;
}


