
#include <iostream>
#include "follower.h"
#include "equipment.h"

int main()
{
	Follower character;
	Equipment myequipment("ooo", "eee", Item::itemTag::weapon, 3, 2, 1);

	character.add_inventory(std::make_unique<Equipment>(myequipment));
	character.add_inventory("ooo", "eee", 3, 2, 1);

	std::cout << character.printInventory().str();
	std::cin.clear();

	std::cout << character.printEquipment().str();

	std::cout << character.printPotions().str();

	character.add_inventory("caillasse", "une pierre quelquonque");
	character.add_inventory(Stats::name_stat::stamina);
	character.add_inventory("une �p�e", "une �p�e simple", 5, 5, 2);

	std::cout << character.printInventory().str();
	std::cin.clear();

	std::cout << character.printEquipment().str();

	std::cout << character.printPotions().str();
	//character.add_inventory(myequipment);


}


