#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include "Stats.h"
#include "item.h"

class Follower
{
private:
	std::string name_; // Follower name_ (Not used in hero)
	std::string description_; // Follower description_ (Not used in hero)

	Stats currentStat_; //named currentstat to be easier to use in character

	std::vector<std::unique_ptr<item>> inventory_;

	int weaponQty_;
	int qItemQty_;
	int potionQty_;

public:
	void setName(std::string name){this->name_ = name;}
	std::string getName() { return name_; }

	void setDescription(std::string description) { this->description_ = description; }
	std::string getDescription() { return description_; }

	std::vector<std::unique_ptr<item>> getInventory() { return inventory_; }

	void setItemQty(); // Follower inventory_. Will be overridden in hero class
	std::stringstream printEquipment();
	std::stringstream printInventory(); // Follower inventory_. Will be overridden in hero class

};

