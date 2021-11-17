<<<<<<< HEAD
#include "follower.h"
#include "Equipment.h"
=======
#include "Follower.h"
#include "equipment.h"
>>>>>>> 05c08ca9a08d230393f685579bd0c5deb44d793c

void Follower::setItemQty()
{
    for (const auto& i : inventory_)
    {
        
        i.get()->get_tag();
        
        item ooo = *i;
        if (ooo.get_tag() == item::itemTag::weapon)
        {
            this->weaponQty_++;
        }
        if (ooo.get_tag() == item::itemTag::quest_item)
        {
            this->qItemQty_++;
        }
        if (ooo.get_tag() == item::itemTag::potion)
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
        Equipment* eee = static_cast<Equipment*>(i.get());
        if (ooo.get_tag() == item::itemTag::weapon)
        {
<<<<<<< HEAD
            retu << "[" << j << "]" << " " + ooo.get_name() << ". ("
        			<< eee->getStats().getStat(Stats::name_stat::ability);
            //static_cast<Equipment*>(i.get())->getStats().setStat(stats_::name_stat::ability, 10);
=======
            retu << "[" << j << "]" << " " + ooo.getName() << ". ("
        			<< "" /*PLACEHOLDER FUNCTION STATS ITEMS*/;
            //static_cast<equipment*>(i.get())->getStats().setStat(Stats::name_stat::ability, 10);
>>>>>>> 05c08ca9a08d230393f685579bd0c5deb44d793c
        }
    }
    return retu;
}

std::stringstream Follower::printInventory()
{
    return std::stringstream();
}


