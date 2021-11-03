#include "stats.h"

stats::stats()
{
}

stats::stats( int ability_, int stamina_, int luck_)
{
	value_ability = ability_;
	value_stamina = stamina_;
	value_luck = luck_;

}

int stats::getStat(name_stat name_stat_)
{
	switch (name_stat_)
	{
	case ability:

		return value_ability;

	case stamina:

		return value_stamina;

	case luck:

		return value_luck;
	}

	return 0;
}

void stats::setStat(name_stat name_stat_, int newValue_)
{
	switch (name_stat_)
	{
	case ability:

		value_ability = newValue_;

	case stamina:

		value_stamina = newValue_;

	case luck:

		value_luck = newValue_;
	}
}

int stats::addStat(name_stat name_stat_, int addValue_)
{
	switch (name_stat_)
	{
	case ability:

		value_ability = value_ability + addValue_;
		return value_ability;

	case stamina:

		value_stamina = value_stamina + addValue_;
		return value_stamina;

	case luck:

		value_luck = value_luck + addValue_;
		return value_luck;
	}

	return 0;
}

void stats::addAllStats(stats addingStats_)
{
	value_ability = value_ability + addingStats_.getStat(ability);
	value_stamina = value_stamina + addingStats_.getStat(stamina);
	value_luck = value_luck + addingStats_.getStat(luck);
}

void stats::subAllStats(stats subtractStats_)
{
	value_ability = value_ability - subtractStats_.getStat(ability);
	value_stamina = value_stamina - subtractStats_.getStat(stamina);
	value_luck = value_luck - subtractStats_.getStat(luck);
}

