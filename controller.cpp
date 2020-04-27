#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include "controller.h"
#include "user.h"

Controller::Controller()
{
	users = new std::map<std::string, User*>();
}
Controller::~Controller()
{
	delete users;
	users = NULL;
}

int Controller::login(std::string UserName, std::string password)
{	

}

int Controller::displayUser(std::string userName)
{

}


int Controller::addUser(std::string userName, std::string password)
{
	//check for admin password


	unsigned long int hashedpassword = hashMaker(password);
	std::cout << "hashedpassword " << hashedpassword << " " <<
	userName <<" \n";
	User *user = new User(userName, hashedpassword);
	users->insert(std::make_pair(userName,user));

}


int Controller::removeUser(std::string userName, std::string password)
{
	//check for admin password


}

int Controller::displayUsers()
{
	//check for admin password

	for(std::map<std::string, User*>::iterator it=users->begin();
		it != users->end();
		++it)
	{
		it->second->displayUser();
	}
}

std::vector<std::string> parseline(std::string line)
{
	std::istringstream iss(line);
	std::vector<std::string> results(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());
	
	return results;
}

int Controller::readFromDatabase()
{
	std::ifstream myfile;
	std::string line;

	std::string name;
	std::string password;
	myfile.open("database.txt");

	if(myfile.is_open())
	{
		while(getline(myfile, line))
		{
			std::vector<std::string> results = parseline(line);
			std::string userName = results.front();
			unsigned long int password = std::stoul(results.back());

			std::cout << "TEST: 01 " << password << "\n";

			User *user = new User(userName, password);
			users->insert(std::make_pair(userName,user));
		}
	}else
		std::cout << "UNable to openFile\n";

}

int Controller::updateDatabase()
{
	for(std::map<std::string, User*>::iterator it=users->begin();
		it != users->end();
		++it)
	{

	}
}