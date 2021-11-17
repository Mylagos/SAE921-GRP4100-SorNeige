#include "stats.h"

stats::stats()
{
}

stats::stats( int ability_, int stamina_, int luck_)
{
	value_ability_ = ability_;
	value_stamina_ = stamina_;
	value_luck_ = luck_;

}

int stats::get_stat(name_stat name_stat_)
{
	switch (name_stat_)
	{
	case name_stat::ability:

		return value_ability_;

	case name_stat::stamina:

		return value_stamina_;

	case name_stat::luck:

		return value_luck_;
	}

	return 0;
}

void stats::set_stat(name_stat name_stat_, int newValue_)
{
	switch (name_stat_)
	{
	case name_stat::ability:

		value_ability_ = newValue_;

	case name_stat::stamina:

		value_stamina_ = newValue_;

	case name_stat::luck:

		value_luck_ = newValue_;
	}
}

int stats::add_stat(name_stat name_stat_, int addValue_)
{
	switch (name_stat_)
	{
	case name_stat::ability:

		value_ability_ = value_ability_ + addValue_;
		return value_ability_;

	case name_stat::stamina:

		value_stamina_ = value_stamina_ + addValue_;
		return value_stamina_;

	case name_stat::luck:

		value_luck_ = value_luck_ + addValue_;
		return value_luck_;
	}

	return 0;
}

void stats::add_all_stats(stats addingStats_)
{
	value_ability_ = value_ability_ + addingStats_.get_stat(name_stat::ability);
	value_stamina_ = value_stamina_ + addingStats_.get_stat(name_stat::stamina);
	value_luck_ = value_luck_ + addingStats_.get_stat(name_stat::luck);
}

void stats::sub_all_stats(stats subtractStats_)
{
	value_ability_ = value_ability_ - subtractStats_.get_stat(name_stat::ability);
	value_stamina_ = value_stamina_ - subtractStats_.get_stat(name_stat::stamina);
	value_luck_ = value_luck_ - subtractStats_.get_stat(name_stat::luck);
}

