
#include <iostream>
#include "follower.h"
#include "equipment.h"
#include "potion.h"

int main()
{
	Follower character;
	Equipment arc("arc", "un arc", Item::itemTag::weapon, 2, 2, 2);
	Potion myPotion("Heal pot", "Pot that heals", Item::itemTag::potion, Stats::name_stat::luck);

	character.add_inventory(std::make_unique<Equipment>(arc));
	character.add_inventory(std::make_unique<Potion>(myPotion));

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
	character.inventoryManager();


}


