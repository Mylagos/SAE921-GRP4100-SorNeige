#pragma once
#include "item.h"
#include "Stats.h"


class equipment: public item
{
private:
	
	bool isEquipped  = false;
	Stats Stats;

public:

	equipment(std::string, std::string, itemTag, int, int, int);

	bool getEquipped();
	void equip();
	void unequip();

	Stats& getStats();
	void setStats(Stats::name_stat s, int value)
	{
		Stats.set_stat(s, value);
	}
	

	void inspect() override;
};

