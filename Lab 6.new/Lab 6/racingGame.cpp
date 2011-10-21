#include <cctype>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <fstream>
#include <string>
#include "LinkedList.h"
using namespace std;
using namespace CS262;


int main() {
	// Initializing
	string inString;
	string carDelimiter("=====");


	// Car Reader
	cout << 2;
	ifstream inFileCars( "cars.txt" );
		if( !inFileCars ) {
			cout << "Error opening file." << endl;
			system("PAUSE");
			exit(1);
	}
	
	while( getline(inFileCars,inString,carDelimiter) ) {
		cout << "while";

		string element;
		while( getline(inString,element,":") ) {
			string theName;
			int theTopSpeed, theAcceleration, theHandling;
			if(element == "Top Speed") {
				cin >> theTopSpeed;
			} else if(element == "Acceleration") {
				cin >> theAcceleration;
			}
		}
	}

	inFileCars.close();


	// Pause
	system("PAUSE");

	// Exit Program
	return 0;
}