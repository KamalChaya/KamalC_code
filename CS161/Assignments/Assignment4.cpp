/**************************************************************
** Program Filename: a4.cpp
** Author: Kamal Chaya
** Date: DUE 2.19.2013
** Description:
    -This program has two main functions:
	1. The ability to check if a user inputted string is
           a palindrome.
 	2. The ability to reverse a user inputted string.
    -It should allow the user to reuse the program or quit 
     if they wish. 
** Input: 
	-Whether or not the user wants to reverse a string, check
	 if it is a palindrome, or quit (inputted in the form of 
	 an integer).
	-The string the user wants the program to analyze
** Output:
	-The reversed string, or a message stating whether or not
	 the inputted string is a palindrome. 
**************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using std::cout;
using std::cin;
using std::getline;
using std::string;

void cut_special_char (string &param1);
void convert_lowercase (string &param1);
string reverse_string (string param1);
bool determine_palindrome (string param1, int iL, int iR);

//QUESTION: when reversing string, do we need to remove spaces? Because the example given does not. 

int main()
{
	bool userWantsRedo = true;
	do
	{
		int decision = 0;
		string input;
		cout << "\nDo you want to reverse a string, check if it is a palindrome, or quit?";
		cout << "\n(Press 1 for reverse, 2 for palindrome, and anything else to quit): ";

		cin >> decision;
		cin.ignore(); //Clear the input stream

		//iL=index of leftmost char in string, iR=index of rightmost.
		int iL = 0, iR = 0;

		/*
		The value of this variable will tell us if the entered string
		is a palindrome or not. 
		*/
		//int isPalindrome = 1;

		switch (decision)
		{
			case 1: //Reverse string
				cout << "\nEnter your string: ";
				getline(cin, input);
				cut_special_char (input);
				cout << "\nThe reversed string is: " << reverse_string(input);
				break;

			case 2: //Check if palindrome
				cout << "\nEnter your string: ";
				getline(cin, input);
				cut_special_char (input);
				convert_lowercase (input);
				iR = input.size() - 1;
				if (determine_palindrome(input, iL, iR) == true)
					cout << "\nYou have entered a palindrome!!!";
				else 
					cout << "\nThis is not a palindrome.";
				break;

			default: //Quit
				userWantsRedo = false;
				break;
		}
	} while (userWantsRedo == true);
	return 0;
}


/*
This function is used to detect any special characters or spaces, and 
cut them out of the string. 
*/
void cut_special_char (string &param1)
{
	/*
	This variable will be used to determine whether or not
	characters have been removed. If they have, we will set this
	to true. Later on in this function, if the value of this variable
	is true, then we will print a message saying that special characters
	were found in the inputted string, and that these will be removed. 
	*/
	bool alter = false;
	
	for (int i = 0; i <= param1.size() - 1; i++)
	{
		/*
		This function uses the isalnum function from the
		standard "ctype.h" library to detect if the user
		has entered any special characters or not. 
		The if case must also evaluate to true if there are any spaces in the
		string. 
		*/
		if ((isalnum(param1.at(i)) == 0) || (param1.at(i) == ' '))
		{
			param1.erase(i, 1);
			alter = true;

			/*
			We need to decrement i because when we remove a special character from our
			string, the size of the string is reduced. If there is a special character
			right next to the one that was erased, then this char will have been skipped
			due to the reduction in size and the incrementing of i. To counteract this, 
			decrementing i will ensure that the character next to the one which was 
			just erased will be inspected by the function. 
			*/
			--i;
		}
	}

	if (alter == true)
	{
		cout << "\nThe string you input has special characters or spaces,";
		cout << "\nand these will be removed.";
	}
}

/*
This function converts a string to have all lowercase letters.
If a string was not converted to all lowercase, then the program
cannot correctly determine if it is a palindrome or not. 

For example; if we entered "Mam", without converting to lowercase
first, the program will say that this is not a palindrome, because
"M" is not the same as "m". Converting all of the letters in a string
to lowercase solves this problem.
*/
void convert_lowercase (string &param1)
{
	/*
	The isupper and tolower functions from the 'ctype.h' library are used to
	to inspect the individual characters in the string and see if they are
	uppercase, and then convert them to lowercase if they are. This process
	is repeated via iteration for all characters in the string.
	*/
	for (int i = 0; i <= param1.size() - 1; i++)
	{
		char c = param1.at(i);
		if (isupper(c) != 0)
		{
			c = tolower(c);
			param1.at(i) = c;
		}
	}
}

string reverse_string (string param1)
{
	if (param1.size() == 0)
		return "";

	else if (param1.size() == 1)
		return param1;

	else
		return param1.at(param1.size() - 1) + reverse_string(param1.substr(1, param1.size() - 2)) + param1.at(0);

}

bool determine_palindrome (string param1, int iL, int iR)
{
	bool isPalindrome = true;
	if (param1.size() == 0)
		cout << "\nYou did not enter a string.";

	else if (param1.size() == 1)
		cout << "\nYou have entered a palindrome!!!";

	else
	{   /*
		Although it is possible to use an if statemetemnt instead of
		a while loop, a while loop is used in order to allow a break
		statement in the else case below. If we had used an if statement,
		the compiler would give an error due to the break statement in 
		the else case.
		*/
		while (iL <= (param1.size() - 1))
		{
			//If the chars at either end of string match..
			if (param1.at(iL) == param1.at(iR))
			{
				/*
				If the chars match, we set isPalindrome to true.
				If at any point they do not match, we set it to 
				false, and then break out of the while loop. Then,
				we later return the value of isPalindrome. Outside
				of this function, we use an if statement to see if
				isPalindrome == true or not. If it is true, we
				print a message stating that the string entered is 
				a palindrome; otherwise, we state that it is not.
				*/
				isPalindrome = true;
				determine_palindrome(param1, iL + 1, iR - 1);
			}

			//If the chars don't match...
			else
			{
				isPalindrome = false;
				break;
			}
		}
	}
	return isPalindrome;
}

//Capital palindromes must work: ie. Mam
//Thi must work: Mam, I'm am ; the program should convert it: Mam, I'm am -> mamimam
//When checking if palindrome: Turn everything into lowercase first.