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
            j++;
        }
        if (i->get_tag() == Item::itemTag::quest_item)
        {
            retu << "[" << j << "]" << " " + i->get_name() << std::endl;
            no_item = false;
            j++;
        }
    }
    if (no_item)
    {
        retu << "You don't have any item!\n";
    }
    retu << "[0] Return." << std::endl;
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
            j++;
        }
    }
    if (no_item)
    {
        ret << "You don't have any potions!\n";
    }
    ret << "[0] Return." << std::endl;
    return ret;
}

std::stringstream Follower::printItemSelected()
{
    std::stringstream ret;
    // TODO //
    // Problème avec les if qui checkent les tag, ils ont pas l'air de marcher je fixerais ça
    // Apparament quand je check le tag potion ça marche pas mais la ça marche en castant, à voir
    // Attention je crois qu'un item de tag weapon va être concidéré comme quest item
    if (itemSelected_->get_tag() == Item::itemTag::weapon) 
    {
        ret << itemSelected_->get_name() << "." << std::endl
            << "If you equip this item, you have the following stats added to your current stats." << std::endl
            << "Ability : " << dynamic_cast<Equipment*>(itemSelected_.get())->getStats().get_stat(Stats::name_stat::ability)
            << ", Stamina : " << dynamic_cast<Equipment*>(itemSelected_.get())->getStats().get_stat(Stats::name_stat::stamina)
            << ", Luck : " << dynamic_cast<Equipment*>(itemSelected_.get())->getStats().get_stat(Stats::name_stat::luck) << "." << std::endl
            << "What do you want to do with this Item?" << std::endl
            << "[1] Equip." << std::endl
            << "[2] Inspect." << std::endl
            << "[0] Exit." << std::endl;
    }
    if (itemSelected_->get_tag() == Item::itemTag::quest_item)
    {
        ret << itemSelected_->get_name() << "." <<std::endl
            << "What do you want to do with this Item?" << std::endl
            << "[1] Inspect." << std::endl
            << "[0] Exit." << std::endl;
    }
    if (auto* myPotion = dynamic_cast<Potion*>(itemSelected_.get()))
    {
        ret << itemSelected_->get_name() << std::endl
            << itemSelected_->get_description() << std::endl
            << "What do you want to do with this Item?" << std::endl
            << "[1] Use." << std::endl
            << "[0] Exit." << std::endl;
    }
    return ret;
}

char Follower::cinIndicator(char input)
{
    std::cout << ">";
    std::cin >> input;
    //std::cin.clear();
    return input;
}

Item Follower::returnItem(char input, Item::itemTag tag)
{
    char j = '1';
    for (const auto& i : inventory_)
    {
        if (tag == Item::itemTag::weapon)
        {
            if (auto* myEquipment = dynamic_cast<Equipment*>(i.get()))
            {
                //std::unique_ptr<Item> oo = std::make_unique<Equipment>(*myEquipment);
                if (input == j) { this->itemSelected_ = std::make_unique<Equipment>(*myEquipment); }
                j++;
            }
            if (i->get_tag() == Item::itemTag::quest_item)
            {
                if (input == j) { this->itemSelected_ = std::make_unique<Item>(*i); }
                j++;
            }
        }
        if (auto* myPotion = dynamic_cast<Potion*>(i.get()))
        {
            if (input == j) { this->itemSelected_ = std::make_unique<Potion>(*myPotion); }
            j++;
        }
    }
    return Item();
}

void Follower::inventoryManager()
{
    char invCase = 'a';
    bool invExit = false;
    char invInput = '0';
    do
    {
	    switch(invCase)
	    {
        case 'a':
            // Main inventory menu
            std::cout << printInventory().str();
            invInput = cinIndicator(invInput);
            std::cout << std::endl;
            if (invInput == '0') { invCase = 'b'; }
            if (invInput == '1') { invCase = 'c'; }
            if (invInput == '2') { invCase = 'd'; }
            break;
        case 'b':
            // Exit inventory
            invExit = true;
            break;
        case 'c':
            // Items menu
            std::cout << printEquipment().str();
            invInput = cinIndicator(invInput);
            std::cout << std::endl;
            if (invInput == '0') { invCase = 'a'; }
            else 
            { 
                invCase = 'e';
                returnItem(invInput, Item::itemTag::weapon);
                std::cout << itemSelected_->get_name() << dynamic_cast<Equipment*>(itemSelected_.get())->printItemStats().str();
            }
            break;
        case 'd':
            // Potions menu
            std::cout << printPotions().str();
            invInput = cinIndicator(invInput);
            std::cout << std::endl;
            if (invInput == '0') { invCase = 'a'; }
            else
            {
                invCase = 'e';
                returnItem(invInput, Item::itemTag::potion);
            }
            break;
        case 'e':
            // Items details
            
            // TODO //
            // Plusieurs trucs à améliorer ici, j'attend que les fonctions equip, use et tout soient prêtes.
            // Même problème que dans la fonction printItemSelected, le check du tag fonctionne pas, tout renvoie à 'c'
            std::cout << printItemSelected().str();
            invInput = cinIndicator(invInput);
            if (invInput == '0' && itemSelected_->get_tag() == Item::itemTag::potion) { invCase = 'd'; }
            else { invCase = 'c'; }
            break;
        default:
            std::cout << "Error?" << std::endl;
            break;
	    }
    } while (invExit == false);

}



std::stringstream Follower::printInventory()
{
    // Prints out info on the player
    std::stringstream ret;
    ret << "You decide to take a moment to reflect upon yourself and look trough your bags" << std::endl << std::endl;
    ret << "Ability " << this->currentStats_.get_stat(Stats::name_stat::ability) << "/" << this->maxStats_.get_stat(Stats::name_stat::ability) << std::endl;
    ret << "Stamina " << this->currentStats_.get_stat(Stats::name_stat::stamina) << "/" << this->maxStats_.get_stat(Stats::name_stat::stamina) << std::endl;
    ret << "Luck " << this->currentStats_.get_stat(Stats::name_stat::luck) << "/" << this->maxStats_.get_stat(Stats::name_stat::luck) << std::endl;
    ret << std::endl;
    ret << "Your bag contains:" << std::endl;
    ret << this->gold_ << " gold." << std::endl;
    ret << this->provisions_ << " provision." << std::endl;
    ret << returnItemQuantity(Item::itemTag::potion) << " potion." << std::endl;
    ret << returnItemQuantity(Item::itemTag::weapon) + returnItemQuantity(Item::itemTag::quest_item) << " Item." << std::endl << std::endl;
    ret << "Which pouch do you want to go trough?" << std::endl 

        << "[1] Items." << std::endl
		<< "[2] Potions." << std::endl
		<< "[3] Help." << std::endl
		<< "[0] Exit." << std::endl;


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

void Follower::add_inventory(std::unique_ptr<Item> item)
{
    inventory_.emplace_back(std::move(item));
}

int Follower::add_to_currentStat(Stats::name_stat nameStat,int addingStats)
{
    if (currentStats_.get_stat(nameStat) + addingStats > 0) {
        if (currentStats_.get_stat(nameStat) + addingStats >= maxStats_.get_stat(nameStat))
        {
            currentStats_.set_stat(nameStat, maxStats_.get_stat(nameStat));
        }
        else
        {
            currentStats_.add_stat(nameStat, addingStats);
        }
    }
    else
    {
        currentStats_.set_stat(nameStat, 0);
    }

    return currentStats_.get_stat(nameStat);
}

int Follower::set_to_currentStat(Stats::name_stat nameStat,int settingStats)
{

    if (settingStats >= maxStats_.get_stat(nameStat))
    {
        currentStats_.set_stat(nameStat, maxStats_.get_stat(nameStat));
    }
    else
    {
        currentStats_.set_stat(nameStat, settingStats);
    }

    return currentStats_.get_stat(nameStat);
}

int Follower::get_one_currentStat(Stats::name_stat name_stat)
{
    return currentStats_.get_stat(name_stat);
}

int Follower::add_to_maxStat(Stats::name_stat name_stat, int addingStats)
{
    if(maxStats_.get_stat(name_stat) + addingStats <= 0 )
    {
        maxStats_.set_stat(name_stat, 0);
    }
    else {
        maxStats_.add_stat(name_stat, addingStats);
    }

    return maxStats_.get_stat(name_stat);
}

int Follower::set_to_maxStat(Stats::name_stat name_stat, int settingStats)
{
    if (settingStats < 0)
    {
        maxStats_.set_stat(name_stat, 0);
    }
    else {
        maxStats_.set_stat(name_stat, settingStats);
    }

    return maxStats_.get_stat(name_stat);

}

int Follower::get_one_maxStat(Stats::name_stat name_stat)
{
    return maxStats_.get_stat(name_stat);
}



