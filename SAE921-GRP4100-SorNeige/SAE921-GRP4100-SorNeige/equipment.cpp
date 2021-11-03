#include "equipment.h"
bool equipment::getEquipped()
{
	return this->isEquipped;
}

void equipment::equip()
{
	this->isEquipped = true;
}

void equipment::unequip()
{
	this->isEquipped = false;
}

