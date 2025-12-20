#include <iostream>
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
	std::string command;
	std::string input[5];
	int oldest;
	int contactCount;
	int j;

	oldest = 0;
	contactCount = 1;
	j = 0;
	while(1)
	{
		std::cout << "Enter a command:" << std::endl;
		std::getline(std::cin, command);
		if(command == "ADD")
		{
			if(contactCount <= 8)
			{
				std::cout << "Enter First Name:" << std::endl;
				std::getline(std::cin, input[0]);			
				std::cout << "Enter Last Name:" << std::endl;
				std::getline(std::cin, input[1]);
				std::cout << "Enter Nick Name:" << std::endl;
				std::getline(std::cin, input[2]);
				std::cout << "Enter Phone Number:" << std::endl;
				std::getline(std::cin, input[3]);
				std::cout << "Enter Darkest Secret:" << std::endl;
				std::getline(std::cin, input[4]);
				phonebook.addContact(contactCount -1, input);
			}
			else
			{
				if(oldest >=8)
					oldest = 0;
				std::cout << "Enter First Name:" << std::endl;
				std::getline(std::cin, input[0]);			
				std::cout << "Enter Last Name:" << std::endl;
				std::getline(std::cin, input[1]);
				std::cout << "Enter Nick Name:" << std::endl;
				std::getline(std::cin, input[2]);
				std::cout << "Enter Phone Number:" << std::endl;
				std::getline(std::cin, input[3]);
				std::cout << "Enter Darkest Secret:" << std::endl;
				std::getline(std::cin, input[4]);
				phonebook.addContact(oldest, input);
				oldest++;
			}
			contactCount++;
		}
		else if(command == "SEARCH")
		{
				std::cout << "     Index|First Name| Last Name| Nick Name" << std::endl;
				phonebook.displayContacts(contactCount);
		}
		else if(command == "EXIT")
			break;
		else
			continue;
	}

	return 0;
}