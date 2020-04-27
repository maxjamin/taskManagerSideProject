#include <iostream>
#include "user.h"
#include <map>

User::User(std::string username, unsigned long int password) : name{username},
password{password}, loggedIn{true}
{
	//users = new std::map<std::string, User*>();
}

User::~User()
{
	//delete users;
	//users = NULL;
}


void User::displayUser()
{
	std::cout << "USER:: " << name << " - " << password <<"\n";
}
		
void User::displayDay(int day, int month, int year)
{

}