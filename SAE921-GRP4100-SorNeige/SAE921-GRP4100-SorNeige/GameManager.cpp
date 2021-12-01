#include "GameManager.h"

GameManager::GameManager()
{
	std::string character_name;
	//create the player character.
	//define the base line of the character(name).
	std::cout << "Good day, we need an name for you to starting this adventure!\n what is your name? > ";
	std::cin >> character_name;
	player_character_.setName(character_name);

	//launch the stats of the player.
	std::cout << "perfect, but we need to give you some stats now:\n";
	system("pause");
	std::cout << "first we go with your stamina, the stamina is use to take damage or do exhaustive task.\n"
		<< "if you go at zero or below stamina, you die\n";
	system("pause");
	player_character_.set_to_maxStat(Stats::name_stat::stamina, roll_new_stat(Stats::name_stat::stamina));
	player_character_.set_to_currentStat(Stats::name_stat::stamina, player_character_.get_one_maxStat(Stats::name_stat::stamina));
	std::cout << "You get " << player_character_.get_one_currentStat(Stats::name_stat::stamina) << " stamina.\n";
	system("pause");
	std::cout << "now you need the ability, the ability it's your capacity to succeed a task, hitting a enemy or blocking a enemy strike.\n"
		<< "better is your ability better you perform.\n";
	system("pause");
	player_character_.set_to_maxStat(Stats::name_stat::ability, roll_new_stat(Stats::name_stat::ability));
	player_character_.set_to_currentStat(Stats::name_stat::ability, player_character_.get_one_maxStat(Stats::name_stat::ability));
	std::cout << "You get " << player_character_.get_one_currentStat(Stats::name_stat::ability) << " ability.\n";
	system("pause");
	std::cout << "and for the last stat we have your luck, this stats represent your luck to perform critical hit, or have good special event."
		<< "that represent too, if low, your chance to take critical hit and have bad special event.\n";
	system("pause");
	player_character_.set_to_maxStat(Stats::name_stat::luck, roll_new_stat(Stats::name_stat::luck));
	player_character_.set_to_currentStat(Stats::name_stat::luck, player_character_.get_one_maxStat(Stats::name_stat::luck));
	std::cout << "You get " << player_character_.get_one_currentStat(Stats::name_stat::luck) << " luck.\n";
	system("pause");

	//TODO//give them a base inventory.

	std::cout << "now you are ready for the adventure, or almost ready.\n"
		<< "because actually you are nude without any equipment, you need some base equipment if you don't want to die.\n";
	system("pause");
	std::cout << "you can chose the equipment you went to take\n"
		<< "but before that i need to explain two things:\n";
	system("pause");
	std::cout << "first is the provision, it's simple, if you have the time for that you can consume 1 provision for gaining 4 stamina\n"
		<< "second thing is the potion, the potion regenerate 1 stats to full and have two use. sometime it grow your maximum of one stats\n"
		<< "now here, the gear you can chose:\n";
	system("pause");

	std::cout << "\nadventurer gear\n"
		<< "basic equipment, lot of resource\n"
		<< "1 basic sword, 1 leather armors\n"
		<< "10 provision,1 health potion\n"
		<< "1 daggers, 1 lantern\n";
	system("pause");

	std::cout << "\nsoldier gear\n"
		<< "good equipment, with a minimal resource\n"
		<< "1 longsword, 1 breastplate \n"
		<< "2 provision, 1 ability potion \n"
		<< "1 lantern\n";
	system("pause");

	std::cout << "\npathfinder gear\n"
		<< "good compromise between equipment and resource\n"
		<< "1 longsword, 1 gambeson \n"
		<< "6 provision, 1 health potion\n"
		<< "1 daggers, 1 lantern\n";
	system("pause");


	int selected_gear_ = 0;
	std::cout << "you can chose one:\n[1]adventurer gear\n[2]soldier gear\n[3]pathfinder gear\n>";
	do
	{
		std::cin >> selected_gear_;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (selected_gear_ <= 0 || selected_gear_ >= 4)
		{
			std::cout << "you need to enter correct value (between 1-3)\n";
		}
	} while (selected_gear_ <= 0 || selected_gear_ >= 4);

	switch (selected_gear_)
	{
	case 1:
		std::cout << "you chose the adventurer gear!\n";
		player_character_.add_inventory("basic sword", "one of the most basic sword in the world", 0, 0, 0);
		player_character_.add_inventory("leather armors", "a armor made of leather, not the best protection", 0, 0, 0);
		player_character_.add_inventory("health potion", "a red potion that heal stamina", Stats::name_stat::stamina);
		player_character_.setProvisions(10);
		player_character_.add_inventory("dagger", "one of the simplest dagger, very useful");
		player_character_.add_inventory("lantern", "this basic lantern give you light at the darkest place");
		break;
	case 2:
		std::cout << "you chose the soldier gear!\n";
		player_character_.add_inventory("longsword", "a big sword, very useful in combat.", 1, 0, 0);
		player_character_.add_inventory("breastplate","a armor made in steel, this principally protect the chest", 0, 8, 0);
		player_character_.add_inventory("ability potion", "a green potion that restore ability", Stats::name_stat::ability);
		player_character_.setProvisions(2);
		player_character_.add_inventory("lantern", "this basic lantern give you light at the darkest place");
		break;
	case 3:
		std::cout << "you chose the pathfinder gear!\n";
		player_character_.add_inventory("longsword", "a big sword, very useful in combat.", 1, 0, 0);
		player_character_.add_inventory("gambeson", "a armor made cotton, very good first protection", 0, 4, 0);
		player_character_.add_inventory("health potion", "a red potion that heal stamina", Stats::name_stat::stamina);
		player_character_.setProvisions(6);
		player_character_.add_inventory("dagger", "one of the simplest dagger, very useful");
		player_character_.add_inventory("lantern", "this basic lantern give you light at the darkest place");
		break;
	}
}

void GameManager::roll_all_player_character_stats()
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


void GameManager::player_inventory_manager()
{

	player_character_.inventoryManager();

}

void GameManager::game_loop()
{
	bool exit_loop = false;
	do
	{
		this->story_manager();

	} while (!exit_loop);
}

void GameManager::story_manager()
{
	int player_choice = -1;
	switch (chapter_)
	{
	case 0:
		std::cout << "at the northern borders of allansia, winters are extremely harsh.\n"
			<< "the snow is falling in tight flakes, and an icy blizzard freezes to the bones the intrepid travelers who venture into this far-off land.\n"
			<< "waiting MAJ,\n";
		system("pause");
		chapter_ = 1;
		break;

	case 1:
		std::cout
			<< "you arrive at the edge of a crevasse.\n"
			<< "a snow bridge spans it.\n";
		system("pause");
		do
		{
			do {
			std::cout << "\n[1]if you want to cross the crevasse by walking on the snow bridge.\n"
				<< "[2]if you prefer to bypass it\n"
				<< "[0]look at your inventory\n>";
			std::cin >> player_choice;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (player_choice <= -1 || player_choice >= 3)
			{
				std::cout << "you need to enter a good value(0-2)";
			}
		} while (player_choice <= -1 || player_choice >= 3);
			switch (player_choice)
			{
			case 0:
				player_character_.inventoryManager();
				break;
			case 1:
				chapter_ = 335;
				break;
			case 2:
				chapter_ = 310;
				break;
			default:
				std::cout << "\n\n ERRORS CHAPTER 1\n\n";
			}
		} while (!(chapter_ == 335 || chapter_ == 310));
		break;
	default:

		std::cout << "errors incorect narative arc";
		system("pause");
	}
}





