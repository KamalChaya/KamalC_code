#include <cstdlib>

#ifndef CREATURE_H
#define CREATURE_H
class creature {
	private:
		int str, hp;
		//string getSpecies();
	public:
		//Returns the damage done in 1 round of combat
		int getDam();

		//Accessors
		int getHp();
		int getStr();

		//Mutators
		void setHp(int newHp);
		void setStr(int newStr);
		void subtractHp(int dmgDone); //Use this to alter the hp of a creature in combat.
};

int creature::getDam() {
	int dam = (rand() % getStr()) + 1;
	return dam;
}

//Accessors
int creature::getHp() { return hp; }
int creature::getStr() { return str; }

//Mutators
void creature::setHp(int newHp) { hp = newHp; }
void creature::setStr(int newStr) { str = newStr; }
void creature::subtractHp(int dmgDone) { hp -= dmgDone; }
	
#endif	



