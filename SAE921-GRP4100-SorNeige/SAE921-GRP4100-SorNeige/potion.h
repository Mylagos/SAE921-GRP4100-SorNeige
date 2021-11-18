#pragma once
#include "Item.h"
#include "Stats.h"

class Potion: public Item 
{
private:

	Stats::name_stat potStat_;
	int dose_ = 2;
	int max_dose_ = 2;

public:

	Potion(Stats::name_stat);
	Potion(std::string, std::string, itemTag, Stats::name_stat);
	Potion(std::string, std::string, itemTag, Stats::name_stat, int);

	Stats::name_stat get_pot_stat();
	int get_dose() override;
	int get_max_dose() override;

	int add_dose(int) override;




	




};