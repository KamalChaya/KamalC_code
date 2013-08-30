/*
Author: Kamal Chaya
Filename: Final_hangman.cpp
Date: 6.7.2013
Description: Implements a simple hangman game, obtaining words
from a text file
Input: text file containing words, players guesses for letters.
Output: Whether or not a guess is correct, a picture of a stick figure.
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "hangman.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;

int main() {
	srand(time(NULL));
	ifstream wordfile ("word_database.txt");
	vector<string> wordArray; //STL vector for holding the words in the file as strings

	string temp, chosenWord;

	if (wordfile.is_open()) {
		while (wordfile.good()) {
			wordfile >> temp;
			wordArray.push_back(temp);
		}
	}

	else 
		cout << "Error: Unable to open line" << endl;

	/*We Add +1 to the size because if we didnt, 
	  then the random number generated would always 
	  be less than the vectors size, which would make 
	  it impossible for the last word in the file to 
	  be chosen. Thus, adding 1 to the size ensures that 
	  the last word can be chosen as well.
	 */
	chosenWord = wordArray[rand() % (wordArray.size() + 1)];

	hangman hangman1(chosenWord);

	hangman1.askWord();

	return 0;
}
