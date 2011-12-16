#include "User.h"

namespace CS262{
	bool operator< (const User& x, const User& y){
		return x.username < y.username;
	}
	bool operator> (const User& x, const User& y){
		return x.username > y.username;
	}
	bool operator== (const User& x, const User& y){
		return x.username == y.username;
	}

	ifstream& operator>> (ifstream& f, User& u){
		f >> u.username >> u.password >> u.firstname >> u.lastname;
		return f;
	}
}