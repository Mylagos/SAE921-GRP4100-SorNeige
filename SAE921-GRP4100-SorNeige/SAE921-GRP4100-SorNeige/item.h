#pragma once
#include <string>

class item
{
public:
	enum class itemTag
	{
		weapon,
		quest_item,
		potion

	};
protected:
	
	std::string name;//name_ of the item
	std::string itemDescription;//simple description_ of the item
	itemTag tag;//item type
	int quantity;

public:

	item();
	item(std::string, std::string, itemTag); //simple constructor for creating no useable object, like quest item.

	std::string getName();//give the name_ of the object
	itemTag getTag();//give the Tag of the object
	std::string getDescription();//give the description_ of the object

	int getQuantity();//get quantity of the object.
	int addQuantity(int);//add a number to the quantity, can be positive or negative
	int setQuantity(int);//set quantity of the object, can only be positive(if negative quantity go to 0)

	virtual void inspect();
	

};

