#include "Potion.h"

/*Potion::Potion(std::string displayName, Stat itemStat)
{
	setDisplayName(displayName);
	setItemStat(itemStat);
}*/

void Potion::printInspect()
{
	std::string ifLuck = "";
	if (getItemStat().returnStatsUsed() == "Luck") { ifLuck = " and give your maximum luck +1 point"; }
	//Si on change les retours de returnStatsUsed(), ajouter un espace par example, ça fuck cette ligne en haut

	std::cout << "This" << getDisplayName() << " will restore your " << getItemStat().returnStatsUsed() << ifLuck << "." << "(Uses left : " << getUsageLeft() << ").\n";
}
