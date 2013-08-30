
//Itoa Function
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
	int x = n, length = 0;

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