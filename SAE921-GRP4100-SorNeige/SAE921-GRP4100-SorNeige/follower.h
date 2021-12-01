#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <memory>

#include "Stats.h"
#include "Item.h"
#include "Equipment.h"

class Follower
{
private:
	std::string name_; // FFollower Variables
	std::string description_; // Follower Variables

	Stats currentStats_;
	Stats maxStats_;

	std::vector<std::unique_ptr<Item>> inventory_;

	// Values used in the printInventory()
	int gold_;
	int provisions_;

	std::unique_ptr<Item> itemSelected_ = nullptr;


public:

	void setName(const std::string name){this->name_ = name;}
	std::string getName() const { return name_; }

	void setDescription(const std::string description) { this->description_ = description; }
	std::string getDescription() const { return description_; }

	void setCurrentStats(const Stats stats) { this->currentStats_ = stats; }
	Stats getCurrentStats() const { return currentStats_; }

	void setItemSelected(std::unique_ptr<Item> item) { this->itemSelected_.swap(item); }
	Item getItemSelected() const { return *itemSelected_; }

	void setProvisions(int number) { this->provisions_ = number; }
	int getProvisions() const { return provisions_; }

	// Returns the number of items in the inventory matching the specified tag
	int returnItemQuantity(Item::itemTag itemTag);

	// These tree methods simply prints out the inventory "Menus"
	// Main inventory menu
	std::stringstream printInventory();
	// Equipment menu
	std::stringstream printEquipment();
	// Potions menu
	std::stringstream printPotions();
	// Specific item menu
	std::stringstream printItemSelected();
	// Check if item selected is equiped

	// Text layout function. Will be moved!!!
	char cinIndicator(char input);
	Item returnItem(char input, Item::itemTag tag);
	// Switch case that will cout all the menus
	// /!\ it does cout so it will have to be modified when going into sfml \!/
	void inventoryManager();


	// ad a item to their inventory
	void add_inventory(std::string,std::string);//add quest item
	void add_inventory(std::string,std::string,int,int,int);//add equipment
	void add_inventory(std::string, std::string, Stats::name_stat);//add potion
	void add_inventory(Stats::name_stat);//add a "normal" potion
	void add_inventory(std::unique_ptr<Item> item);//add a pregenerated item

	
	int add_to_currentStat(Stats::name_stat,int);//get damage on the stats chosen and return the new value. use negative for damage and positive for regen. this new value cannot be below 0 or abow maxstats value
	int set_to_currentStat(Stats::name_stat,int);//using for setting a stats this new value cannot be below 0 or abow the same maxstats value
	int get_one_currentStat(Stats::name_stat);//for getting one particuliare stats
	
	int add_to_maxStat(Stats::name_stat, int);//get damage on the max stamina stats and return the new value. use negative for damage and positive for regen. this new value cannot be below 0
	int set_to_maxStat(Stats::name_stat, int);//using for setting the maxStamina. this new value cannot be below 0
	int get_one_maxStat(Stats::name_stat);//for getting one particuliare stats

	void equip_item (std::unique_ptr<Equipment> item);
	

};

