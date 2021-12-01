#pragma once
#include "Follower.h"
#include "Stats.h"

class GameManager
{
private:
	Follower player_character_{};
	int chapter_ = 0;
public:
	GameManager();//create the player for a first game
	GameManager(std::string character_name);
	//voila fait ce que tu veus


	

	void roll_all_player_character_stats();
	int roll_new_stat(Stats::name_stat);

	void player_inventory_manager();

	void game_loop();

	void story_manager();

	void menu_manager_safe();
	void menu_manager_unsafe();

	
};
