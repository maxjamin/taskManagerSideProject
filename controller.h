#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <map>
#include "user.h"
#include <unordered_map>

class Controller
{
	private:
		std::map<std::string, User*> *users;
		std::hash<std::string> hashMaker;

	public:
		Controller();
		~Controller();

		User* login(std::string userName, std::string password);
		
		//functions only for admin
		int addUser(std::string userName, std::string password);
		int removeUser(std::string userName, std::string password);
		int displayUsers();
		int updateDatabase();
		int readFromDatabase();

};


#endif 