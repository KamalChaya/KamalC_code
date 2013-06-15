#include "creature.h"
#include <string>
using std::string;

//include guard
#ifndef CREATURECAR_H
#define CREATURECAR_H


//constructor: needs to take in a parameter of type creature which is the driver.
class Creature_car {
private:
	int spd; //how much it moves per second.
	
public:
	//constructor
	creature * driver;

	//accessor
	int getSpeed() { return spd; }
	virtual string getVehicle() { return ""; }
	virtual int getDistance() { return 0; }
	//mutator
	void setSpeed(int newSpd) { spd = newSpd; }

};

class skateboard: public Creature_car {
public:
	//creature * driver;
	skateboard(creature pilot) { 
		driver = &pilot
		
	}
	
	string getVehicle() { return "skateboard"; }
	int getDistance() { return getSpeed(); }
};


class motorcycle: public Creature_car {
public:
	creature * driver;
	motorcycle(creature pilot) { driver = &pilot; }

	string getVehicle() { return "Vehicle"; }
	int getDistance() { return getSpeed(); }
};

class bike: public Creature_car {
public:
	creature * driver;
	bike(creature pilot) { driver = &pilot; }

	string getVehicle() { return "bike"; }
	int getDistance() { return getSpeed(); }
};

class racecar: public Creature_car {
public:
	creature * driver;
	racecar(creature pilot) { driver = &pilot; }

	string getVehicle() { return "racecar"; }
	int getDistance() { return getSpeed(); }
};
#endif