#pragma once
#include <iostream>
#include <vector>

#include "Stats.h"
#include "item.h"

class follower
{
private:
	std::string name; // Follower name (Not used in hero)
	std::string description; // Follower description (Not used in hero)

	Stats currentStat; //named currentstat to be easier to use in character

	std::vector<std::unique_ptr<item>> inventory;

	int weaponQty;
	int qItemQty;
	int potionQty;

public:
	void setName(std::string name_){this->name = name_;}
	std::string getName() { return name; }

	void setDescription(std::string description_) { this->description = description_; }
	std::string getDescription() { return description; }

	std::vector<std::unique_ptr<item>> getInventory() { return inventory; }

	void setItemQty(); // Follower inventory. Will be overridden in hero class
	void printEquipment();
	void printInventory(); // Follower inventory. Will be overridden in hero class

};

