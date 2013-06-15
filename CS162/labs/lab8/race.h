/*
 * This file contains the function execute_race.
 * Include this file to allow you to perform
 * races between your creatures.
 *
 * You will need to have the following functions defined:
 *
 *			In the car class (and subclasses):
 *				string getVehicle() // string describing the vehicle
 *				int getDistance()   // how far we move per second
 *
 *			In the creature class (and subclasses):
 *				string getSpecies()    // string describing the species
 *				int getHp()     // getter for the creature hitpoints
 *				void setHp(int) // setter for the creature hitpoints
 *				int getDam()        // how much damage we did
 */
#ifndef RACE_H
#define RACE_H


#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <string>
#include "creature.h"
#include "CreatureCar.h"

/*
 * These macros can be adjusted to change
 * the time the game takes to run.
 */
#define SEC_TIME_LIMIT 120 // game will quit if no winner after this time is up
#define RACE_DISTANCE 1000 // distance to reach the food
#define VICTORY_FOOD  1000 // the amount of food
#define EAT_PER_ROUND 0.05 // the percent of their bodyweight
                           // a creature can eat per second

using std::cout;
using std::endl;
using std::flush;
using std::string;

/*
 * This function takes as input two pointers
 * to objects of the creature_car class (or sub-classes).
 * It will return the pointer to the winning creature_car.
 */
creature *execute_race (Creature_car *a, Creature_car *b)
{
	int remaining_food = VICTORY_FOOD;
	int race_prog_a = 0;
	int race_prog_b = 0;

	bool finished_a = false;
	bool finished_b = false;

	/*
	string species_a = a->driver-> //Cant access get species?
	string species_b = b->driver->getSpecies();*/

	string species_a = "human";
	string species_b = "elf";

	int limit = 0;
	int temp = 0;
	int random = 0;

	// initialize random numbers
	srand(time(NULL));

	// Print out who is racing...
	cout << "Car A: " << species_a;
	cout << " in the " << a->getVehicle() << endl;

	cout << "Car B: " << species_b;
	cout << " in the " << b->getVehicle() << endl;

	cout << endl;

	cout << "Race will begin in " << flush;
	sleep(2);
	cout << "3, " << flush;
	sleep(1);
	cout << "2, " << flush;
	sleep(1);
	cout << "1..." << flush;
	sleep(1);
	cout << "GO!" << endl << endl;

	// Start Race!
	while (++limit < SEC_TIME_LIMIT) {
		sleep(1);
		cout << endl;
		cout << endl;
		cout << endl;

		// Racer A
		if (!finished_a) { // Round One: Racing
			race_prog_a += a->getDistance();
			if (race_prog_a >= RACE_DISTANCE) {
				finished_a = true;
				cout << "Racer A (" << species_a << ") has reached the food." << endl;
			} else {
				cout << "Racer A (" << species_a << ") has completed "
					 << race_prog_a * 100 / RACE_DISTANCE << "% of the race." << endl;
			}
		} else if (remaining_food > 0) { // Round Two: Eating
			random = rand() % 100;
			if (random == 99) {
				cout << "Perfect piece of food!" << endl;
				temp = a->driver->getHp() * EAT_PER_ROUND * 20;
			} else if (random > 90) {
				cout << "Good piece of food!" << endl;
				temp = a->driver->getHp() * EAT_PER_ROUND * 5;
			} else {
				temp = a->driver->getHp() * EAT_PER_ROUND;
			}
			if (temp == 0) {
				temp = 1; // to help out the little guys
			}
			if (temp >= remaining_food) {
				a->driver->setHp(a->driver->getHp() + remaining_food);
				remaining_food = 0;
				cout << "Racer A (" << species_a << ") has eaten the last of the food"
					 << " and now has " << a->driver->getHp() << " hitpoints." << endl;
			} else {
				a->driver->setHp(a->driver->getHp() + temp);
				remaining_food -= temp;
				cout << "Racer A (" << species_a << ") has eaten " << temp
					 << " and now has " << a->driver->getHp() << " hitpoints." << endl;
			}
		} else if (limit % 2 == 0) { // Round Three: Fighting
			sleep(1); // for dramatic effect
			temp = a->driver->getDam();
			if (temp >= b->driver->getHp()) {
				cout << "Racer A (" << species_a << ") has defeated Racer B (" << species_b
					 << ") with a hit for " << temp << " damage!" << endl;
				return a->driver;
			} else {
				b->driver->setHp(b->driver->getHp() - temp);
				cout << "Racer A (" << species_a << ") has hit Racer B (" << species_b
					 << ") for " << temp << " damage. Racer B now has "
					 << b->driver->getHp() << " hitpoints." << endl;
			}
		}

		// Racer B
		if (!finished_b) { // Round One: Racing
			race_prog_b += b->getDistance();
			if (race_prog_b >= RACE_DISTANCE) {
				finished_b = true;
				cout << "Racer B (" << species_b << ") has reached the food." << endl;
			} else {
				cout << "Racer B (" << species_b << ") has completed "
					 << race_prog_b * 100 / RACE_DISTANCE << "% of the race." << endl;
			}
		} else if (remaining_food > 0) { // Round Two: Eating
			random = rand() % 100;
			if (random == 99) {
				cout << "Perfect piece of food!" << endl;
				temp = b->driver->getHp() * EAT_PER_ROUND * 20;
			} else if (random > 90) {
				cout << "Good piece of food!" << endl;
				temp = b->driver->getHp() * EAT_PER_ROUND * 5;
			} else {
				temp = b->driver->getHp() * EAT_PER_ROUND;
			}
			if (temp == 0) {
				temp = 1; // to help out the little guys
			}
			if (temp >= remaining_food) {
				b->driver->setHp(b->driver->getHp() + remaining_food);
				remaining_food = 0;
				cout << "Racer B (" << species_b << ") has eaten the last of the food"
					 << " and now has " << b->driver->getHp() << " hitpoints." << endl;
			} else {
				b->driver->setHp(b->driver->getHp() + temp);
				remaining_food -= temp;
				cout << "Racer B (" << species_b << ") has eaten " << temp
					 << " and now has " << b->driver->getHp() << " hitpoints." << endl;
			}
		} else if (limit % 2 == 1) { // Round Three: Fighting
			sleep(1); // for dramatic effect
			temp = b->driver->getDam();
			if (temp >= a->driver->getHp()) {
				cout << "Racer B (" << species_b << ") has defeated Racer A (" << species_a
					 << ") with a hit for " << temp << "damage!" << endl;
				return b->driver;
			} else {
				a->driver->setHp(a->driver->getHp() - temp);
				cout << "Racer B (" << species_b << ") has hit Racer A (" << species_a
					 << ") for " << temp << " damage. Racer A now has "
					 << a->driver->getHp() << " hitpoints." << endl;
			}
		}
	}
	// ran out of time
	if (a->driver->getHp() > b->driver->getHp()) {
		cout << "Time expired. Racer A has more hitpoints left." << endl;
		return a->driver;
	} else {
		cout << "Time expired. Racer B has more hitpoints left." << endl;
		return b->driver;
	}
}

// 
#endif