/*
Lab 4: summation.cpp
Kamal Chaya
*/

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::pow;


int calcSum(int upperlimit)
{
	int functionVal = 0;
	int sum = 0;
	for(int i = 1; i <= upperlimit; i++)
	{
		functionVal = pow(i, 5) + 10;
		sum = sum + functionVal;
	}
	
	return sum;
}

int main()
{
	bool findSum = true;
	
	while (findSum == true)
	{
		while(1)
		{
			char yesorno;
			
			cout << "\nDo you want to find the summation for the function\n";
			cout << "f(x) = x^5 + 10? (y/n):";
			cin >> yesorno;
				
			if ((yesorno == 'y') || (yesorno == 'Y'))
			{
				findSum = true;
				break;
			}
					
			else if ((yesorno == 'n') || (yesorno == 'N'))
			{
				findSum = false;
				break;
			}
					
			else
				cout << "\nInvalid input, you didnt enter a 'y' or 'n'; try again.";
		}
		
		int n = 0;
		cout << "\nTo what number n would you like to calculate the sum?";
		cin >> n;
		cout << "\nCalculating sum for n = " << n << "...";
		cout << "\nThe sum is: " << calcSum(n);
		
		//So the user can get asked again if they want to calculate the sum or not
	}
	
	return 0;
}