#include "readers.h"

// Car Reader
namespace CS262 {
LinkedList<car> carReader() {
	ifstream inFileCars( "cars.txt" );
		if( !inFileCars ) {
			cout << "Error opening file." << endl;
			system("PAUSE");
			exit(1);
	}
	
	std::string inString, theName;
	LinkedList<car> cars;
	int theTopSpeed(0), theAcceleration, theHandling, i(0);
	char lineDelimeter = ':';
	
	while( getline(inFileCars,inString,lineDelimeter) ) {
		if(i%5 == 0){
			theName = inString;
		} else {
			if(inString == "Top Speed") {
				inFileCars >> theTopSpeed;
			} else if(inString == "Acceleration") {
				inFileCars >> theAcceleration;
			} else if(inString == "Handling") {
				inFileCars >> theHandling;
			}
		}
		getline(inFileCars,inString);
		if(i%5 == 4) {
			car tempCar(theName, theTopSpeed, theAcceleration, theHandling);
			cars.insertAtTail(tempCar);
		}
		i++;
	}

	inFileCars.close();
	return cars;
}
}