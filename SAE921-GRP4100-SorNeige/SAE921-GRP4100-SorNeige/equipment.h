#pragma once
#include "item.h"
#include "stats.h"


class equipment: public item
{
private:
	
	bool isEquipped;

public:

	stats stats;

	bool getEquipped();
	void equip();
	void unequip();

};

