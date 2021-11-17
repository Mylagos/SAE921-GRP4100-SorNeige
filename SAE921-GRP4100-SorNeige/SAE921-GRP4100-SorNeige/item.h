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
	
<<<<<<< HEAD
	std::string name_;//name_ of the item
	std::string item_description_;//simple description of the item
	itemTag tag_;//item type
	int quantity_ = 1;
=======
	std::string name;//name_ of the item
	std::string itemDescription;//simple description_ of the item
	itemTag tag;//item type
	int quantity;
>>>>>>> 05c08ca9a08d230393f685579bd0c5deb44d793c

public:

	item() = default;
	item(std::string, std::string, itemTag); //simple constructor for creating no useable object, like quest item.

<<<<<<< HEAD
	std::string get_name();//give the name_ of the object
	itemTag get_tag();//give the Tag of the object
	std::string get_description();//give the description of the object
=======
	std::string getName();//give the name_ of the object
	itemTag getTag();//give the Tag of the object
	std::string getDescription();//give the description_ of the object
>>>>>>> 05c08ca9a08d230393f685579bd0c5deb44d793c

	int get_quantity();//get quantity_ of the object.
	int add_quantity(int);//add a number to the quantity_, can be positive or negative
	int set_quantity(int);//set quantity_ of the object, can only be positive(if negative quantity_ go to 0)

	virtual void inspect();
	

};

