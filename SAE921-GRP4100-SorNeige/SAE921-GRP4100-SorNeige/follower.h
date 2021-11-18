#pragma once
#include <iostream>
#include <vector>
#include <sstream>

#include "Stats.h"
#include "Item.h"

class Follower
{
private:
	std::string name_; // FFollower Variables
	std::string description_; // Follower Variables

	Stats currentStat_;
	Stats maxStats_;

	std::vector<std::unique_ptr<Item>> inventory_;

	// Values used in the printInventory()
	int gold_;
	int provisions_;

public:
	void setName(std::string name){this->name_ = name;}
	std::string getName() const { return name_; }

	void setDescription(std::string description) { this->description_ = description; }
	std::string getDescription() const { return description_; }

	// Returns the number of items in the inventory matching the specified tag
	int returnItemQuantity(Item::itemTag itemTag);

	// These tree methods simply prints out the inventory "Menus"
	// Main inventory menu
	std::stringstream printInventory();
	// Equipment menu
	std::stringstream printEquipment();
	// Potions menu
	std::stringstream printPotions();


};

