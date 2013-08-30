/***************************************************************
** Program Filename: primes.cpp
** Author: Kamal Chaya
** Date: 1.28.2013 (what date do we put)
** Description: 
	-Finds and prints all the prime numbers between 3, and some
	 higher number (which is set by the user). 
** Input:
	-The upper limit, x. The prime numbers printed will be 
	 between 3 and x.
** Output:
	-Printing on the screen the prime numbers between 3 and x
***************************************************************/

//Include pertinent libraries
#include <iostream>
#include <cmath>

//Bring in the necessary items from the standard namespace
using std::cout;
using std::cin;

int main()
{
    /*
	 The variable 'x' will be the upper limit; the primes found 
	 will be between 3 and x. 
	 */
	int x = 0;
	
	//Welcome message
	cout << "\nWelcome! This program will print prime numbers";
	cout << "\nwithin a specified range.\n";
	
	
	while(1)
	{
		//Get user input for the upper limit (x).
	
		cout << "--------------------------------------------------------";
		cout << "\nWhat is the upper limit x that you would like to set?\n";
		cout << "The prime numbers printed will be between 3 and x.\n";
		cout << "Please enter in a number bigger than 3.\n";
		cin >> x;
	
	   /*
		If the number entered is less than or equal to 3, the infinite while loop
		makes it so that the program will go back to lines 40-44, where
		the number can be entered again. This way, if the user enteres in a number
		less than or equal to 3, the program recognizes this mistake and allows them
		the opportunity to enter a valid number. 
	    */
		if (x <= 3)
		{
			cout << "\nInvalid input; you entered a number that was not ";
			cout << "\nbigger than 3. Please enter a number bigger than 3.";
		}
		
		else
			break;
	}
		
	
   /*
    This for loop iterates the variable n from 3 to x; iterated
	values of n are tested to see if they are prime or not. 
    */
		 
	for	(int n = 3; n <= x; n++)
	{
	   /*
	    To check if a number is prime, we only need to divide it by every
		number from 2 to the square root of n (we don't need to go all the
		way to n-1, which is the original method the assignment described).
		This is because if a number n is not prime, then it will have at least
		2 factors other than n and 1. One of the factors will be greater than 
		the square root of n, and the other less than the square root of n. Dividing
		by any of these factors results in a modulus of 0, so simply dividing n 
		by the factors less than the square root of n will suffice (this is
		explained in more detail in the writeup). 
		*/
		bool numberIsPrime = true;
		for (int divisor = 2; divisor <= sqrt(n); divisor++)
		{
			/*
			 If n divides evenly with the divisor, that means
			 it is not prime, so set numberIsPrime to false.
			 */
			if (n % divisor == 0)
				numberIsPrime = false;
		}

		if(numberIsPrime == true)
			cout << "\n" << n << " is a prime number.\n";
	}
	return 0;
}
