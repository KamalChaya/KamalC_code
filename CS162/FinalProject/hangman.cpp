#include "hangman.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

hangman::hangman(string word): chosenWord(word), misses(0), occurrences(0)  { 
	blank.resize(chosenWord.size(), '-'); 
}

hangman::hangman(): chosenWord("television"), blank("----------"), misses(0), occurrences(0) {}

void hangman::drawFigure() {
	switch (misses) {
		case 1:
			cout << "The head has been hanged." << endl;
			cout << " ______    " << endl;
			cout << "|      |   " << endl;
			cout << "|      0   " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "---        " << endl;
			break;

		case 2:
			cout << "The head and torso has been hanged." << endl;
			cout << " ______    " << endl;
			cout << "|      |   " << endl;
			cout << "|      0   " << endl;
			cout << "|      |   " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "---        " << endl;
			break;

		case 3:
			cout << "The head, torso, and left arm has been hanged." << endl;
			cout << " ______    " << endl;
			cout << "|      |   " << endl;
			cout << "|      0   " << endl;
			cout << "|     -|   " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "---        " << endl;
			break;

		case 4:
			cout << "The head, torso, and both arms have been hanged." << endl;
			cout << " ______    " << endl;
			cout << "|      |   " << endl;
			cout << "|      0   " << endl;
			cout << "|     -|-  " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "---        " << endl;
			break;

		case 5:
			cout << "The head, torso, both arms, and left leg have been hanged." << endl;
			cout << " ______    " << endl;
			cout << "|      |   " << endl;
			cout << "|      0   " << endl;
			cout << "|     -|-  " << endl;
			cout << "|     /    " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "---        " << endl;
			break;

		case 6:
			cout << "All body parts are hanged. The stick figure has died. You have lost" << endl;
			cout << " ______    " << endl;
			cout << "|      |   " << endl;
			cout << "|      0   " << endl;
			cout << "|     -|-  " << endl;
			cout << "|     / \\ " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "|          " << endl;
			cout << "---        " << endl;
			break;
	}
}
	
void hangman::askWord() {
	while (misses < 6) {
		occurrences = 0;
		char c;
		char temp;
		cout << "Enter a letter you think is in the word." << endl;
		cout << "The word has " << chosenWord.size() << " letters." << endl;
		cin >> c;
	
		for (int i = 0; i <= chosenWord.size() - 1; i++) {
			if ((chosenWord.at(i) == c) && (blank.at(i) != c)) {
				cout << "That letter has been found in the word " << ++occurrences 
																  << " time(s)." << endl;

				//Replace the dash in blank with the appropriate character.
				temp = chosenWord.at(i);
				blank[i] = temp;
			}

			else {
				if ((i == chosenWord.size() - 1) && (occurrences == 0)) {
					cout << "That letter is not in the word or has already been used." << endl;
					misses++;
					cout << "You have " << 6 - misses << " body parts left until the stick figure is hung." << endl;
					drawFigure(); //Draw the stick figure on the screen.
				}
			}
		}

		cout << "The word so far: " << endl;
		cout << blank << endl;

		if (checkBlank() == false) {
			cout << "You have guessed the word correctly!" << endl;
			break;
		}
	}
}

bool hangman::checkBlank() {
	bool dashes = false;
	for (int i = 0; i <= blank.size() - 1; i++) {
		if (blank.at(i) == '-') 
			dashes = true;
	}
	return dashes;
}
