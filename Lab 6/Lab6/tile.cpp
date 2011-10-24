#include "tile.h"
#include <iostream>
using namespace std;

namespace CS262{
	void tile::change_acc(car& c) {
		c.set_currentSpeed(c.get_currentSpeed()-c.get_currentAcc());
		c.set_currentAcc(c.get_currentAcc()*2);
		c.set_currentSpeed(c.get_currentSpeed()+c.get_currentAcc());
		if (c.get_currentSpeed() > c.get_topSpeed()){
			c.set_currentSpeed(c.get_topSpeed());
		}
		if (c.get_currentSpeed() < 0) {
			c.set_currentSpeed(0);
		}
	}

	void tile::check_topspeed(car& c) {
		if ((2 + c.get_handling()) < c.get_currentSpeed()) {
			c.set_currentSpeed(c.get_currentSpeed() - 2*(c.get_currentSpeed() - 2 - c.get_handling()-1));
		}
		if (c.get_currentSpeed() < 0) {
			c.set_currentSpeed(0);
		}
	}
}