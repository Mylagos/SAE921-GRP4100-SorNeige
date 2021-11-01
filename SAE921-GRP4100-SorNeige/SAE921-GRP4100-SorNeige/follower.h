#pragma once
#include <iostream>
#include <vector>

#include "stats.h"
#include "item.h"

class follower
{
private:
	std::string name;
	std::string description;

	//named currentstat to be easier to use in character
	stats currentStat;

	std::vector<item> inventory;

public:
	void setName(std::string name_){this->name = name_;}
	std::string getName() { return name; }

	void setDescription(std::string description_) { this->description = description_; }
	std::string getDescription() { return description; }

};

