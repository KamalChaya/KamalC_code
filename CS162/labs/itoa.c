#include <stdio.h>

/*convert int to char*/
void myitoa1(int x, char *str, int base){
	char char_array[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int negative = 0;
	int str_length = 0, number = x;
	
	if(x < 0){		//check if x is negative
		number = -x;	//save x into number as positive
		x = number;			//make x positive
		negative = 1;
	}
	
	do{					//find string length
		str_length++;
		x = x / base;
	} while(x > 0);
	
	x = number;			//restore x from number
	
	if(negative == 1){
		str[0] = '-';	//add (-) sign to front of string if x is negative
		str_length++;	//increase string length by 1
	}
	
	str[str_length--] = '\0';	//set null at end of str
	
	do{
		str[str_length--] = char_array[x % base];	//set string value corresponding to characters in char_array
		x = x - (x % base);		//get rid of last digit in x
		x = x / base;			//divide x by base and move on
	} while(x > 0);
}

void determineDigits (int n, int *numDigits, int base) {
	if (n < 0)
		n = -n;

	(*numDigits) = 0;
	while (n > 0) {
		n /= base;
		(*numDigits)++;
	}
}

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
	
	
	if (signOfN < 0) {
		str[0] = '-';
		length++;
	}
	
	str[length--] = '\0';
	
	do {
		str[length--] = "0123456789abcdef" [n % base];
		n -= (n % base);
		x /= base;
	} while (n > 0);
}

void revCstr (char str[], int numDigits) {
	char temp;
	int i, j;

	for (i = 0, j = numDigits; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}


int main() {
	char buffer[10];
	myItoA(5, 10, buffer);
	
	printf("%s", buffer);
	
	return 0;
}