#ifndef USER_H
#define USER_H

#include <iostream>
#include <map>
class User
{
	private:
		std::string name;
		unsigned long int password;
		bool loggedIn;

		//change to days data type
		//pointer to a map with string pointer to users
		std::map<std::string, User*> *users;

	public:
		User(std::string userName, unsigned long int password);
		~User();
		void displayUser();
		void displayDay(int day, int month, int year);
		std::string getUserName() { return name; }
		unsigned long int getUserPassword() {return password; }
		int logIn() {loggedIn = true; }
};

#endif