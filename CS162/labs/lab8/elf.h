
//#include "creature.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;

#ifndef ELF_H
#define ELF_H
class elf: public creature {
	private:
		string getSpecies();
		//bool magicAtk;

	public:
		int getDam ();
		elf (int newHp, int newStr);
};

int elf::getDam() {
			cout << "\n" << elf::getSpecies() 
				 << "attacks for " << creature::getDam() << " damage!";
			int dam = creature::getDam();

			if ((rand() % 10) == 0) {
				cout << "\nMagical attack inflicts " << dam << " extra damage!";
				dam *= 2;
			}

			return dam;
}

//constructor
elf::elf(int newHp, int newStr) { setHp(newHp), setStr(newStr); }

//Accessors
string elf::getSpecies() {
	return "elf";
}
#endif
