#pragma once
#include <list>
#include <string>

class Stats
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
	int value_ability_ = 0;
	int value_stamina_ = 0;
	int value_luck_ = 0;

	

	
public:

	

	Stats();//constructor that set all stat by default to 0
	Stats(int, int, int);//constructor is for setting specific stat

	int get_stat(name_stat);//get the value of the given stats_
	void set_stat(name_stat, int);//set the value of the given stats_
	int add_stat(name_stat, int);//add a value of the given stats_, can be positive or negative.
	void add_all_stats(Stats);//add the value off the class stats_ given
	void sub_all_stats(Stats);//subtract the value off the class stats_ given





};

