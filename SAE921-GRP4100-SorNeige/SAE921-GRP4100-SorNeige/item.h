#pragma once
#include <string>

#include "Stats.h"

class Item
{
public:
	enum class itemTag
	{
		weapon,
		quest_item,
		potion

	};
protected:

	std::string name_;//name_ of the Item
	std::string item_description_;//simple description of the Item
	itemTag tag_;//Item type
	int quantity_ = 1;

public:
	Item() = default;
	Item(std::string, std::string, itemTag); //simple constructor for creating no useable object, like quest Item.

	std::string get_name();//give the name_ of the object
	itemTag get_tag();//give the Tag of the object
	std::string get_description();//give the description of the object

	int get_quantity();//get quantity_ of the object.
	int add_quantity(int);//add a number to the quantity_, can be positive or negative
	int set_quantity(int);//set quantity_ of the object, can only be positive(if negative quantity_ go to 0)

	virtual  ~Item() = default;


};

