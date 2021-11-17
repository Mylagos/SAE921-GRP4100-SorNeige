#pragma once
#include <list>
#include <string>

class stats
{

private:
	//main stat for all the game is here
	int value_ability_ = 0;
	int value_stamina_ = 0;
	int value_luck_ = 0;

	

	
public:

	enum class name_stat
	{
		ability = 0,
		stamina,
		luck
	};

	stats();//constructor that set all stat by default to 0
	stats(int, int, int);//constructor is for setting specific stat

	int get_stat(name_stat);//get the value of the given stats
	void set_stat(name_stat, int);//set the value of the given stats
	int add_stat(name_stat, int);//add a value of the given stats, can be positive or negative.
	void add_all_stats(stats);//add the value off the class stats given
	void sub_all_stats(stats);//subtract the value off the class stats given





};

