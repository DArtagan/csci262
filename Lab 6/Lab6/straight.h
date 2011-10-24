#pragma once
#include "tile.h"
namespace CS262 {
class straight : public tile{
public:
	void change_acc(car&){};
	void check_topspeed(car& c){};
};
}
