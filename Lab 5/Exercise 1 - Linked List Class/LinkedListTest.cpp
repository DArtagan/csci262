// An interactive test program for the new linkedList class
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <limits>
#include "LinkedList.h"
using namespace std;
using namespace CS262;


void print_menu();
// Postcondition: A menu of choices for this program has been written to cout.


char get_user_command();
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.


double get_number();
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.


void copy_destroy(LinkedList source) { }
// Postcondition: A copy of the source linked list has been created and
// subsequently destroyed


int main( )
{
    LinkedList list; // A linked list that we’ll perform tests on
    char choice;     // A command character entered by the user
	double value;
    
    cout << "I have initialized an empty list of real numbers." << endl;

    do
    {
        print_menu();
        choice = toupper(get_user_command());

        switch (choice)
        {
            case 'I':
				list.insertAtHead(get_number());
				break;

			case 'T':
				list.insertAtTail(get_number());
				break;

            case 'R':
				value = get_number();
				if (list.removeFromList(value))
					cout << endl << "The item has been removed." << endl;
				else
					cout << endl << "The item was not in the list." << endl;
				break;

			case 'C':
				list.clearList();
				break;

			case 'S':
				cout << "Current list size: " << list.size() << endl;
				break;

			case 'X':
				copy_destroy(list);
				cout << "Copy created and destroyed; ensure the list is unchanged" << endl;
				break;

			case '=':
				list = list = list;
				cout << "Assignment done; ensure the list is unchanged" << endl;
				break;

            case 'Q':
				break;

            default:
				cout << choice << " is invalid." << endl;
        }
    }
    while ((choice != 'Q'));

    return EXIT_SUCCESS;
}


void print_menu() {
    cout << endl; // Print blank line before the menu
    cout << "The following choices are available: " << endl;
    cout << "  I   Insert a number at the beginning of the list" << endl;
	cout << "  T   Insert a number at the end of the list" << endl;
    cout << "  R   Remove a number from the list" << endl;
	cout << "  C   Clear the list" << endl;
	cout << "  S   Display list size" << endl;
	cout << "  X   Create and destroy a copy of the list" << endl;
	cout << "  =   Test the assignment operator" << endl;
    cout << "  Q   Quit the program" << endl;
}


char get_user_command() {
    char command;

    cout << "Enter choice: ";
    cin >> command; // Input of characters skips blanks and newline character
	cout << endl;

    return command;
}


double get_number() {
    double result;
    
    cout << "Please enter a number: ";
    
	if (!(cin >> result)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		result = get_number();
	}

    return result;
}
