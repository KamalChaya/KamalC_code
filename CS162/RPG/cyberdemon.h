//#include "creature.h"
#include "demon.h"

#ifndef CYBERDEMON_H
#define CYBERDEMON_H
class cyberdemon: public demon {
	private:
		string getSpecies();
	public:
		int getDam();
		cyberdemon(int newHp, int newStr);
};
#endif