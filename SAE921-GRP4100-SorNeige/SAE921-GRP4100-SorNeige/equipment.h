#pragma once
#include "item.h"
#include "Stats.h"
#include "iostream"



class Equipment: public item
{
private:
	
	bool is_equipped_  = false;
	Stats stats_;

public:

	Equipment(std::string&, std::string&, itemTag&, int, int, int);

	bool get_equipped();
	void equip();
	void unequip();

	Stats& getStats();
	void set_stats(Stats::name_stat s, int value)
	{
		stats_.set_stat(s, value);
	}
	
	
	void inspect() override;
};

