#include "Potion.h"


Potion::Potion(Stats::name_stat stat)
{
	

	switch (stat)
	{
	case Stats::name_stat::ability:

		this->name_ = "Potion of ability";
		break;

	case Stats::name_stat::luck:

		this->name_ = "Potion of luck";
		break;

	case Stats::name_stat::stamina:

		this->name_ = "Potion of stamina";
		break;

	default:
		this->name_ = "Errors enum";
		break;

	}

	this->item_description_ = "une potion pour régénérer une statistique.";
	this->tag_ = itemTag::potion;
	this->potStat_ = stat;
}


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

Stats::name_stat Potion::get_pot_stat()
{
	return potStat_;
}

int Potion::get_dose()
{
	return dose_;
}

int Potion::get_max_dose()
{
	return max_dose_;
}


int Potion::add_dose(int add_value)
{
	if (dose_+add_value >= max_dose_)
	{
		dose_ = max_dose_;
	}
	else {
		dose_ += add_value;
	}

	return dose_;
}



