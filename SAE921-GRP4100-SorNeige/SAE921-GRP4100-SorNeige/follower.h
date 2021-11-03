#pragma once
#include <iostream>
#include <vector>

#include "stats.h"
#include "item.h"

class follower
{
private:
	std::string name; // Follower name (Not used in hero)
	std::string description; // Follower description (Not used in hero)

	stats currentStat; //named currentstat to be easier to use in character

	std::vector<item> inventory;

public:
	void setName(std::string name_){this->name = name_;}
	std::string getName() { return name; }

	void setDescription(std::string description_) { this->description = description_; }
	std::string getDescription() { return description; }

	void printInventory(); //Will be overridden in hero class
};

