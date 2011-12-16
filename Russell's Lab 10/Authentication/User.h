#pragma once
#include <utility>
#include <fstream>
#include <string>
using namespace std;

namespace CS262{

class User
{
public:
	User(const string& s1 = "", const string& s2 = "", const string& s3 = "", const string& s4 = ""): username(s1), password(s2), firstname(s3), lastname(s4) {}
	friend bool operator< (const User& x, const User& y);
	friend bool operator> (const User& x, const User& y);
	friend bool operator== (const User& x, const User& y);
	friend ifstream& operator>> (std::ifstream&, User&);
	string get_user() const {return username;}
	string get_first() const {return firstname;}
	string get_last() const {return lastname;}
	string get_pass() const {return password;}
	// returns true if the given password is the same as the user's true password
	bool authenticate(const std::string& provided_password) const {return password == provided_password;}

private:
	std::string username, password, firstname, lastname;
};
using namespace rel_ops;
}

