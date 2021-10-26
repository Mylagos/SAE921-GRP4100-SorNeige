#pragma once
#include <list>
#include <string>

class stats
{
private:
	//main stat for all the game is here
	int value_ability = 0;
	int value_stamina = 0;
	int value_luck = 0;

	//simple enum for know what we talking if we went to change stats
	enum name_stat
	{
		ability = 0,
		stamina,
		luck
	};

	
public:
	
	stats();//constructor that set all stat by default to 0
	stats(int, int, int);//constructor is for setting specific stat

	int getStat(name_stat);//use this for get a value of a stat
	void setStat(name_stat, int);//for set a stat to a value
	int addStat(name_stat, int);//for add a + or - value to a stat
	void addAllStats(stats);//for add a another stats class to this stats like a item.





};

