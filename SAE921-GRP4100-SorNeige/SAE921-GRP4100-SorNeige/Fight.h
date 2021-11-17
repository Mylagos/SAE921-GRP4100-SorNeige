#pragma once

#include "Follower.h"
#include "Monster.h"

class Fight
{
private:

	std::vector<Monster> monster_vector_;
	bool end_fight_ = false;

public:
	Fight() = default;
	Fight(int&, std::string, int, int);
	Fight(int&, std::string, int, int, std::string, int, int);

	~Fight();


	void to_fight(int&);
	void fighting_round();

	bool luck_check();
	bool ability_check();
	bool oposing_abality_check();

};
