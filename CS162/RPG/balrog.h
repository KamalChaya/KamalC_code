#include "demon.h"

#ifndef BALROG_H
#define BALROG_H
class balrog: public demon {
	private:
		string getSpecies();
	public:
		int getDam();
		balrog(int, int);
};
#endif
