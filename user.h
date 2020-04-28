#ifndef USER_H
#define USER_H

#include <iostream>
#include <map>
#include <queue>
#include "task.h"

class User
{
	private:
		std::string name;
		unsigned long int password;
		bool loggedIn;

		//change to days data type
		//pointer to a map with string pointer to users
		std::map<std::string, std::priority_queue<Task*>> *days;

	public:
		User(std::string userName, unsigned long int password);
		~User();
		void addDay(std::string day); // format "00/00/0000" month day year
		void displayUser();
		void displayTopPriorityDay(std::string day);
		void addTask(std::string day, std::string task, int priorityLevel);
		std::string getUserName() { return name; }
		unsigned long int getUserPassword() {return password; }
		int logIn() {loggedIn = true; }
};

#endif