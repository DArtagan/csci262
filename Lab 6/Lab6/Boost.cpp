#include "Boost.h"

namespace CS262 {
void Boost::change_acc(car& c) {
	c.set_currentSpeed(c.get_currentSpeed()-c.get_currentAcc());
	c.set_currentAcc(c.get_currentAcc()*acc_multi);
	c.set_currentSpeed(c.get_currentSpeed()+c.get_currentAcc());
	if (c.get_currentSpeed() > c.get_topSpeed()){
		c.set_currentSpeed(c.get_topSpeed());
	}
	if (c.get_currentSpeed() < 0) {
		c.set_currentSpeed(0);
	}
}
}