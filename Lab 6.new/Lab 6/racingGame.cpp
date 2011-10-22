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
	
	string element, theName;
	int theTopSpeed, theAcceleration, theHandling;
	while( getline(inFileCars,inString.str(),carDelimiter) ) {
		int i(0);
		cout << inString.str();
		while( getline(inString,element,lineDelimiter) ) {
			cout << element;
			if(i == 0){
				cin >> theName;
			} else {
				if(element == "Top Speed") {
					cin >> theTopSpeed;
					cout << "theTopSpeed";
				} else if(element == "Acceleration") {
					cin >> theAcceleration;
					cout << theAcceleration;
				} else if(element == "Handling") {
					cin >> theHandling;
					cout << theHandling;
				}
				i++;
			}
		}
		car tempCar(theName, theTopSpeed, theAcceleration, theHandling);
		cars.insertAtTail(tempCar);
		cout << "while";
	}

	inFileCars.close();


	// Pause
	system("PAUSE");

	// Exit Program
	return 0;
}