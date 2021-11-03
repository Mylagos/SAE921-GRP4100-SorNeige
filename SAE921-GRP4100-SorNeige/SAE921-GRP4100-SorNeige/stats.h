#pragma once
#include <list>
#include <string>

class stats
{

public:
	enum class name_stat
	{
		ability = 0,
		stamina,
		luck
	};
private:
	//main stat for all the game is here
	int value_ability = 0;
	int value_stamina = 0;
	int value_luck = 0;

	

	
public:
	
	stats();//constructor that set all stat by default to 0
	stats(int, int, int);//constructor is for setting specific stat

	int getStat(name_stat);//get the value of the given stats
	void setStat(name_stat, int);//set the value of the given stats
	int addStat(name_stat, int);//add a value of the given stats, can be positive or negative.
	void addAllStats(stats);//add the value off the class stats given
	void subAllStats(stats);//subtract the value off the class stats given





};

