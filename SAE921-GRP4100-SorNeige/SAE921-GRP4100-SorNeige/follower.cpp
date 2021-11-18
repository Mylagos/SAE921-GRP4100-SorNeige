#include "Follower.h"
#include "Equipment.h"
#include "Potion.h"

int Follower::returnItemQuantity(Item::itemTag itemTag)
{
    // Goes trough the Inventory and adds +1 to the count int for each item with the tag specified
    int count = 0;
    for (const auto& i : inventory_)
    {
        switch (itemTag)
        {
        case Item::itemTag::weapon:
            count++;
        case Item::itemTag::potion:
            count++;
        case Item::itemTag::quest_item:
            count++;
        }
    }
	return count;
}

std::stringstream Follower::printEquipment()
{
    int j=1;
    std::stringstream retu;
    retu << "You decide to look trough your items." << std::endl;
    // Goes trough the inventory and prints out each Equipment and Quest Item name and stats if equipment
    for (const auto& i : inventory_)
    {
        if (auto* myEquipment = dynamic_cast<Equipment*>(i.get()))
        {
            retu << "[" << j << "]" << " " + myEquipment->get_name() << ". ("
        			<< myEquipment->printItemStats().str() << ")" << std::endl;
        }
        if (i->get_tag() == Item::itemTag::quest_item)
        {
            retu << "[" << j << "]" << " " + i->get_name() << std::endl;
        }
    }
    return retu;
}

std::stringstream Follower::printPotions()
{
    int j = 1;
    std::stringstream ret;
    ret << "You look trough your potions" << std::endl;
    // Goes trough the inventory and prints out every potion name and doses
    for (const auto& i : inventory_)
    {
        if (auto* myPotion = dynamic_cast<Potion*>(i.get()))
        {
            ret << "[" << j << "]" << " " + myPotion->get_name() << ". Doses left :" << myPotion->get_dose() <<  std::endl;
        }
    }
    return std::stringstream();
}

std::stringstream Follower::printInventory()
{
    // Prints out info on the player
    std::stringstream ret;
    ret << "You decide to take a moment to reflect upon yourself and look trough your bags" << std::endl << std::endl;
    ret << "Hability " << this->currentStat_.get_stat(Stats::name_stat::ability) << "/" << this->maxStats_.get_stat(Stats::name_stat::ability) << std::endl;
    ret << "Stamina " << this->currentStat_.get_stat(Stats::name_stat::stamina) << "/" << this->maxStats_.get_stat(Stats::name_stat::stamina) << std::endl;
    ret << "Luck " << this->currentStat_.get_stat(Stats::name_stat::luck) << "/" << this->maxStats_.get_stat(Stats::name_stat::luck) << std::endl;
    ret << std::endl;
    ret << "Your bag contains:" << std::endl;
    ret << this->gold_ << " gold." << std::endl;
    ret << this->provisions_ << " provision." << std::endl;
    ret << returnItemQuantity(Item::itemTag::potion) << " potion." << std::endl;
    ret << returnItemQuantity(Item::itemTag::weapon) << " Item." << std::endl;
    ret << "Which pouch do you want to go trough?" << std::endl

        << "[1] : Items. [2] : Potions. [3] : Help." << std::endl;


    return std::stringstream();
}


