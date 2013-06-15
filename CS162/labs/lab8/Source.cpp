//lab8: Kamal Chaya
#include <unistd.h>
#include "balrog.h"
#include "creature.h"
#include "CreatureCar.h"
#include "cyberdemon.h"
#include "demon.h"
#include "elf.h"
#include "human.h"
#include "race.h"

int main() {

	human human1(100, 10);
	elf elf1(100, 15);

	motorcycle cycle1(human1);
	skateboard board1(elf1);

	execute_race(&cycle1, &board1);

	return 0;
}