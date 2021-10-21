#pragma once
#include "Stat.h"

class Hero
{
private:
	/*int hability_, maxHability_;
	int vitality_, maxVitality_;
	int luck_, maxLuck_;*/

	Stat currentStat_;
	Stat maxStat_;
	// TODO getters setters pour ces variables

public:
	// GETTERS AND SETTERS
#pragma region GETTERS AND SETTERS
	/*void setHability(int n) { hability_ = n; }
	int getHability() { return hability_; }

	void setMaxHability(int n) { maxHability_ = n; }
	int getMaxHability() { return maxHability_; }


	void setVitality(int n) { vitality_ = n; }
	int getVitality() { return vitality_; }

	void setMaxVitality(int n) { maxVitality_ = n; }
	int getMaxVitality() { return maxVitality_; }


	void setLuck(int n) { luck_ = n; }
	int getLuck() { return luck_; }

	void setMaxLuck(int n) { maxLuck_ = n; }
	int getMaxLuck() { return maxLuck_; }*/
#pragma endregion END

	bool checkHability();
	bool checkVitality();
	bool checkLuck();

};

