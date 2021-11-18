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


	void fighting_loop(Follower&);
	void fighting_round(Follower&);

	std::stringstream action_check(Follower&);
	std::stringstream check_bag(Follower&);

	bool luck_check();
	bool ability_check();
	bool oposing_abality_check();

};
