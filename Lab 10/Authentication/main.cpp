#include <cstdlib>
#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "User.h"
using namespace std;
using namespace CS262;

static ofstream outfile;
void output_User(const User& u) {
	string str(u.getUsername() + " " + u.getUsername() + " " + u.getFirstName() + " " + u.getLastName());
	outfile << str << endl;
}

int main() {
	// Declarations
	char choice = '0';
	BinarySearchTree<User,string> UserTree;
	User temp, maximum, minimum;
	User* ptr;
	string username, password, firstName, lastName;

	// Read in from file
	ifstream infile("users.txt");
		while (infile >> temp) {
			UserTree.insert(temp);
		}
	infile.close();

	// Menu
	while(choice != 'Q') {
		cout << "Enter the corresponding number for what you want to do:" << endl << "1:  Attempt to log in" << endl << "2:  Register a new user" << endl << "3:  Delete an existing user" << endl << "4:  View total number of users" << endl << "5:  View min and max username" << endl << "6:  View tree height" << endl << "Q:  Quit the program" << endl;
		cin >> choice;
		switch(choice) {
		case '1':
			// Authenticate User
			cout << endl << "Log in:" << endl << "   Username: ";
			cin >> username;
			cout << endl << "   Password: ";
			cin >> password;
			ptr = UserTree.search(username);
			if (ptr == NULL) {
				cout << endl << "Invalid username/password combination." << endl;
			} else if (ptr->authenticate(password)){
				cout << endl << "Welcome " << ptr->getFirstName() << ", " << ptr->getLastName() << "." << endl << endl << endl;
			} else {
				cout << endl << "Invalid username/password combination." << endl << endl << endl;
			}
			break;
		case '2':
			// Register User
			cout << endl << "Enter the unique username of the user you want to create: ";
			cin >> username;
			if (!UserTree.search(username)) {
				cout << "   Password: ";
				cin >> password;
				cout << "   First Name: ";
				cin >> firstName;
				cout << "   Last Name: ";
				cin >> lastName;
				User newuser(username, password, firstName, lastName);
				UserTree.insert(newuser);
				cout << endl << "User successfully created!" << endl << endl << endl;
			} else {
				cout << endl << "User already exists!" << endl << endl << endl;
			}
			break;
		case '3':
			cout << endl << "Enter the user name of the user you want to remove:";
			cin >> username;
			if (UserTree.remove(username)) {
				cout << endl << username << " was successfully removed!" << endl << endl << endl;
			} else {
				cout << endl << "No such user exists." << endl << endl << endl;
			}
			break;
		case '4':
			cout << endl << "   There are " << UserTree.size() << " users in this tree." << endl;
			break;
		case '5':
			maximum = UserTree.max();
			minimum = UserTree.min();
			cout << endl << "   Minimum Username: " << minimum.getUsername() << endl << "   Maximum Username: " << maximum.getUsername() << endl << endl << endl;
			break;
		case '6':
			cout << endl << "The User Tree is " << UserTree.height() << " users in height." << endl << endl << endl;
			break;
		}
	}

	outfile.open("users.txt");
	UserTree.preorder(output_User);
	outfile.close();

	return 0;
}