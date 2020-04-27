#include <iostream>
#include "controller.h"

int main()
{
	Controller *controller = new Controller();
	controller->readFromDatabase();

	controller->addUser("Ghost", "illNeverTell");
	controller->addUser("sam", "password");
	controller->addUser("sierra", "password");
	controller->displayUsers();

	std::cout << "TESTUSER is...\n";
	User *testUser = controller->login("sam", "password");

	testUser->displayUser();

	std::cout << "\n\n_________________________\n";
	controller->updateDatabase();
}