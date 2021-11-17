#include "item.h"

item::item(std::string name, std::string description, itemTag tag)
{
	this->name_ = name;
	this->item_description_ = description;
	this->tag_ = tag;

}


std::string item::get_name()
{
	return this->name_;
}

item::itemTag item::get_tag()
{
	return this->tag_;
}

std::string item::get_description()
{
	return this->item_description_;
}

int item::get_quantity()
{
	return this->quantity_;
}

int item::add_quantity(int adding_value)
{
	quantity_ = quantity_ + adding_value;
	return this->quantity_;
}

int item::set_quantity(int new_quantity)
{
	if (new_quantity >= 0)
	{
		quantity_ = new_quantity;
	}
	else
	{
		quantity_ = 0;
	}

	return this->quantity_;
}

