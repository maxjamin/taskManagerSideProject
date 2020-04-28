#include <iostream>
#include "task.h"


void Task::displayTask()
{
	std::cout << "Task: " << getName() 
	<< " \nPriority " << getPriority() << "\n";
}