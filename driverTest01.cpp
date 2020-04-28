#include <iostream>
#include "controller.h"

int main()
{
	Controller *controller = new Controller();

	controller->readFromDatabase();
	std::string userInput;
	User *testUser = NULL;

	//log user in
	while(!testUser)
	{
		std::cout << "Please login: \n";

		std::string username;
		std::string password;

		std::cout << "Please enter your username: ";
		std::getline(std::cin, username);
		std::cout << "Password: ";
		std::getline(std::cin, password);

		testUser = controller->login(username, password);
		if(testUser == NULL)
			std::cout << "USER " << username << " not found\n";
		else
			std::cout << "Welcome back " << username << "\n";
		
	}


	while(1)
	{
		std::cout << "--> ";
		getline(std::cin, userInput);

		if(userInput == "add day")
		{
			std::string day;
			std::cout << "Please enter day ex. d/m/y \"00/00/0000\": ";
			getline(std::cin, day);

			testUser->addDay(day);
		}
		else if(userInput == "add task")
		{
			std::string day;
			std::string task;
			std::string priorityLevel;

			std::cout << "Please enter the day: ";
			getline(std::cin, day);
			std::cout << "Please enter the task name: ";
			getline(std::cin, task);
			std::cout << "Please enter the priority Level: ";
			getline(std::cin, priorityLevel);

			testUser->addTask(day, task, std::stoi(priorityLevel));
		}
		else if(userInput == "display day")
		{
			std::string day;
			std::cout << "Please enter day ex. d/m/y \"00/00/0000\": ";
			getline(std::cin, day);
			testUser->displayDay(day);
		}
		else if(userInput == "add user")
		{
			std::string username;
			std::string password;

			std::cout << "Enter the users name: ";
			std::getline(std::cin, username);
			std::cout << "Enter the new users password: ";
			std::getline(std::cin, password);

			controller->addUser(username, password);
		}
		else if(userInput == "remove user")
		{
			std::string username;
			std::string password;

			std::cout << "Enter the users name: ";
			std::getline(std::cin, username);
			std::cout << "Enter the new users password: ";
			std::getline(std::cin, password);

			controller->removeUser(username, password);
		}
		else if(userInput == "update database")
		{
			std::cout << "Updating database\n";
			controller->updateDatabase();
		}
		else if(userInput == "display users")
		{
			controller->displayUsers();
		}
		else{
			std::cout << "Command not found\n";
		}
	}
}