#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include "Stats.h"
#include "Item.h"

class Follower
{
private:
	std::string name_; // Follower name_ (Not used in hero)
	std::string description_; // Follower description_ (Not used in hero)

	Stats currentStat_; //named currentstat to be easier to use in character
	Stats maxStats_;

	std::vector<std::unique_ptr<Item>> inventory_;

	// Values used in the various inventory prints
	int gold_;
	int provisions_;

public:
	void setName(std::string name){this->name_ = name;}
	std::string getName() const { return name_; }

	void setDescription(std::string description) { this->description_ = description; }
	std::string getDescription() const { return description_; }


	void setItemQty(); // Follower inventory_. Will be overridden in hero class

	// These tree methods simply prints out the inventory "Menus"
	// Main inventory menu
	std::stringstream printInventory();
	// Equipment menu
	std::stringstream printEquipment();
	// Potions menu
	std::stringstream printPotions();


	int potionQty();
	int equipmentQty();
	int qItemQty();

};

