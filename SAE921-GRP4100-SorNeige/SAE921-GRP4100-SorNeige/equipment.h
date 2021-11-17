#pragma once
#include "item.h"
#include "Stats.h"


class equipment: public item
{
private:
	
	bool isEquipped  = false;
	stats Stats;

public:

	equipment(std::string, std::string, itemTag, int, int, int);

	bool getEquipped();
	void equip();
	void unequip();

	stats& getStats();
	void setStats(stats::name_stat s, int value)
	{
		Stats.set_stat(s, value);
	}
	

	void inspect() override;
};

