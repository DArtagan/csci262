#include "Date.h"
#include <iostream>

using namespace std;

Date::Date(void)
{
	month = 1;
	day = 1;
	year = 1980;
}

Date::Date(const Date& source)
{
	cout << "Inside copy constructor!\n";
	month = source.month;
	day = source.day;
	year = source.year;
}

bool Date::operator <(const Date& RHS) {
	cout << "The < function has been called\n";
	if((year < RHS.year) && (month < RHS.month) && (day < RHS.day)) {
		return true;
	} else {
		return false;
	}
}

bool operator!=(const Date& LHS, const Date& RHS) {
	cout << "The != function has been called\n";
	if((LHS.year != RHS.year) || (LHS.month != RHS.month) || (LHS.day != RHS.day)) {
		return true;
	} else {
		return false;
	}
}

bool operator ==(const Date& LHS, const Date& RHS) {
	cout << "The == function has been called\n";
	if((LHS.getYear() == RHS.getYear()) && (LHS.getMonth() == RHS.getMonth()) && (LHS.getDay() == RHS.getDay())) {
		return true;
	} else {
		return false;
	}
}