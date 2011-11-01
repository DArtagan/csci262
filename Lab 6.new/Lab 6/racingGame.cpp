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
	char carDelimiter = '=';
	char lineDelimiter = ':';
	LinkedList<car> cars;
	LinkedList<track> track;


	cars = carReader();
	track = trackReader();


	// Pause
	system("PAUSE");

	// Exit Program
	return 0;
}