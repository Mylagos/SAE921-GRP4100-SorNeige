#include "item.h"

item::item(std::string name_, std::string description_, itemTag tag_)
{
	this->name = name_;
	this->itemDescription = description_;
	this->tag = tag_;

}


std::string item::getName()
{
	return this->name;
}

item::itemTag item::getTag()
{
	return this->tag;
}

std::string item::getDescription()
{
	return this->itemDescription;
}

int item::getQuantity()
{
	return this->quantity;
}

int item::addQuantity(int addingValue_)
{
	quantity = quantity + addingValue_;
	return this->quantity;
}

int item::setQuantity(int newQuantity_)
{
	if (newQuantity_ >= 0)
	{
		quantity = newQuantity_;
	}
	else
	{
		quantity = 0;
	}

	return this->quantity;
}

