/**************************************************************/
// NAME		Ivan Yaremenko, Vlad Yaremenko
// DATE		12/05/11
// SECTION	B
//
// PURPOSE	The purpose of this assignment is to become more familiar
//			with binary tree implementation, traversal and use as well 
//			as to model a simple login operation.
/**************************************************************/

#include "user.h"
#include "BST.h"
#include <cstdlib>
#include <iostream>
#include <cassert>
#include <fstream>


using namespace std;
using namespace CS262;

static ofstream outfile;

void output_user(user& userperson)
{
	
	outfile<<userperson.username;
	outfile<<userperson.password;
	outfile<<userperson.f_name;
	outfile<<userperson.l_name;
	outfile<<"/n";
}

int main()
{
	//Populate tree
	string usrname, pass, first, last;
	BST<user, std::string> database;
	user login;

	ifstream infile("users.txt");
	if (!infile)
    {
        cout<< "Error opening file users.txt." <<endl;
        system ("PAUSE");
        exit (1);
    }

	while(infile>>usrname>>pass>>first>>last)
	{
		user* insert_user = new user(usrname, pass, first, last);
		database.insert(*insert_user);
	}
	
	infile.close();

	//Enter main sequence

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
		cout<<"Q: Quit the program"<<endl;
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
			cin>> user_password;


			if(database.search(user_name) == NULL)
			{
				cout<< "No user "<<user_name<<" was found in database."<<endl;
			}
			else
			{
				login = *database.search(user_name);

				if(login.password == user_password)
				{
					cout<<"Welcome "<<login.f_name<<" "<<login.l_name<<"!"<<endl;
				}
				else
				{
					cout<<"Wrong password! Get your passwords straight otherwise Skyrim will shut down...."<<endl;
				}
			}
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
				
				if(database.search(user_name) !=NULL)
				{
					cout<<"Username already in use"<<endl;
				}
				else
				{
					unique = true;
				}
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

			database.insert(new_user);

			cout<<"User "<<user_name<<" created!"<<endl;
		}

		if(cont=='3')
		{
			std::string username;

			cout<<"Enter username of user to delete: ";
			cin>>username;
			cout<<endl;

			if(database.search(username) ==NULL)
			{
				cout<<"User "<<username<<" does not exist."<<endl;
			}
			else
			{
				database.remove(username);
				cout<<"Deleted "<<username<<endl;
			}
		}

		if(cont=='4')
		{
			int count = database.size();//Find the number of users in the tree
			cout<<"There are "<<count<<" users in this database."<<endl;
		}

		if(cont=='5')
		{
			std::string max, min;
			max=database.max().username;
			min = database.min().username;
			cout<<"The database contains usernames between "<<min<<" and "<<max<<"."<<endl;
		}

		if(cont=='6')
		{
			int height = database.height(); //Set this to the height of the tree
			cout<<" The height of the tree is "<<height<<"."<<endl;
		}
	}

	ofstream outfile ("users.txt");
    
    if (!outfile)
    {
        cout << "Error opening output file." << endl;
        system ("PAUSE");
        exit (1);
    }

	user defaulted;
	database.inorder(output_user);

	outfile.close();
	return 0;
}


