#pragma once
#include "tile.h"
namespace CS262 {
class turn : public tile
{
public:
	turn() : tile(0,"turn"), max_speed_allowed(1) {};
	int get_max_speed_allowed(){return max_speed_allowed;}
	void set_max_speed_allowed(int s){max_speed_allowed = s;}
	void check_topspeed(car& c);
	void change_acc(car&) {};

private:
	int max_speed_allowed;
	
};
}