#include "user.h"
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <fstream>


using namespace std;
using namespace CS262;

void output_user(const user& userperson)
{
	string usrname, pass, first, last;

	ifstream infile("users.txt");
	if (!infile)
    {
        cout<< "Error opening file users.txt." <<endl;
        system ("PAUSE");
        exit (1);
    }
	if(infile)
	{
		infile>>usrname>>pass>>first>>last;
		user input(usrname, pass, first, last);
		userperson = input;
	}


}

int main()
{
	//Read in the data into the tree

	//Put that logic in yourself above ^

	char cont('f');

	while( (cont != 'Q') || (cont !='q'))
	{
		cout<<"+++++++Menu+++++++"<<endl<<endl;
		cout<<"Choose one of the following actions:"<<endl;
		cout<<"1: Attempt to log in"<<endl;
		cout<<"2: Register a new user"<<endl;
		cout<<"3: Delete an existing user"<<endl;
		cout<<"4: View total number of users"<<endl;
		cout<<"5: View min and max username"<<endl;
		cout<<"6: View tree height"<<endl;
		cout<<"Q: Quit the program"<<endl:
		cin>>cont;

		if(cont == 'Q')
		{
			return 0;
		}

		if(cont== '1')
		{
			std::string user_name;
			std::string user_password;
		
			cout<<"Log In:"<<endl;
			cout<<"Username: ";
			cin>> user_name;
			cout<<"Password: ";
			cin>> user_password:

			//Find user_name in tree, if not there return saying:
			//cout<<"No user with username "<<user_name<<" exists in the database."<<endl;
			//Else make user "user login;" equal to the found user

			//If the user is found:
			//if(user_password == login)
			//cout<<"Welcome "<<login.f_name<<" "<<login.l_name<<"!"<<endl;
		}
		if(cont =='2')
		{
			std::string user_name;
			std::string user_password;
			std::string first_n;
			std::string last_n;
			bool unique(false);
			
			while(!unique)
			{
				cout<<"Enter a new username: ";
				cin>>user_name;
				cout<<endl;
				//Check to see if username is used
				//If used:
				//cout<<"Username already in use"<<endl;

				//If not used:
				//unique = true;
			}
			
			cout<<"Enter a new password: ";
			cin>>user_password;
			cout<<endl;

			cout<<"Enter user first name: ";
			cin>>first_n;
			cout<<endl;

			cout<<"Enter user last name: ";
			cin>>last_n;
			cout<<endl;

			user new_user(user_name,user_password, first_n, last_n);

			//Add the new_user to the search tree

			cout<<"User "<<user_name<<" created!"<<endl;
		}

		if(cont=='3')
		{
			std::string username;

			cout<<"Enter username of user to delete: ";
			cin>>username;
			cout<<endl;

			//Check to see if user is in the database

			//If not:
			//cout<<"User "<<username<<" does not exist."<<endl;

			//If found remove the user
			//cout<<"User "<<username<<" deleted."<<endl;
		}

		if(cont=='4')
		{
			int count;//Find the number of users in the tree
			cout<<"There are "<<count<<" users in this database."<<endl;
		}

		if(cont=='5')
		{
			std::string max, min;
			//Set max to right most node and min to left most
			cout<<"The database contains usernames between "<<min<<" and "<<max<<"."<<endl;
		}

		if(cont=='6')
		{
			int height; //Set this to the height of the tree
			cout<<" The height of the tree is "<<height<<"."<<endl;
		}
	}

	//Write the tree back to the file

	return 0;
}


