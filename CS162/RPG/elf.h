
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
#endif
