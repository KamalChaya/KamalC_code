#include "cyberdemon.h"

//constructor
cyberdemon::cyberdemon(int newHp, int newStr) { setHp(newHp), setStr(newStr); }

string cyberdemon::getSpecies() { return "cyberdemon"; }

int cyberdemon::getDam() { 
	cout << "\n" << cyberdemon::getSpecies() << " attacks for " << creature::getDam() << " normal damage!";
	return demon::getDam(); 
}
	

