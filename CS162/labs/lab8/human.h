//#include "creature.h"
#include <string>
#include <iostream>
using std::cout;
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

human::human(int newhp, int newStr) { setHp(newhp), setStr(newStr); }

string human:: getSpecies() { return "human"; }

int human:: getDam() {
	cout << "\n" << human::getSpecies() 
		 << "attacks for "<< creature::getDam() << " damage! ";
	return creature::getDam();
}
#endif