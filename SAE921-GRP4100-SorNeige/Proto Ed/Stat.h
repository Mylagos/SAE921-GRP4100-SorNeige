#pragma once
#include <iostream>
class Stat
{
private:
	int hability_;
	int vitality_;
	int luck_;
public:
	Stat(int hability, int vitality, int luck);

#pragma region GETTERS SETTERS
	void setHability(int n) { hability_ = n; }
	int getHability() { return hability_; }

	void setVitality(int n) { vitality_ = n; }
	int getVitality() { return vitality_; }

	void setLuck(int n) { luck_ = n; }
	int getLuck() { return luck_; }
#pragma endregion END

	// CHARACTERS Methods?


	// ITEMS Methods?

	std::string returnStatsUsed(); // used in potion.cpp

	int printHability(){} // used to inspect weapon ,see weapon Stats (todo)



};

