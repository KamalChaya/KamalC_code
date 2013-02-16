/*
Name: Kamal Chaya
Filename: function_fun.cpp
Lab 5
*/

#include <iostream>
#include <string>
#include <cstdlib>
using std::cout;
using std::cin;
using std::string;
using std::atoi;

int is_positive_int (string n);
void get_positive_int (string &n1, string &n2);
void countUp (int n1);
void countDwn (int n1);
void countBtwn (int n1, int n2);

int main()
{
	bool userWantsRedo;
	do
	{
		//Declare string vars
		string n1, n2;
		
		//Get positive int
		get_positive_int (n1, n2);
		
		//Convert from str to int
		int a, b;
		a = atoi(n1.c_str());
		b = atoi(n2.c_str());
		
		//Count up, down, and between
		countUp(a);
		cout << "\n";
		countDwn(a);
		cout << "\n";
		countBtwn(a, b);
		
		//Ask the user if they want to redo or not:
		while (1)
		{
			int yesOrNo;
			cout << "\nDo you want to run this again with 2 different ints?";
			cout << "\n(Enter 1 for yes, or 2 for no): ";
			cin >> yesOrNo;
			
			if (yesOrNo == 1)
			{
				userWantsRedo = true;
				break;
			}
			
			else if (yesOrNo == 2)
			{
				userWantsRedo = false;
				break;
			}
			
			else
			{
				cout << "\nInvalid Input: please enter a number between 1 and 2";
			}
		}
	} while (userWantsRedo == true);
	return 0;
}

int is_positive_int (string str1)
{
	int size = str1.size();
	
	for (int i = 0; i <= size; i++)
	{
		if (
			(str1.at(i) == '0') || 
			(str1.at(i) == '1') || 
			(str1.at(i) == '2') || 
			(str1.at(i) == '3') || 
			(str1.at(i) == '4') || 
			(str1.at(i) == '5') || 
			(str1.at(i) == '6') || 
			(str1.at(i) == '7') || 
			(str1.at(i) == '8') ||
			(str1.at(i) == '9') 
		   )
		{
			//In this case, the number entered is positive.
			return 1;
			break;
		}
		
		else
			return 0; //The user didn't enter a positive number

	}
}

void get_positive_int (string &n1, string &n2)
{
	while (1)
	{
		cout << "\nPlease enter 2 positive ints: \n";
		cin >> n1 >> n2;
			
		//Check if the number entered is positive or not:
		if ((is_positive_int(n1) == 0) || (is_positive_int(n2) == 0))
		{
			cout << "\nYou did not enter a positive int. Try again.";
		}
			
		else
			break;
			
	}
}

void countUp (int n1)
{
	for (int i = 0; i <= n1; i++)
	{
		cout << i << " ";
	}
}

void countDwn (int n1)
{
	for (int i = n1; i >= 0; i--)
	{
		cout << i << " ";
	}
}

void countBtwn (int n1, int n2)
{
	for (int i = n1; i <= n2; i++)
	{
		cout << i << " ";
	}
}
	