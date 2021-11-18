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

	//virtual for Equipment
	virtual std::stringstream printItemStats() { std::stringstream ss; return ss; };
	virtual bool get_equipped() { return EXIT_SUCCESS; };
	virtual void equip() = 0;
	virtual void unequip() = 0;
	virtual Stats& getStats() = 0;
	virtual void set_stats(Stats::name_stat s, int value) = 0;

	//virtual for potion
	virtual Stats::name_stat get_pot_stat() = 0;
	virtual int get_dose() = 0;
	virtual int get_max_dose() = 0;
	virtual int add_dose(int) = 0;

};

