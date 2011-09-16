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

bool Date::operator <(const Date& compare)
{
	return true;
}
