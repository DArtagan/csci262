#include <cstdlib>
#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "User.h"
using namespace std;
using namespace CS262;

int main() {
	// Declarations
	char choice = '0';

	// Read in from file
	ifstream infile("user.txt");
	{
		// Temporary Variables
		User temp;
		string username, password, firstName, lastName;
	
		BinarySearchTree<User,string> UserTree;
		while (infile >> temp) {
			UserTree.insert(temp);
		}
	}
	infile.close();

	// Menu
	while(choice != 'Q') {
		cout << "Enter the corresponding number for what you want to do:" << endl << "1:  Attempt to log in" << endl << "2:  Register a new user" << endl << "3:  Delete an existing user" << endl << "4:  View total number of users" << endl << "5:  View min and max username" << endl << "6:  View tree height" << "Q:  Quit the program" << endl;
		cin >> choice;
		switch(choice) {
		case '1':

			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		}
	}

	return 0;
}