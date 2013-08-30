/***************************************************************
**Program Filename: Problem6.5.cpp
**Author: Kamal Chaya
**Date: DUE 3.15.2013	
**Description:
	-Makes a class called fraction, with functions to allow the 
	 user to change the numerator and denominator.
	-Shows the fraction in decimal form, as well as the fraction
	 reduced to simplest form.
	-Finds the GCD with euclids algorithm to reduce it to simplest
	 form.
**Input:
	-Numerator
	-Denominator
**Output:
	-The resulting fraction in decimal form.
	-The fraction reduced to its most simplified form.
 ***************************************************************/

#include <iostream>
using std::cout;
using std::cin;

//QUESTION: Ok to define functions inside class?
//IF the num>dem and num/den = 1, do we display the 1 in the den, or no?
//Special test cases?

class Fraction {
public:
	/******************************************************
	 ** Function: divide();
	 ** Description: Divides the numerator and denominator, 
	    and prints the result in decimal form.
	 ** Parameters: None (not needed, variables are all 
	    handled inside the class).
	 ** Pre-Conditions: None
	 ** Post-Conditions: None
	 *******************************************************/
	void divide() {
		quotient  = (double) num/den;
		cout << "\nResult of fraction: " << quotient;
	}

    /******************************************************
	 ** Function: setNumDen();
	 ** Description: Gets the users input for the numerator and
	    denominator. Checks if the input denominator is 0,
		and if it is, prompt the user for a new denominator.
	 ** Parameters: None (not needed, variables are all 
	    handled inside the class).
	 ** Pre-Conditions: None
	 ** Post-Conditions: None
	 *******************************************************/

	void setNumDen() { 
		cout << "\nEnter a numerator >: ";
		cin >> num;

		while (1) { 
			cout << "\nEnter a denominator >: ";
			cin >> den;

			if (den == 0) //Cannot accept a denominator of 0.
				cout << "\nCannot divide by 0; enter a nonzero denominator.";

			else
				break;
		}
	}

	/******************************************************
	 ** Function: setNums();
	 ** Description: the findGCDEuclid function requires that
	    whenever it divides, the dividend is always bigger
		than the divisor. This function will assign the 
		dividend and divisor values to conform to this rule.
	 ** Parameters: None (not needed, variables are all 
	    handled inside the class).
	 ** Pre-Conditions: None
	 ** Post-Conditions: None
	 *******************************************************/
	void setNums() {
	   /*
		We need 2 variables to hold the numbers which we are constantly dividing
		which eachother. Initially, this will be the numerator and denominator,
		but this will change with repeated divisions. Thus it is easier to have 
		variables seperate from the numerator and denominator to hold these values.
		
		The reason for this if-else structure is that when using euclids algorithm,
		we need the numerator of our divisions to be bigger than our denominator
		(ie dividend > divisor). This if-else structure will assign those values accordingly.
		*/
		if (num > den) {
			dividend = num;
			divisor = den;
		}
		
		else if (den > num) {
			dividend = den;
			divisor = num;
		}
	}

    /******************************************************
	 ** Function: findGCDEuclid();
	 ** Description: Uses Euclids algorithm to find the GCD
	    for the numerator and denominator entered by the user.
		This GCD will be used later in order to simplify the
		function. 
	 ** Parameters: None (not needed, variables are all 
	    handled inside the class).
	 ** Pre-Conditions: Dividend > Divisor (handled
	    by setNums();
	 ** Post-Conditions: None
	 *******************************************************/
	void findGCDEuclid() {
		/*
		In euclids algorithm, we divide the numerator by the denominator
		(assuming numerator > denominator), and if the remainder is not 0, 
		then we divide the denominator by the remainder. if this
		remainder is not 0, then we divide the old remainder by this new
		remainder. This process repeats until we finally get a remainder of
		0. The denominator of the fraction that has a remainder of 0 is the
		GCD.
		 */
		while (dividend % divisor != 0) {
			temp = divisor;
			divisor = (dividend % divisor);
			dividend = temp;
		}
		
		gcd = divisor;
	}

    /***************************************************************
	 ** Function: showSimpleFrac()
	 ** Description: Shows the fraction reduced to most simplified terms.
	    Uses the previously calculated GCD.
	 ** Parameters: None (not needed, variables are all 
	    handled inside the class).
	 ** Pre-Conditions: Npne
	 ** Post-Conditions: None
	 ***************************************************************/
	void showSimpleFrac() {
		cout << "\nReduced Fraction: " << num/gcd << "/" << den/gcd;
	}
	
	
private:
	int num, den, gcd, divisor, dividend, temp;
	float quotient;
};

int main() {
	bool redo;
	char yOrN;
	do {
		//Make an object of the class fraction called ratio
		Fraction ratio;
	
		//Call the function to get values for the numerator/denominator from the user.
		ratio.setNumDen(); 

		//Divide the numerator by denominator and show the result as a decimal.
		ratio.divide();

		//Set the numbers properly to use the Euclidean GCD algorithm.
		ratio.setNums();

		//Calculate the GCD
		ratio.findGCDEuclid();

		//Show the fraction in simplest form
		ratio.showSimpleFrac();

		while(1) {
			cout << "\nDo you want to reuse the program? (y/n) ";
			cin >> yOrN;

			if (yOrN == 'y') {
				redo = true;
				break;
			}

			else if (yOrN == 'n') {
				redo = false;
				break;
			}

			else
				cout << "\nInvalid character entered; please re-input.";
		}
	} while (redo == true);

	return 0;
}