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

		int login(std::string userName, std::string password);
		int displayUser(std::string UserName);
		

		//functions only for admin
		int addUser(std::string userName, std::string password);
		int removeUser(std::string userName, std::string password);
		int displayUsers();
		int updateDatabase();
		int readFromDatabase();

};


#endif 