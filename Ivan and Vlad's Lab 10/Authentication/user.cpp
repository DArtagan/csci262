#include "user.h"

namespace CS262{
	
		bool operator <(const user& one, const user& two)
		{
			int count;
			bool check;
			if(one.username.size() > two.username.size())
			{
				count = two.username.size();
				check=false;
			}
			else
			{
				count = one.username.size();
				check=true;
			}

			char left;
			char right;

			for( int i=0; i<count; i++)
			{
				left = one.username[i];
				right = two.username[i];
				if(left < right)
				{
					return true;
				}
				else if(left>right)
				{
					return false;
				}
			}
			return check;
		}

		bool operator >(const user& one, const user& two)
		{
			int count;
			bool check;
			if(one.username.size() > two.username.size())
			{
				count = two.username.size();
				check=true;
			}
			else
			{
				count = one.username.size();
				check=false;
			}

			char left;
			char right;

			for( int i=0; i<count; i++)
			{
				left = one.username[i];
				right = two.username[i];
				if(left > right)
				{
					return true;
				}
				else if(left<right)
				{
					return false;
				}
			}
			return check;
		}


		bool operator ==(const user& one, const user& two)
		{
			if(one.username.size() != two.username.size())
			{
				return false;
			}

			char left;
			char right;

			for(int i=0; i<one.username.size(); i++)
			{
				left = one.username[i];
				right = two.username[i];
				if(left != right)
				{
					return false;
				}
			}
			return true;
		}

		void user::operator =(const user& input)
		{
			username = input.username;
			password = input.password;
			f_name = input.f_name;
			l_name = input.l_name;
		}
		
		//Operators for keys
		bool operator <(const string& one, const user& two)
		{
			int count;
			bool check;

			if(one.size()>two.username.size())
			{
				count = two.username.size();
				check = false;
			}
			else
			{
				count = one.size();
				check = true;
			}
			char left;
			char right;

			for( int i=0; i<count; i++)
			{
				left = one[i];
				right = two.username[i];
				if(left < right)
				{
					return true;
				}
				else if(left >right)
				{
					return false;
				}
			}
			return check;
		}


		bool operator >(const string& one, const user& two)
		{
			int count;
			bool check;

			if(one.size()>two.username.size())
			{
				count = two.username.size();
				check = true;
			}
			else
			{
				count = one.size();
				check = false;
			}
			char left;
			char right;

			for( int i=0; i<count; i++)
			{
				left = one[i];
				right = two.username[i];
				if(left > right)
				{
					return true;
				}
				else if(left<right)
				{
					return false;
				}
			}
			return check;
		}

		bool operator ==(const string& one, const user& two)
		{
			if(one.size() != two.username.size())
			{
				return false;
			}

			char left;
			char right;

			for(int i=0; i<one.size(); i++)
			{
				left = one[i];
				right = two.username[i];

				if(left != right)
				{
					return false;
				}
			}
			return true;
		}

		//Password check
		bool user::password_check(const string& tryone) const
		{
			if(tryone.size() != username.size())
			{
				return false;
			}

			char left;
			char right;

			for(int i =0; i<tryone.size(); i++)
			{
				left = username[i];
				right = tryone[i];
				if(left != right)
				{
					return false;
				}
			}
			return true;
		}
}