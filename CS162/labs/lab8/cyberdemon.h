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

cyberdemon::cyberdemon(int newHp, int newStr) { setHp(newHp), setStr(newStr); }

string cyberdemon::getSpecies() { return "cyberdemon"; }

int cyberdemon::getDam() { return demon::getDam(); }
#endif