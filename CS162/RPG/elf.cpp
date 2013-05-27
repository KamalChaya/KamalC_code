#include "elf.h"

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