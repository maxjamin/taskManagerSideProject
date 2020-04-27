#include <iostream>
#include "controller.h"

int main()
{
	Controller *controller = new Controller();
	controller->readFromDatabase();
	controller->displayUsers();
}