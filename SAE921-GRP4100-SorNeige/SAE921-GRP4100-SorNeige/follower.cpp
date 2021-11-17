#include "Follower.h"

void Follower::setItemQty()
{
    for (const auto& i : inventory_)
    {
        
        i.get()->get_tag();
        
        Item ooo = *i;
        if (ooo.get_tag() == Item::itemTag::weapon)
        {
            this->equipmentQty_++;
        }
        if (ooo.get_tag() == Item::itemTag::quest_item)
        {
            this->qItemQty_++;
        }
        if (ooo.get_tag() == Item::itemTag::potion)
        {
            this->potionQty_++;
        }
    }
}

std::stringstream Follower::printEquipment()
{
    int j=1;
    std::stringstream retu;
    retu << "You decide to look trough your items." << std::endl;
    for (const auto& i : inventory_)
    {
        Item item = *i;
        Equipment* equipmentPtr = static_cast<Equipment*>(i.get());

        if (item.get_tag() == Item::itemTag::weapon)
        {
            retu << "[" << j << "]" << " " + item.get_name() << ". ("
        			<< equipmentPtr->printItemStats().str() << ")" << std::endl;
            //static_cast<Equipment*>(i.get())->getStats().setStat(stats_::name_stat::ability, 10);
        }
    }
    return retu;
}

std::stringstream Follower::printPotions()
{
    int j = 1;
    std::stringstream ret;
    ret << "You look trough your potions" << std::endl;
    for (const auto& i : inventory_)
    {
        Item item = *i;
        Equipment* equipmentPtr = static_cast<Equipment*>(i.get());

        if (item.get_tag() == Item::itemTag::potion)
        {
            ret << "[" << j << "]" << " " + item.get_name() << std::endl;
            //static_cast<Equipment*>(i.get())->getStats().setStat(stats_::name_stat::ability, 10);
        }
    }
    return std::stringstream();
}

std::stringstream Follower::printInventory()
{
    std::stringstream ret;
    ret << "You decide to take a moment to reflect upon yourself and look trough your bags" << std::endl << std::endl;
    ret << "Hability " << this->currentStat_.get_stat(Stats::name_stat::ability) << "/" << this->maxStats_.get_stat(Stats::name_stat::ability) << std::endl;
    ret << "Stamina " << this->currentStat_.get_stat(Stats::name_stat::stamina) << "/" << this->maxStats_.get_stat(Stats::name_stat::stamina) << std::endl;
    ret << "Luck " << this->currentStat_.get_stat(Stats::name_stat::luck) << "/" << this->maxStats_.get_stat(Stats::name_stat::luck) << std::endl;
    ret << std::endl;
    ret << "Your bag contains:" << std::endl;
    ret << this->gold_ << " gold." << std::endl;
    ret << this->provisions_ << " provision." << std::endl;
    ret << this->potionQty_ << " potion." << std::endl;
    ret << this->equipmentQty_ << " item." << std::endl;
    ret << "Which pouch do you want to go trough?" << std::endl

        << "[1] : Items. [2] : Potions. [3] : Help." << std::endl;


    return std::stringstream();
}


