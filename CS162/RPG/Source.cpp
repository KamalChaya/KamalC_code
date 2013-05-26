/*
Program Filename: Source.cpp
Author: Kamal Chaya
Date Due: 5.27.2013
Description: Defines the classes in the creatures 
header file. This can be used to implement a simple 
RPG like game.
Input: What race the user wants
Output: Damage done during combat
*/

#include <iostream>
#include <string>
#include <cstdlib> /* rand, srand */
#include <ctime> /* time (for seeding rand numbers) */

#include "creature.h"
#include "human.h"
#include "elf.h"
#include "demon.h"
#include "balrog.h"
#include "cyberdemon.h"
	
#include "human.cpp"
#include "balrog.cpp"
#include "elf.cpp"
#include "demon.cpp"
#include "cyberdemon.cpp"

using std::string;
using std::cout;
using std::cin;

/*
Questions:
	-Do we need a get species function for each of our child classes that represent each of the races?
	-Are the child classes declared correctly in the header file?
	-Can we define our functions inside of our classes?
	-Cant we just make the private vars protected, eliminating the need for accesors?
	//are the one line accessors ok?
	-Do i need to include human.h elf.h and demon.h in my main? since they are already included by creature.	
	\

	-How do I call getDam for each level in the class hierarchy?
	-Does the demon class need a getspecies function as well or do only balrog and cyberdemon need it?

*/

int main() {
	srand(time(NULL));
	
	int balrogHp = 0, balrogInitHp = 0, balrogStr = 0;
	cout << "\nHow much hp should the balrog have?";
	cin >> balrogHp;
	balrogInitHp = balrogHp;
	cout << "\nHow much strength should the balrog have?";
	cin >> balrogStr;
	balrog balrog1(balrogHp, balrogStr);//create balrog object
		
	int cyberHp = 0, cyberInitHp = 0, cyberStr = 0;
	cout << "\nHow much hp should the cyberdemon have?";
	cin >> cyberHp;
	cyberInitHp = cyberHp;
	cout << "\nHow much strength should the cyberdemon have?";
	cin >> cyberStr;
	cyberdemon cyberdemon1(cyberHp, cyberStr); //create cyberdemon object.

	int elfHp = 0, elfInitHp = 0, elfStr = 0;
	cout << "\nHow much hp should the elf have?";
	cin >> elfHp;
	elfInitHp = elfHp;
	cout << "\nHow much strength should the elf have?";
	cin >> elfStr;
	elf elf1(elfHp, elfStr); //create elf object

	int humanHp = 0, humanInitHp = 0, humanStr = 0;
	cout << "\nHow much hp should the human have?";
	cin >> humanHp;
	humanInitHp = humanHp;
	cout << "\nHow much strength should the human have?";
	cin >> humanStr;
	human human1(humanHp, humanStr); //create human object.

	int battleChoice = 0;
	cout << "\nPress 1 for balrog vs cyberdemon, or 2 for elf vs human.";
	cin >> battleChoice;

	if (battleChoice == 1) {
		int cyberDam = 0, balDam = 0;
		while (1) {
			cout << "\nCombat Round Results: ";
			cyberDam = cyberdemon1.getDam();
			cout << "\n";
			balDam = balrog1.getDam();
			balrog1.subtractHp(cyberDam);
			cyberdemon1.subtractHp(balDam);
			cout << "\nBalrog hp: " << balrog1.getHp() << "/" << balrogInitHp;
			cout << "\nCyberdemon hp: " << cyberdemon1.getHp() << "/" << cyberInitHp;

			int keyPress = 0;
			cout << "\nPress 1 to proceed to the next round of combat.";
			while (1) {
				cin >> keyPress;
				if (keyPress == 1)
					break;
			}
			
			if ((balrog1.getHp() <= 0) || (cyberdemon1.getHp() <= 0))
				break;
		}
		
		if ((balrog1.getHp() <= 0) && (cyberdemon1.getHp() <= 0)) 
			cout << "\nBoth combatants have defeated eachother.";
		
		else if (balrog1.getHp() <= 0) 
			cout << "\nThe cyberdemon is victorious!"; 
		
		else if (cyberdemon1.getHp() <= 0) 
			cout << "\nThe balrog is victorious!";
	}
	
	else if (battleChoice == 2) {
		int elfDam = 0, humDam = 0;
		while (1) {
			cout << "\nCombat round results: ";
			elfDam = elf1.getDam();
			cout << "\n";
			humDam = human1.getDam();
			efl1.subtractHp(humDam);
			human1.subtractHp(elfDam);
			cout << "\nHuman hp: " << human1.getHp() << "/" << humanInitHp;
			cout << "\nElf hp: " << elf1.getHp() << "/" << elfInitHp;
			
			int keypress = 0;
			cout << "\nPress 1 to proceed to the next round of combat.";
			cin >> keypress;
			while (1) {
				if (keypress == 1)
					break;
			}
			
			if ((elf1.getHp() <= 0) || (human1.getHp() <= 0))
				break;
		}
		
		if ((human1.getHp() <= 0) && (elf1.getHp() <= 0))
			cout << "\nBoth combatants have been defeated.";
		
		else if (elf1.getHp() <= 0)
			cout << "\nThe human is victorious!";
		
		else if (human1.getHp() <= 0)
			cout << "\nThe elf is victorious!";
	}
	
	return 0;
}


