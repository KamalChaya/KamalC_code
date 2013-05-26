#include "demon.h"

//string demon::getSpecies() { return "demon:"; }

int demon::getDam() {
	int dam = 0;

	if (((rand() % getStr()) % 100) < 5) {
		dam += 50;
		cout << "\nDemonic attack inflicts 50 additional damage!";
	}

	return dam + creature::getDam();
}