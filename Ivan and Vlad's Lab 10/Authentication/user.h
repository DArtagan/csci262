#pragma once
#include <cstdlib>
#include <utility>
#include <string>

using namespace std;

namespace CS262
{
	struct user
	{

		string username;
		string password;
		string f_name;
		string l_name;

		//Default constructor
		user(): username(""), password(""), f_name(""), l_name(""){};

		//Constructor
		user(string usr, string pswrd, string f_n, string l_n):username(usr), password(pswrd), f_name(f_n), l_name(l_n){};

		//Operators for users
		friend bool operator <(const user& one, const user& two);

		friend bool operator ==(const user& one, const user& two);

		void operator =(const user& input);
		
		//Operators for keys
		friend bool operator <(const string&, const user&);

		friend bool operator >(const string&, const user&);

		friend bool operator ==(const string&, const user&);

		//Password check
		bool password_check(const string& tryone) const;
	};

	using namespace rel_ops;
}
