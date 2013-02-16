//By kamal chaya

#include <iostream> /*included to allow for cout/cin to be used*/
#include <ctime> /*included to allow time() to be used*/
#include <cstdlib> /*include to allow rand() and srand() to be used*/

using std::cout;
using std::cin;

int main() 
{
	int x; /* variable to hold our random integer*/
	srand(time(NULL)); /*seeds random number generator. Do this just once*/
	
	x = rand() % 50;
	int user_guess = 0; //variable for the user's guess.
	
	//for loop iterates i from 1 to 5 to give user 5 tries to guess
	for(int i = 1; i <= 5; i++)
	{
		cout << "\nGuess my number.\n";
		cin >> user_guess;
		
		if (user_guess < x)
			cout << "\n" << user_guess << " is too low";
		
		else if (user_guess == x)
		{
			cout << "\nPerfect guess!\n";
			break;
			//If the user guesses right, the game is over, regardless
			//of whether they needed 5 tries or not. Thus, use a break statement.
		}
			
		else
			cout << "\n" << user_guess << " is too high";
			
	}
	
	return 0;
}