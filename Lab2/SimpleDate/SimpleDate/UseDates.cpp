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

