/**************************************************************/
// William H. Weiskopf
// September 6, 2011
// Sec: A
//
// PURPOPOSE: To explore different means of setting up overloaded operators and to explore inline constructors.  
/**************************************************************/

/***********************
Questions:
1. Explain the differences among the three constructors (default, regular, and copy).
	Default: This constructor initializes the month to 1, the day to 1, and the year to 1980.  This constructor runs when no parameters are specified.
	Regular: This constructor is an inline constructor.  It takes three parameters given on initialization of a Date object and uses those for the month, day, and year variables.
	Copy: This constructor uses a Date object to create another Date object just like the last one.  The parameter given to this constructor is the reference to another Date object and then the constructor uses the day, month, and year variables of that source parameter to initialize the variables of the new Date object.

2. The regular constructor (the one that takes three parameters) is an inline function. Explain what that means and how it works.
	Inline constructors don't require a function declared in the implementation file.  All actions are developed in the header file.  Because of the unique format of this function, it is best to only use inline functions with single line, simple functions.  The colon marks the division between the declaration and the implementation and the inline function must finish with double curly brackets, no semi-colon.

3. When is the copy constructor called in this program? That is, what two situations cause it to be called?
	The copy constructor is called when the Date object Party is used to make dupParty.  It is also called when the Date object today is initialized.

4. Explain the difference between the two uses of == (see the two comment lines that say == is used here and == is also used here).
	This is a case of an overloaded operator.  For the first case the == makes a call to the == operator of the Date class to run the == function included therein.  In the second case the == operator is used as a standard C++ operator.

************************/

// A simple driver program to help us understand copy constructors
// and overloaded operators

#include "Date.h"
#include <iostream>

using namespace std;

void printDate(Date date);

int main()
{
	Date today = Date(9,1,2007);
	Date party(9, 10, 2007);
	Date dupParty(party);
	if (today == party)  // == is used here
		cout << "We'll party today\n";
	else
		cout << "No party today, maybe this weekend\n";
	int x=8, y=9;
	if (x == y) // == is also used here
		cout << "Testing == on integers, is it our function?\n";
	printDate(today);
	if (party != dupParty)
		cout << "The party dates are different\n";
	else
		cout << "The party dates are the same\n";
	if (today < party)
		cout << "You have a party coming up!\n";
	if (party < today)
		cout << "You missed the party, too bad!\n";
	system("pause");
}

void printDate(Date date)
{
	cout << "Printing the date, as requested: ";
	cout << date.getMonth() << "/" << date.getDay() << "/" << date.getYear() << endl;
}

