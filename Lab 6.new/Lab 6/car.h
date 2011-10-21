#pragma once
#include <cstdlib>
#include <string>


namespace CS262 {
	class car {
	public:
		car(std::string theName = "bug", int theTopSpeed = 6, int theAcceleration = 3, int theHandling = 2) : name(theName), topSpeed(theTopSpeed), acceleration(theAcceleration), handling(theHandling) {}

	private:
		std::string name;
		int topSpeed, acceleration, handling;
	};
}
