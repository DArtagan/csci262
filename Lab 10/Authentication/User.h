#pragma once
#include <iostream>
#include <utility>
#include <fstream>
#include <string>
using namespace std;

namespace CS262 {
	class User {
	public:
		// Constructors
		User() : username(""), password(""), firstName(""), lastName("")  {}
		User(std::string theUsername, std::string thePassword, std::string theFirstName, std::string theLastName) : username(theUsername), password(thePassword), firstName(theFirstName), lastName(theLastName) {}

		// Item-Item comparisons
		friend bool operator <(const User&, const User&);
		friend bool operator ==(const User&, const User&);

		// Key-Item comparisons
		friend bool operator <(const string&, const User&);
		friend bool operator >(const string&, const User&);
		friend bool operator ==(const string&, const User&);

		// Other operators
		friend ifstream& operator>> (std::ifstream&, User&);

		// Functions
		bool authenticate(const string& provided_password) const;

	private:
		std::string username, password, firstName, lastName;
	};

	using namespace rel_ops;
}
