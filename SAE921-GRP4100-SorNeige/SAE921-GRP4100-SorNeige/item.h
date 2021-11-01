#pragma once
#include <string>

class item
{
public:
	enum itemTag
	{
		weapon,
		quest_item,
		potion,

	};
private:
	
	std::string name;//name of the item
	std::string itemDescription;//simple description of the item
	itemTag tag;//item type
	int quantity;

public:

	item(std::string, std::string, itemTag); //simple constructor for creating no useable object, like quest item.

	std::string getFunction();//this is for getting function or description of the item.
	void loseItem();//this is for deleting the item.
};

