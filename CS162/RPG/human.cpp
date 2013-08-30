#include "human.h"
#include <iostream>

using std::cout;

//constructor
human::human(int newhp, int newStr) { setHp(newhp), setStr(newStr); }

string human:: getSpecies() { return "human"; }

int human:: getDam() {
	
	cout << "\n" << human::getSpecies() 
		 << "attacks for "<< creature::getDam() << " damage! ";
	return creature::getDam();
}