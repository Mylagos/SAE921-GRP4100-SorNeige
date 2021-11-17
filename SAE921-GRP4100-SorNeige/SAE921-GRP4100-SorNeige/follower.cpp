#include "Follower.h"
#include "equipment.h"

void Follower::setItemQty()
{
    for (const auto& i : inventory_)
    {
        
        i.get()->getTag();
        
        item ooo = *i;
        if (ooo.getTag() == item::itemTag::weapon)
        {
            this->weaponQty_++;
        }
        if (ooo.getTag() == item::itemTag::quest_item)
        {
            this->qItemQty_++;
        }
        if (ooo.getTag() == item::itemTag::potion)
        {
            this->potionQty_++;
        }
    }
}

std::stringstream Follower::printEquipment()
{
    int j=1;
    std::stringstream retu;
    for (const auto& i : inventory_)
    {
        item ooo = *i;
        equipment* eee = static_cast<equipment*>(i.get());
        if (ooo.getTag() == item::itemTag::weapon)
        {
            retu << "[" << j << "]" << " " + ooo.getName() << ". ("
        			<< "" /*PLACEHOLDER FUNCTION STATS ITEMS*/;
            //static_cast<equipment*>(i.get())->getStats().setStat(Stats::name_stat::ability, 10);
        }
    }
    return retu;
}

std::stringstream Follower::printInventory()
{
    return std::stringstream();
}


