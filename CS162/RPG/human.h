//#include "creature.h"
#include <string>

using std::string;

#ifndef HUMAN_H
#define HUMAN_H
class human: public creature {
	private:
		string getSpecies();
	public:
		int getDam();
		human(int hp, int newStr); //constructor
};

#endif