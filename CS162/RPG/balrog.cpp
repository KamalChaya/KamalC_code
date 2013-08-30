#include "balrog.h"

balrog::balrog(int newHp, int newStr) { setHp(newHp), setStr(newStr); }

string balrog::getSpecies() { return "balrog"; }

int balrog::getDam() {
	cout << "\n" << balrog::getSpecies() << "attacks for " 
		 << creature::getDam() << " damage!";

	cout << "\n" << balrog::getSpecies() << "speed attack inflicts "
		<< creature::getDam() << " additional damage!";

	return 2*creature::getDam() + demon::getDam();
}