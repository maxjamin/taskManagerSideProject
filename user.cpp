#include <iostream>
#include "user.h"
#include "task.h"
#include <map>

User::User(std::string username, unsigned long int password) : name{username},
password{password}, loggedIn{true}
{
	days = new std::map<std::string, std::priority_queue<Task*> >();
}

User::~User()
{
	//delete users;
	//users = NULL;
}

void User::addDay(std::string day)
{

	days->insert(std::make_pair(day, std::priority_queue<Task*>()));
	
}

void User::addTask(std::string day, std::string task, int priorityLevel)
{
	std::map<std::string, std::priority_queue<Task*>>:: iterator it;
	it =days->find(day);

	//make sure the day is assigned a queue
	if(it != days->end())
	{
		std::cout << "Task added\n";
		Task *tempTask = new Task(priorityLevel, task);
		it->second.push(tempTask);

	}
}

void User::displayUser()
{
	std::cout << "USER:: " << name << " - " << password <<"\n";
}
		
void User::displayDay(std::string day)
{
	std::map<std::string, std::priority_queue<Task*>>:: iterator it;
	it =days->find(day);

	//make sure the day is not empty
	if(!it->second.empty())
	{ 
		Task *task = it->second.top();
		//std::cout << "Display " << day << " root Task " << task->getName()
	  	//<< "\n";
		}
	else
	{
		std::cout << "No tasks for this day\n";
	}

}