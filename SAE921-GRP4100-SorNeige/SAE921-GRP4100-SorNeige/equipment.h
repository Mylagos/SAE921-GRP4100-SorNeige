#pragma once
#include "item.h"
#include "stats.h"


class equipment: public item
{
private:
	
	bool isEquipped;

public:
	stats stats;

	equipment(std::string, std::string, itemTag, int, int, int);

	bool getEquipped();
	void equip();
	void unequip();

};

