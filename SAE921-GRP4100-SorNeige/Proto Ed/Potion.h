#pragma once
#include "Item.h"
class Potion :
    public Item
{
private:
    int usageLeft_ = 2;
public:
    //Potion(std::string displayName, Stat itemStat);
    //jsplus comment on fait un constructeur d'une classe h�rit�e d'une interface, impossible de lancer le code si on cr�� un objet potion, todo

    int getUsageLeft() { return usageLeft_; } // J'impl�mente pas encore de setter comme je sais pas encore comment use() va fonctionner

    void printInspect() override;
    void use() override;
};

