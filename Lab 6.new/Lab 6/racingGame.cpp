#include <cctype>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <fstream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "car.h"
using namespace std;
using namespace CS262;


int main() {
	// Initializing
	string inString;
	char carDelimiter = '=';
	char lineDelimiter = ':';
	LinkedList<car> cars;


	// Car Reader
	ifstream inFileCars( "cars.txt" );
		if( !inFileCars ) {
			cout << "Error opening file." << endl;
			system("PAUSE");
			exit(1);
	}
	
	string key, theName;
	int value, theTopSpeed, theAcceleration, theHandling, i(0);
	
	while( getline(inFileCars,inString) ) {
		cout << inString;
		cout << i%5;
		size_t delLocation;
		if(i%5 == 0){
			theName = inString;
		} else {
			delLocation = inString.find(lineDelimiter);
			key = inString.substr(0, delLocation);
			//value = inString.substr(delLocation + 2, inString.size() - 1);
			cout << value;
			if(key == "Top Speed") {
				theTopSpeed = value;
				cout << "theTopSpeed";
			} else if(key == "Acceleration") {
				theAcceleration = value;
				cout << theAcceleration;
			} else if(key == "Handling") {
				theHandling = value;
				cout << theHandling;
			}
		}
		i++;
		if(i%5 == 4) {
			//car tempCar(theName, theTopSpeed, theAcceleration, theHandling);
			//cars.insertAtTail(tempCar);
			cout << "while";
		}
	}

	inFileCars.close();


	// Pause
	system("PAUSE");

	// Exit Program
	return 0;
}