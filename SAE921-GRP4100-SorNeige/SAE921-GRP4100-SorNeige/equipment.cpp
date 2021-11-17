#include "Equipment.h"

Equipment::Equipment(std::string& name, std::string& description, itemTag& tag, int ability, int stamina, int luck)
{

	this->name_ = name;
	this->item_description_ = description;
	this->tag_ = tag;
	this->stats_.set_stat(Stats::name_stat::ability, ability);
	this->stats_.set_stat(Stats::name_stat::stamina, stamina);
	this->stats_.set_stat(Stats::name_stat::luck, luck);

}


bool Equipment::get_equipped()
{
	return this->is_equipped_;
}

void Equipment::equip()
{
	this->is_equipped_ = true;
}

void Equipment::unequip()
{
	this->is_equipped_ = false;
}

Stats& Equipment::getStats()
{
	return this->stats_;
}
