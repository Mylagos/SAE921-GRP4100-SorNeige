#pragma once
#include "item.h"
#include "Stats.h"

class Potion: public item 
{
private:

	Stats::name_stat potStat_;
	int dose_;
	int maxDose_;

public:
	Potion(std::string, std::string, itemTag, Stats::name_stat);
	Potion(std::string, std::string, itemTag, Stats::name_stat, int);

	Stats::name_stat get_pot_stat();
	int get_dose();
	int get_max_dose();

	int add_dose();









};