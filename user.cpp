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
	delete days;
	days = NULL;
}

void User::addDay(std::string day)
{
	std::map<std::string, std::priority_queue<Task*>>:: iterator it;
	it =days->find(day);

	days->insert(std::make_pair(day, std::priority_queue<Task*>()));	
}

void User::addTask(std::string day, std::string task, int priorityLevel)
{
	std::map<std::string, std::priority_queue<Task*>>:: iterator it;
	it =days->find(day);

	//make sure the day is assigned a queue
	if(it == days->end())
	{
		std::cout << "No day.. adding day before making task\n";
		addDay(day);
		//find newly created inserted pair and update iterator variable 
		it = days->find(day);

	}

	std::cout << "Task added\n";
	it->second.push(new Task(priorityLevel, task));

	std::cout << "Day is " << it->second.empty() << "\n";

}

void User::displayUser()
{
	std::cout << "USER:: " << name << " - " << password <<"\n";
}
		
void User::displayTopPriorityDay(std::string day)
{
	std::map<std::string, std::priority_queue<Task*>>:: iterator it;
	it =days->find(day);
	std::string userInput;

	//make sure the day is not empty
	if(!it->second.empty() && it != days->end())
	{ 
		Task * task = it->second.top();
		std::cout << "\nTop task for ";
		task->displayTask();
		std::cout << "For: " << day << "\n";

		std::cout << "Has the task been completed? (y/n): ";
		std::getline(std::cin, userInput);

		if(userInput == "n");
		{	std::cout << "erase task " << userInput << "\n";
			//it->second.pop();
			task = NULL;
		}

	}
	else
	{
		std::cout << "No tasks for this day\n";
	}

}