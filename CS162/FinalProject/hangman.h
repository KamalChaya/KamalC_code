#include <string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#ifndef HANGMAN_H
#define HANGMAN_H

class hangman {
public:
	hangman(); //def.constructor, makes the word television by default. Not really going to be used.
	hangman(string word); //This constructor makes the word whatever is randomly chosen from the vector.
	void askWord();
	void drawFigure();
	bool checkBlank();
private:
	/*
	 The blank string will be displayed on the screen, it will be
	 dashes initially, but then as the player guesses the correct
	 letters it will change to show these letters (similar to how
	 the dashes have letters written over them in real hangman).
	 */
	string blank, chosenWord;
	int misses;
	int occurrences;
};


#endif