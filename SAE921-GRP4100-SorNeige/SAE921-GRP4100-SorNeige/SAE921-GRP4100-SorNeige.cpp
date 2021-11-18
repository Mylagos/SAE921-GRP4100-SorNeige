
#include <iostream>
#include "follower.h"

int main()
{
	Follower character;

	std::cout << character.printInventory().str();
	std::cin.clear();

	std::cout << character.printEquipment().str();

	std::cout << character.printPotions().str();


	std::cout << character.printInventory().str();
	std::cin.clear();

	std::cout << character.printEquipment().str();

	std::cout << character.printPotions().str();

}


