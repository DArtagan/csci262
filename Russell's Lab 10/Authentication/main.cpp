#include "BinarySearchTree.h"
#include "User.h"
using namespace std;
using namespace CS262;

static ofstream outfile;
void output_User(const User& u) {
	string str(u.get_user() + " " + u.get_pass() + " " + u.get_first() + " " + u.get_last());
	outfile << str << endl;
}

int main(){
	ifstream infile("User.txt");
	User temp;
	User* temp2;
	string usna, pswd, fname, lname;
	char menu('0');
	BinarySearchTree<User,string> UserTree;
	while (infile >> temp) {
		UserTree.insert(temp);
	}
	infile.close();
	while(menu != '7') {
		cout << "1: Attempt to log in" << endl;
		cout << "2. Register a new user" << endl;
		cout << "3. Delete an existing user" << endl;
		cout << "4. View total number of users" << endl;
		cout << "5. View min and max username" << endl;
		cout << "6. View tree height" << endl;
		cout << "7. Quit the program" << endl;
		cin >> menu;
		if (menu == '1') {
			cout << endl << "Log in:" << endl << "- Username: ";
			cin >> usna;
			cout << endl << "- Password: ";
			cin >> pswd;
			temp2 = UserTree.search(usna);
			if (temp2 == NULL) {
				cout << endl << "Invalid username/password combination." << endl;
			} else if (temp2->authenticate(pswd)){
				cout << endl << "Welcome " << temp2->get_first() << ", " << temp2->get_last() << "." << endl;
			} else {
				cout << endl << "Invalid username/password combination." << endl;
			}
		} else if (menu == '2') {
			cout << endl << "Enter the unique username of the user you want to create: ";
			cin >> usna;
			if (!UserTree.search(usna)) {
				cout << endl << "- Password: ";
				cin >> pswd;
				cout << endl << "- First Name: ";
				cin >> fname;
				cout << "- Last Name: " << endl;
				cin >> lname;
				User newuser(usna, pswd, fname, lname);
				UserTree.insert(newuser);
				cout << endl << "User successfully created!" << endl;
			} else {
				cout << endl << "User already exists!" << endl;
			}
		} else if (menu == '3') {
			cout << endl << "Enter the user name of the user you want to remove:";
			cin >> usna;
			if (UserTree.remove(usna)) {
				cout << endl << usna << " was successfully removed!" << endl;
			} else {
				cout << endl << "No such user!" << endl;
			}
		} else if (menu == '4') {
			cout << endl << "There are " << UserTree.size() << " users." << endl;
		} else if (menu == '5') {
			cout << endl << "Minumum User: " << UserTree.min().get_user() << " Maxiumum User: " << UserTree.max().get_user() << endl;
		} else if (menu == '6') {
			cout << endl << "The User Tree is " << UserTree.height() << " users in height." << endl;
		} else if (menu == '7') {
			break;
		} else {
			cout << endl << "Invalid Input!" << endl;
		}
	}

	outfile.open("User.txt");
	UserTree.preorder(output_User);
	outfile.close();

	return 0;
}