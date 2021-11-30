#include "GameManager.h"

GameManager::GameManager(std::string character_name)
{
	//if a memory found load the memory.
	//create the player character.
		//define the base line of the character(name).
	player_character_.setName(character_name);
		//launch the stats of the player.
	roll_player_character_stats();
		//TODO//give them a base inventory.
	//create the memory for the history.
	std::cout << player_character_.getName() << "\n"
		<< "you have " << player_character_.get_one_currentStat(Stats::name_stat::stamina) << " stamina \n"
		<< "you have " << player_character_.get_one_currentStat(Stats::name_stat::ability) << " ability \n"
		<< "you have " << player_character_.get_one_currentStat(Stats::name_stat::luck) << " luck \n";
	


}

void GameManager::roll_player_character_stats()
{
	player_character_.set_to_maxStat(Stats::name_stat::stamina, roll_new_stat(Stats::name_stat::stamina));
	player_character_.set_to_currentStat(Stats::name_stat::stamina, player_character_.get_one_maxStat(Stats::name_stat::stamina));

	player_character_.set_to_maxStat(Stats::name_stat::ability, roll_new_stat(Stats::name_stat::ability));
	player_character_.set_to_currentStat(Stats::name_stat::ability, player_character_.get_one_maxStat(Stats::name_stat::ability));

	player_character_.set_to_maxStat(Stats::name_stat::luck, roll_new_stat(Stats::name_stat::luck));
	player_character_.set_to_currentStat(Stats::name_stat::luck, player_character_.get_one_maxStat(Stats::name_stat::luck));

}

int GameManager::roll_new_stat(Stats::name_stat name_stat)
{
	int new_stat = 0;

	srand(time(nullptr));

	switch (name_stat)
	{
	case Stats::name_stat::ability:

		new_stat = 6 + rand() % 4 + rand() % 4 ;// random value between 6 and 12, probably 9(2 value)
		break;
	case Stats::name_stat::stamina:
		new_stat = 14 + rand() % 4 + rand() % 4 + rand() % 4 ; //random value between 14 and 23, probably 18-19(3 value)
		break;
	case Stats::name_stat::luck:
		new_stat = 5 + rand() % 5 ; //random value between 5 and 9, 7 in the middle.
		break;

	}

	return new_stat;
}








