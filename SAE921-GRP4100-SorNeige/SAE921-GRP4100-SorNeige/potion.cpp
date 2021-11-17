#include "Potion.h"

Potion::Potion(std::string name, std::string item_description, itemTag tag, Stats::name_stat stat)
{
	this->name_ = name;
	this->item_description_ = item_description;
	this->tag_ = tag;
	this->potStat_ = stat;

}

Potion::Potion(std::string name, std::string item_description, itemTag tag, Stats::name_stat stat, int dose)
{
	this->name_ = name;
	this->item_description_ = item_description;
	this->tag_ = tag;
	this->potStat_ = stat;
	this->dose_ = dose;
}
