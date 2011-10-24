#pragma once
#include "tile.h"
namespace CS262 {
class Boost :public tile
{
public:
	Boost() : tile(0,"boost"), acc_multi(2){};
	void change_acc(car&);
	void set_acc_multi(double m){acc_multi = m;}
	void check_topspeed(car& c) {};

private:
	double acc_multi;

};
}
