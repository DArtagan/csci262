#include <cctype>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "Recipe.h"
using namespace std;
using namespace CS262;


int main() {
	cout << 1;
	LinkedList<string> ingredients;

	cout << 2;
	ifstream inFile( "recipes.txt" );
		if( !inFile ) {
			cout << "Error opening file." << endl;
			system("PAUSE");
			exit(1);
	}

	cout << 3;
	// Complete Ingredients list
	string inString;
	while( getline(inFile,inString) ) {
		cout << "while";
		if(inString == "=====") {
			getline(inFile,inString);
		} else {
			ingredients.insertAtTail(inString);
		}
	}

	cout << 4;
	for (node_iterator<string> it=ingredients.begin(); it != ingredients.end(); ++it) {
		cout << *it << ", "; // print each ingredient
	}

	inFile.close();

	// Pause
	system("PAUSE");

	// Exit Program
	return 0;
}