/*****************************************************************************
**Program Filename: chayak_assignment1.cpp
**Author: Kamal Chaya
**Date: 1.13.2013
**Description: 
	*Assigns macro's from the climits
	 library to variables of the correct data type, 
	 and prints to the screen the values of these variables in decimal,
	 hexadecimal, and octal. 
	*Adds 1 to the variables with the maximum values, and 
	 subtracts 1 from the variables with the minimum values
	 and prints the results to the screen.
	*Uses the pow() function from the cmath library to calculate
	 the biggest and smallest short, int, and long (signed and 
	 unsigned), and prints the results to the screen. 
**Input: None
**Output: 
	*Values of the variables assigned to the macro's.
	*The values of the variables containing tha maximum values + 1
	*The values of the variables with the minimum values - 1
	*Values calculated with the pow() function for the biggest and smallest
	 short, int, and long (signed and unsigned). 
*****************************************************************************/

//Include the pertinent libraries
#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>

/*
The <iomanip> library is included in order to 
gain access to the setprecision() function. 
*/

using std::cout;
using std::pow;
using std::dec;
using std::hex;
using std::oct;
using std::setprecision;

int main()
{
	/*
	the setprecision function will make it so that the program
	displays 20 decimal digits before it switches over to 
	scientific notation. 
	*/
	cout << setprecision(20);
	
	//Here, the signed macros are assigned to the correct variable types
	int intMin = INT_MIN;
	int intMax = INT_MAX;
	short shrtIntMin = SHRT_MIN;
	short shrtIntMax = SHRT_MAX;
	long longIntMin = LONG_MIN;
	long longIntMax = LONG_MAX;

	//Here, the unsigned macros are assigned to the correct variable types
	unsigned int unsignIntMax = UINT_MAX;
	unsigned short unsignShrtIntMax = USHRT_MAX;
	unsigned long unsignLongIntMax = ULONG_MAX;
	
	cout << "Below, the values of the variables assigned to the macros are shown:\n";

	//Print the values of the variables in decimal (base 2):
	cout << "\n---VARIABLE VALUES SHOWN BELOW IN DECIMAL (BASE 2)---\n";
	cout << "Minimum (signed int): " << dec << intMin << "\n";
	cout << "Maximum (signed int): " << dec << intMax << "\n";
	cout << "Minimum (signed short int): " << dec << shrtIntMin << "\n";
	cout << "Maximum (signed short int): " << dec << shrtIntMax << "\n";
	cout << "Minimum (signed long int): " << dec << longIntMin << "\n";
	cout << "Maximum (signed long int): " << dec << longIntMax << "\n";
	cout << "Maximum (unsigned int): " << dec << unsignIntMax << "\n";
	cout << "Maximum (unsigned short int): " << dec << unsignShrtIntMax << "\n";
	cout << "Maximum (unsigned long int): " << dec << unsignLongIntMax << "\n";
	
	//Print the values of the variables in hexadecimal (base 16):
    cout << "\n---VARIABLE VALUES SHOWN BELOW IN HEXADECIMAL (BASE 16)---\n";
	cout << "Minimum (signed int): " << hex << intMin << "\n";
	cout << "Maximum (signed int): " << hex << intMax << "\n";
	cout << "Minimum (signed short int): " << hex << shrtIntMin << "\n";
	cout << "Maximum (signed short int): " << hex << shrtIntMax << "\n";
	cout << "Minimum (signed long int): " << hex << longIntMin << "\n";
	cout << "Maximum (signed long int): " << hex << longIntMax << "\n";
	cout << "Maximum (unsigned int): " << hex << unsignIntMax << "\n";
	cout << "Maximum (unsigned short int): " << hex << unsignShrtIntMax << "\n";
	cout << "Maximum (unsigned long int): " << hex << unsignLongIntMax << "\n";
	
	//Print the values of the variables in octal (base 8):
    cout << "\n---VARIABLE VALUES SHOWN BELOW IN OCTAL (BASE 8)---\n";
	cout << "Minimum (signed int): " << oct << intMin << "\n";
	cout << "Maximum (signed int): " << oct << intMax << "\n";
	cout << "Minimum (signed short int): " << oct << shrtIntMin << "\n";
	cout << "Maximum (signed short int): " << oct << shrtIntMax << "\n";
	cout << "Minimum (signed long int): " << oct << longIntMin << "\n";
	cout << "Maximum (signed long int): " << oct << longIntMax << "\n";
	cout << "Maximum (unsigned int): " << oct << unsignIntMax << "\n";
	cout << "Maximum (unsigned short int): " << oct << unsignShrtIntMax << "\n";
	cout << "Maximum (unsigned long int): " << oct << unsignLongIntMax << "\n";
	
	//Printing the resulting decimal values when one is added to the variables containing 
	//the maximum values.
	cout << "\nBelow, 1 + the variables with the max values is shown:\n";
	cout << "Signed int max + 1: " << dec << ++intMax << "\n";
	cout << "Signed short int max + 1: " << dec << ++shrtIntMax << "\n";                                                       														
	cout << "Signed long int max + 1: " << dec << ++longIntMax << "\n";
	cout << "Unsigned int max + 1: " << dec << ++unsignIntMax << "\n";											
	cout << "Unsigned long int max + 1: " << dec << ++unsignLongIntMax << "\n";										      											 
	cout << "Unsigned short int max + 1: " << dec << ++unsignShrtIntMax << "\n";
																					
	//Printing the resulting decimal values when one is subtracted from the 
	//variables containing the minimum values
	cout << "\nBelow, the variables with the minimum values - 1 is shown:\n";
	cout << "Signed int min - 1: " << dec << --intMin << "\n";																  
	cout << "Signed short int min - 1: " << dec << --shrtIntMin << "\n";  												  
	cout << "Signed long int min - 1:" << dec << --longIntMin << "\n";

	/*
	Below, pow() is used to calculate the largest and smallest short, int, and long
	(both signed and unsigned).
	*/
	cout << "\nBelow, the pow function is used to calcuate the largest and smallest";
	cout << "\nvalues of variables of type short, int, and long (signed and unsigned):";
	cout << "\nMax (unsign int): " << (unsigned int) pow(2, sizeof(int) * 8) - 1;
	cout << "\nMax (signed int): " << (signed int) pow(2, (sizeof(int) * 8 - 1)) - 1;
	cout << "\nMin (signed int): " << (signed int) - pow(2, (sizeof(int) * 8 - 1));
	
	/*
	some of the lines are indented in this fashion to 
	conform to the 90 character line limit
	*/
	cout << "\nMax (unsign short int): " 
		 << (unsigned short) 2 * pow(2, sizeof(short) * 8 - 1) - 1; 
	
	cout << "\nMax (signed short int): " 
		 << (signed short) (2 * pow(2, sizeof(short) * 8 - 2) - 1) + 1;
	
	cout << "\nMin (signed short int): " << (signed short) - pow(2, sizeof(short) * 8 - 1);
	
	cout << "\nMax (unsign long int): " 
	     << (unsigned long) 2 * (pow(2, sizeof(long) * 8 - 1) - 1) + 1;
	
	cout << "\nMax (signed long int): " 
	     << (unsigned long) pow(2, sizeof(long) * 8 - 1) - 1;
	
	cout << "\nMin (signed long int): " 
	     << (signed long) - pow(2, sizeof(long) * 8 - 1) << "\n";
	
	return 0; 
}
              

