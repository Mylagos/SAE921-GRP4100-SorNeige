#include "Item.h"



Item::Item(std::string name, std::string description, itemTag tag)
{
	this->name_ = name;
	this->item_description_ = description;
	this->tag_ = tag;

}


std::string Item::get_name()
{
	return this->name_;
}

Item::itemTag Item::get_tag()
{
	return this->tag_;
}

std::string Item::get_description()
{
	return this->item_description_;
}

int Item::get_quantity()
{
	return this->quantity_;
}

int Item::add_quantity(int adding_value)
{
	quantity_ = quantity_ + adding_value;
	return this->quantity_;
}

int Item::set_quantity(int new_quantity)
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

