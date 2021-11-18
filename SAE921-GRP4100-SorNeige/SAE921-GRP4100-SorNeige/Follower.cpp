#include "Follower.h"
#include "Equipment.h"
#include "Potion.h"

int Follower::returnItemQuantity(Item::itemTag itemTag)
{
    // Goes trough the Inventory and adds +1 to the count int for each item with the tag specified
    int count = 0;
    for (const auto& i : inventory_)
    {
        if (itemTag == i->get_tag())
        {
            count++;
        }
    }
	return count;
}

std::stringstream Follower::printEquipment()
{
    bool no_item = true;
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
            no_item = false;
        }
        if (i->get_tag() == Item::itemTag::quest_item)
        {
            retu << "[" << j << "]" << " " + i->get_name() << std::endl;
            no_item = false;
        }
      
    }
    if (no_item)
    {
        retu << "You don't have any item!\n";
    }
    return retu;
}

std::stringstream Follower::printPotions()
{
    bool no_item = true;
    int j = 1;
    std::stringstream ret;
    ret << "You look trough your potions" << std::endl;
    // Goes trough the inventory and prints out every potion name and doses
    for (const auto& i : inventory_)
    {
        if (auto* myPotion = dynamic_cast<Potion*>(i.get()))
        {
            ret << "[" << j << "]" << " " + myPotion->get_name() << ". Doses left :" << myPotion->get_dose() <<  std::endl;
            no_item = false;
        }
    }
    if (no_item)
    {
        ret << "You don't have any potions!\n";
    }
    return ret;
}



std::stringstream Follower::printInventory()
{
    // Prints out info on the player
    std::stringstream ret;
    ret << "You decide to take a moment to reflect upon yourself and look trough your bags" << std::endl << std::endl;
    ret << "Ability " << this->currentStat_.get_stat(Stats::name_stat::ability) << "/" << this->maxStats_.get_stat(Stats::name_stat::ability) << std::endl;
    ret << "Stamina " << this->currentStat_.get_stat(Stats::name_stat::stamina) << "/" << this->maxStats_.get_stat(Stats::name_stat::stamina) << std::endl;
    ret << "Luck " << this->currentStat_.get_stat(Stats::name_stat::luck) << "/" << this->maxStats_.get_stat(Stats::name_stat::luck) << std::endl;
    ret << std::endl;
    ret << "Your bag contains:" << std::endl;
    ret << this->gold_ << " gold." << std::endl;
    ret << this->provisions_ << " provision." << std::endl;
    ret << returnItemQuantity(Item::itemTag::potion) << " potion." << std::endl;
    ret << returnItemQuantity(Item::itemTag::weapon) + returnItemQuantity(Item::itemTag::quest_item) << " Item." << std::endl;
    ret << "Which pouch do you want to go trough?" << std::endl

        << "[1] : Items. [2] : Potions. [3] : Help." << std::endl;


    return ret;
}

void Follower::add_inventory(const std::string name,const std::string description)
{
    inventory_.push_back(std::make_unique<Item>(name, description, Item::itemTag::quest_item));
}

void Follower::add_inventory(const std::string name, const std::string description,const int ability,const int stamina,const int luck)
{
    inventory_.push_back(std::make_unique<Equipment>(name,description, Item::itemTag::weapon,ability, stamina, luck));
}

void Follower::add_inventory(const std::string name,const std::string description,const Stats::name_stat stats)
{
    inventory_.push_back(std::make_unique<Potion>(name,description, Item::itemTag::potion, stats));
}

void Follower::add_inventory(const Stats::name_stat stats)
{
    inventory_.push_back(std::make_unique<Potion>(stats));

}
