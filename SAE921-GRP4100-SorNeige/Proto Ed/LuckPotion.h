#pragma once
#include "Potion.h"
class LuckPotion :
    public Potion
{
private:
public:
    void printInspect() override;
    void use() override;
};

