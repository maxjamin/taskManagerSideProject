#ifndef TASK_H
#define TASK_H

class Task
{
private:
	int priority;
	std::string name;
public:
	Task(int priority, std::string name) : priority {priority}, name {name}
	{ }
	std::string getName() {return name; }
	void SetPriority(int newPriority) { priority = newPriority; }
};


#endif