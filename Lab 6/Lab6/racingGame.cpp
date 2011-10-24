#include <cctype>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <fstream>
#include <string>
#include <algorithm>
#include "LinkedList.h"
#include "car.h"
#include "readers.h"
using namespace std;
using namespace CS262;


int main() {
	// Initializing
	string inString;
	car player;
	char carDelimiter = '=';
	char lineDelimiter = ':';
	LinkedList<car> cars;
	LinkedList<tile> track;
	int n(0), round(0);
	node_iterator<tile> fakeit;


	cars = carReader();
	track = trackReader();

	for(node_iterator<car> it = cars.begin(); it != cars.end(); ++it){
		cout << (*it).get_name() << ", ";
	}
	cout << endl << "Choose A Car:" << endl;
	cin >> inString;
	for(node_iterator<car> it = cars.begin(); it != cars.end(); ++it){
		if ((*it).get_name() == inString) {
			player = *it;
			break;
		}
		cout << "Couldn't find Car, Please try again:" << endl;
	}

	for(node_iterator<tile> it = track.begin(); it != track.end(); ) {
		fakeit = it;
		for(int i = 0; i < 5 && fakeit != track.end(); i++){
			cout << (*fakeit).get_type() << ", ";
			++fakeit;
		}

		cout << endl << "Your Current Speed is " << player.get_currentSpeed() << endl << "Accellerate(w) or Decellerate(s): ";
		cin >> inString;
		if (inString == "w") {
			player.set_currentAcc(player.get_acceleration());
		} else if (inString == "s") {
			player.set_currentAcc(0-player.get_acceleration());
		} else {
			cout << "Incorrect Input." << endl;
		}

		round++;
		player.set_currentSpeed(player.get_currentSpeed()+player.get_currentAcc());
		if (player.get_currentSpeed() > player.get_topSpeed()) {
			player.set_currentSpeed(player.get_topSpeed());
		} else if (player.get_currentSpeed() < 0) {
			player.set_currentSpeed(0);
		}
		for (int i = 0; i < player.get_currentSpeed() && it != track.end(); i++){
			if (((*it).get_type() == "straight")) {
				++it;
			} else if (((*it).get_type() == "boost")) {
				(*it).change_acc(player);
				cout << "Boost changed speed to " << player.get_currentSpeed() << endl;
				++it;
			} else if (((*it).get_type() == "turn")) {
				(*it).check_topspeed(player);
				cout << "After turn you are traveling " << player.get_currentSpeed() << endl;
				++it;
			}
		}
	}

	// Pause
	cout << "You finished the track in " << round << " rounds.";
	system("PAUSE");

	// Exit Program
	return 0;
}