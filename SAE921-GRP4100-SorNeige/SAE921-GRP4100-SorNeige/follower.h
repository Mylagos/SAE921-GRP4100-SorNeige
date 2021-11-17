#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include "Stats.h"
#include "Item.h"
#include "Equipment.h"

class Follower
{
private:
	std::string name_; // Follower name_ (Not used in hero)
	std::string description_; // Follower description_ (Not used in hero)

	Stats currentStat_; //named currentstat to be easier to use in character
	Stats maxStats_;

	std::vector<std::unique_ptr<Item>> inventory_;

	int gold_;
	int provisions_;

	int potionQty_;
	int equipmentQty_;
	int qItemQty_;

public:
	void setName(std::string name){this->name_ = name;}
	std::string getName() const { return name_; }

	void setDescription(std::string description) { this->description_ = description; }
	std::string getDescription() const { return description_; }

	std::vector<std::unique_ptr<Item>> getInventory() const { return inventory_; }

	void setItemQty(); // Follower inventory_. Will be overridden in hero class
	std::stringstream printInventory(); // Follower inventory_. Will be overridden in hero class
	std::stringstream printEquipment();
	std::stringstream printPotions();

};

