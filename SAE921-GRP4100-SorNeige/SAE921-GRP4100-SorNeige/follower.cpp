#include "follower.h"
#include "Equipment.h"

void follower::setItemQty()
{
    for (const auto& i : inventory)
    {
        
        i.get()->get_tag();
        
        item ooo = *i;
        if (ooo.get_tag() == item::itemTag::weapon)
        {
            this->weaponQty++;
        }
        if (ooo.get_tag() == item::itemTag::quest_item)
        {
            this->qItemQty++;
        }
        if (ooo.get_tag() == item::itemTag::potion)
        {
            this->potionQty++;
        }
    }
}

std::stringstream follower::printEquipment()
{
    int j=1;
    std::stringstream retu;
    for (const auto& i : inventory)
    {
        item ooo = *i;
        Equipment* eee = static_cast<Equipment*>(i.get());
        if (ooo.get_tag() == item::itemTag::weapon)
        {
            retu << "[" << j << "]" << " " + ooo.get_name() << ". ("
        			<< eee->getStats().getStat(Stats::name_stat::ability);
            //static_cast<Equipment*>(i.get())->getStats().setStat(stats_::name_stat::ability, 10);
        }
    }
    return retu;
}

std::stringstream follower::printInventory()
{
    return std::stringstream();
}


