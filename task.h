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
	Task(const Task &task) : priority {task.priority}, name {task.name}
	{ }
	std::string getName() {return name; }
	int getPriority() {return priority; }
	void setName(std::string newName) { name = newName; } 
	void SetPriority(int newPriority) { priority = newPriority; }
	void displayTask();
};


#endif