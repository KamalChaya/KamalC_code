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

using std::cout;
using std::cin;
using std::getline;
using std::string;

string reverse_string (string param1);
bool determine_palindrome (string param1, int iL, int iR);

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
				cout << "\nThe reversed string is: " << reverse_string(input);
				break;

			case 2: //Check if palindrome
				cout << "\nEnter your string: ";
				getline(cin, input);
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
	{
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
				determine_palindrome(param1, ++iL, --iR);
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

//Detect special chars in string: use isalpha function or isalphanum.

