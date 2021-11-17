#pragma once
#include "item.h"
#include "Stats.h"

class potion: public item 
{
private:

	Stats::name_stat potStat;
	int dose;
	int maxDose;

public:
	potion(std::string, std::string, itemTag, Stats::name_stat);
	potion(std::string, std::string, itemTag, Stats::name_stat, int);

	Stats::name_stat getPotStat();
	int getDose();
	int getMaxDose();

	int addDose();









};