#pragma once


class Date
{
public:
	Date(void);
	Date(int m, int d, int y) : month(m), day(d), year(y) {}
	Date(const Date&);
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getYear() const { return year; }
	bool operator <(const Date& compare);
	friend bool operator!=(const Date& date1, const Date& date2);

private:
	int month, day, year;
};

bool operator ==(const Date& date1, const Date& date2);