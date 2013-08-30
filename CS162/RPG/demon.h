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
#endif