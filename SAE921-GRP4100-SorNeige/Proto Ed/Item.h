#pragma once
#include "Hero.h"
#include "Stat.h"
#include<iostream>
#include<vector>

class Item
{
private:
	std::string displayName_;
	Stat itemStats_;
public:
	Item();

#pragma region GETTERS SETTERS
	void setDisplayName(std::string name) { this->displayName_ = name; }
	std::string getDisplayName() { return displayName_; }

	void setItemStat(Stat stats) { this->itemStats_ = stats; }
	Stat getItemStat() { return itemStats_; }
#pragma endregion

	virtual void printInspect();
	virtual void use();

};

