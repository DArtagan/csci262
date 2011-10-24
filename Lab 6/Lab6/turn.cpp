#include "turn.h"

namespace CS262 {
	void turn::check_topspeed(car& c) {
		if ((max_speed_allowed + c.get_handling()) < c.get_currentSpeed()) {
			c.set_currentSpeed(c.get_currentSpeed() - 2*(c.get_currentSpeed() - max_speed_allowed - c.get_handling()));
		}
		if (c.get_currentSpeed() < 0) {
			c.set_currentSpeed(0);
		}
	}
}