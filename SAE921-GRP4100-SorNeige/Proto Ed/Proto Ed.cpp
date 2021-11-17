
#include <iostream>
#include <sstream>
#include "Stat.h"
#include "Item.h"
#include "Potion.h"

int main()
{
	int input;
	int input2;
	int input3;
	int o;
	bool loopOut = false;

	std::stringstream eee;
	eee << "Which pouch do you want to go trough?" << std::endl
		<< "[1] : Items. [2] : Potions. [3] : Help." << std::endl;
	std::cout << eee.str();

	while (loopOut == false)
	{
		std::cout << "You decide to take a moment to reflect upon yourself and look trough your bags." << std::endl << std::endl;
		std::cout << "Hability 4/8" << std::endl
			<< "Vitality 7/9" << std::endl
			<< "Luck 11/12" << std::endl
			<< std::endl;
		std::cout << "Your bag contains :" << std::endl
			<< "6 gold." << std::endl
			<< "14 provisions." << std::endl
			<< "3 potions." << std::endl
			<< "3 items." << std::endl
			<< std::endl;
		std::cout << "Which pouch do you want to go trough?" << std::endl
			<< "[1] : Items. [2] : Potions. [3] : Help." << std::endl;

		std::cout << ">";
		std::cin >> input;
		std::cout << std::endl;

		if (input == 3)
		{
			continue;
		}

		if (input == 1)
		{
			std::cout << "You look trough your items." << std::endl
				<< "[1] x2 Dagger (+2/-1/+3)" << std::endl
				<< "[2] Longsword (+4/+2/0)" << std::endl
				<< "[3] Exit." << std::endl;
		}
		else if (input == 2)
		{
			std::cout << "You look trough your potions." << std::endl
				<< "[1] Hability potion (2/2)" << std::endl
				<< "[2] Luck potion (1/2)" << std::endl
				<< "[3] Hability potion (1/2)" << std::endl
				<< "[3] Exit." << std::endl;
		}

		std::cout << ">";
		std::cin >> input2;
		std::cout << std::endl;

		if (input2 == 3)
		{
			continue;
		}

		std::cout << "What do you want to do with that item?" << std::endl
			<< "[1] : Inspect. [2] Equip. (/use, change en fonction de l'item.) [3] Exit." << std::endl;

		std::cout << ">";
		std::cin >> input3;
		std::cout << std::endl;

		if (input3 == 3)
		{
			continue;
		}

		if (input3 == 1)
		{
			std::cout << "It's a steel dagger, it looks decent. "
				<< "You might not have much range with that weapon, but it's sharp, pointy, and it's light weight makes it a versatile weapon"
				<< std::endl;
		}
		else if (input3 == 2)
		{
			//(????'Your right hand is now busy'????)
			std::cout << "You equip a Dagger. (????'Your right hand is now busy'????)" << std::endl
				<< "Hab+1\t 4-> 5/8." << std::endl
				<< "Vit-1\t 7-> 6/9." << std::endl
				<< "Luck+3\t 11-> 12/12." << std::endl;
		}

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Fin.";
		std::cin >> o;

		if (o == 3)
		{
			continue;
		}
	}
}
