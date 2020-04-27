#include <iostream>
#include "user.h"
#include <map>

User::User(std::string username, int password) : name{username},
password{password}
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
	std::cout << "USER:: " << name << "\n";
}
		
void User::displayDay(int day, int month, int year)
{

}