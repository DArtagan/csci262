#pragma once
#include <cstdlib>
#include <string>


namespace CS262 {
	class car {
	public:
		car(std::string theName = "bug", int theTopSpeed = 6, int theAcceleration = 3, int theHandling = 2) : name(theName), topSpeed(theTopSpeed), acceleration(theAcceleration), handling(theHandling) {}
		int get_topSpeed() {return topSpeed;}
		int get_acceleration() {return acceleration;}
		int get_handling() {return handling;}
		std::string get_name() {return name;}

		void set_topSpeed(int theTopSpeed) {};

	private:
		std::string name;
		int topSpeed, acceleration, handling;
	};
}
