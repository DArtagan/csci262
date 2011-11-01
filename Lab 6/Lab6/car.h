#pragma once
#include <cstdlib>
#include <string>


namespace CS262 {
	class car {
	public:
		car(std::string theName = "bug", int theTopSpeed = 6, int theAcceleration = 3, int theHandling = 2, int thecurrentSpeed = 0, int thecurrentAcc = 0) : name(theName), topSpeed(theTopSpeed), acceleration(theAcceleration), handling(theHandling), currentSpeed(thecurrentSpeed), currentAcc(thecurrentAcc) {}
		int get_topSpeed() {return topSpeed;}
		int get_acceleration() {return acceleration;}
		int get_handling() {return handling;}
		int get_currentAcc() {return currentAcc;}
		int get_currentSpeed() {return currentSpeed;}
		std::string get_name() {return name;}

		void set_currentSpeed(int s) {currentSpeed = s;}
		void set_currentAcc(int a) {currentAcc = a;}

	private:
		std::string name;
		int topSpeed, acceleration, handling, currentSpeed, currentAcc;
	};
}
