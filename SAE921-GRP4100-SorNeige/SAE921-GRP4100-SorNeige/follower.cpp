#include "follower.h"
#include "equipment.h"
void follower::setItemQty()
{
    for (const auto& i : inventory)
    {
        
        i.get()->getTag()
        
        item ooo = *i;
        if (ooo.getTag() == item::itemTag::weapon)
        {
            this->weaponQty++;
        }
        if (ooo.getTag() == item::itemTag::quest_item)
        {
            this->qItemQty++;
        }
        if (ooo.getTag() == item::itemTag::potion)
        {
            this->potionQty++;
        }
    }
}

void follower::printEquipment()
{
    int j=1;
    for (const auto& i : inventory)
    {
        item ooo = *i;
        equipment* eee = static_cast<equipment*>(i.get());
        if (ooo.getTag() == item::itemTag::weapon)
        {
            std::cout << "[" << j << "]" << " " << ooo.getName() << ". ("
        			<< eee->getStats().getStat(stats::name_stat::ability);
            static_cast<equipment*>(i.get())->getStats().setStat(stats::name_stat::ability, 10);
        }
    }
}


