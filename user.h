#ifndef USER_H
#define USER_H

#include <iostream>
#include <map>
class User
{
	private:
		std::string name;
		int password;
		bool loggedIn;

		//change to days data type
		//pointer to a map with string pointer to users
		std::map<std::string, User*> *users;

	public:
		User(std::string userName, int password);
		~User();
		void displayUser();
		void displayDay(int day, int month, int year);
};

#endif