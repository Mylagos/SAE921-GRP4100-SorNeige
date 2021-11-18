#pragma once
#include <sstream>

#include "Item.h"
#include "Stats.h"
#include "iostream"



class Equipment: public Item
{
private:
	
	bool is_equipped_  = false;
	Stats stats_;

public:

	Equipment(std::string&, std::string&, itemTag&, int, int, int);

	bool get_equipped() override;
	void equip() override;
	void unequip() override;
	Stats& getStats() override;

	void set_stats(Stats::name_stat s, int value) override;
	std::stringstream printItemStats() override;

	
};

