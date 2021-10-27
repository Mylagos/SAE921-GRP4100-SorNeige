#pragma once
#include <string>

class item
{
private:
	enum itemTag
	{
		weapon,
		quest_item,
		potion,

	};
	std::string name;
	std::string itemDescription;
	itemTag tag;

public:

	virtual std::string getFunction();
	virtual void usingItem();
	virtual void loseItem();
};

