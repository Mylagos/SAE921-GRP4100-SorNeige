#include "Stat.h"

Stat::Stat(int hability, int vitality, int luck)
{
	this->hability_ = hability;
	this->vitality_ = vitality;
	this->luck_ = luck;
}

std::string Stat::returnStatsUsed()
{
	
	int a = this->getHability(); // Convoluted method, needs to be simplified
	int b = this->getVitality();
	int c = this->getLuck();

	std::string returnString;
	

	if (a > 0) { returnString = "Hability"; }
	if (b > 0) { returnString = "Vitality"; }
	if (c > 0) { returnString = "Luck"; }




	/*if (a > 0)
		{
			returnString += "Hability";
		}
		else if (a > 0 && b > 0 && c > 0) {
			returnString += " , ";
		}
		else if (a > 0 && b > 0 && c < 0) {
			returnString += " and ";
		}
		else if (b > 0) {
			returnString += "Vitality";
		}
		else if (a > 0 || b > 0) {
			returnString += " and ";
		}
		else if (c > 0) {
			returnString += "Luck";
		}*/
	
	return returnString;

}
