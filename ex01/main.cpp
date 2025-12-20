#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
	std::string command;
	std::string input;
	int oldest;
	int i;

	oldest = 0;
	i = 0;
	while(1)
	{
		std::cout << "Enter a command:" << std::endl;
		std::cin >> command;
		if(command == "ADD")
		{
			
		}
		else if(command == "SEARCH")
		{

		}
		else if(command == "EXIT")
			break;
		else
			continue;
	}

	return 0;
}