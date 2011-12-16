#include "User.h"

namespace CS262 {
	bool operator <(const User& LHS, const User& RHS) {
		return LHS.username < RHS.username;
	}

	bool operator ==(const User& LHS, const User& RHS) {
		return LHS.username == RHS.username;
	}

	bool operator <(const string& LHS, const User& RHS) {
		return LHS < RHS.username;
	}

	bool operator >(const string& LHS, const User& RHS) {
		return LHS > RHS.username;
	}

	bool operator ==(const string& LHS, const User& RHS) {
		return LHS == RHS.username;
	}

	bool User::authenticate(const string& provided_password) const {
		return password == provided_password;
	}

	ifstream& operator>> (ifstream& f, User& u){
		f >> u.username >> u.password >> u.firstName >> u.lastName;
		return f;
	}
}