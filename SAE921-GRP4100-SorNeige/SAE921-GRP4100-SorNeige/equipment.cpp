#include "equipment.h"

equipment::equipment(std::string name_, std::string description_, itemTag tag_, int ability_, int stamina_, int luck_)
{

	this->name = name_;
	this->itemDescription = description_;
	this->tag = tag_;
	isEquipped = false;
	this->Stats.setStat(stats::name_stat::ability, ability_);
	this->Stats.setStat(stats::name_stat::stamina, stamina_);
	this->Stats.setStat(stats::name_stat::luck, luck_);

}


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

stats equipment::getStats()
{
	return this->Stats;
}
