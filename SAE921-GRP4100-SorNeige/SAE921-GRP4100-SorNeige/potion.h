#pragma once
#include "item.h"
#include "stats.h"

class potion: public item 
{
private:

	stats::name_stat potStat;
	int dose;
	int maxDose;

public:
	potion(std::string, std::string, itemTag, stats::name_stat);
	potion(std::string, std::string, itemTag, stats::name_stat, int);

	stats::name_stat getPotStat();
	int getDose();
	int getMaxDose();

	int addDose();









};