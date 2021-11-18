#include "Fight.h"

void Fight::fighting_loop(Follower& character)
{
	do
	{
		fighting_round(character);
		if (true/**/)
		{
			end_fight_ = true;
		}

	} while (!end_fight_);


}


void Fight::fighting_round(Follower& character)
{

	action_check(character);
	//action check
	//action is check bag, block, attack or flee if possible.
	//loop if the player use bag, or anything else.

	//fight
	//opposing ability check on target in blocking state or attacking state
	//luck check in auto.
	//dealing damage on monster
	//check if monster is alive(if not finish the fight)
	//monster opposing ability check
	//luck check auto
	//dealing damage
	//check if we are death

}

