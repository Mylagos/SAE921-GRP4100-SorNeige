
#include <iostream>
#include "follower.h"

int main()
{
	Follower character;

	std::cout << character.printInventory().str();
	std::cin.clear();

	std::cout << character.printEquipment().str();

	std::cout << character.printPotions().str();

	character.add_inventory("caillasse", "une pierre quelquonque");
	character.add_inventory(Stats::name_stat::stamina);
	character.add_inventory("une épée", "une épée simple", 5, 5, 2);

	std::cout << character.printInventory().str();
	std::cin.clear();

	std::cout << character.printEquipment().str();

	std::cout << character.printPotions().str();


}


