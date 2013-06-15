#include "creature.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;

#ifndef DEMON_H
#define DEMON_H
class demon: public creature {
	public:
		int getDam();
};

int demon::getDam() {
	int dam = 0;

	if (((rand() % getStr()) % 100) < 5) {
		dam += 50;
		cout << "\nDemonic attack inflicts 50 additional damage!";
	}

	return dam + creature::getDam();
}

#endif