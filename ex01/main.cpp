#include <iostream>
#include "PhoneBook.hpp"

bool is_alpha(std::string str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if((str[i] < 'A' || str[i] > 'Z') && (str[i] < 'a' || str[i] > 'z'))
			return false;
		i++;
	}
	return true;
}

bool is_num(std::string str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(str[i] < '0' || str[i] > '9')
			return false;
		i++;
	}
	return true;
}

int main()
{
    PhoneBook phonebook;
	std::string command;
	std::string input[5];
	int temp_index;
	int oldest;
	int contactCount;
	int j;

	temp_index = 0;
	oldest = 0;
	contactCount = 0;
	j = 0;
	while(1)
	{
		std::cout << "Enter a command:" << std::endl;
		std::getline(std::cin, command);
		if(command == "ADD")
		{
			if(contactCount < 8)
			{
				std::cout << "Enter First Name:" << std::endl;
				while (true)
				{
				    std::getline(std::cin, input[0]);
				    if (!input[0].empty() && is_alpha(input[0]))
				        break;
				    std::cout << "First Name cannot be empty or numeric. Try again:" << std::endl;
				}
				std::cout << "Enter Last Name:" << std::endl;
				while (true)
				{
				    std::getline(std::cin, input[1]);
				    if (!input[1].empty() && is_alpha(input[1]))
				        break;
				    std::cout << "Last Name cannot be empty or numeric. Try again:" << std::endl;
				}
				std::cout << "Enter Nick Name:" << std::endl;
				while (true)
				{
				    std::getline(std::cin, input[2]);
				    if (!input[2].empty() && is_alpha(input[2]))
				        break;
				    std::cout << "Nick Name cannot be empty or numeric. Try again:" << std::endl;
				}
				std::cout << "Enter Phone Number:" << std::endl;
				std::getline(std::cin, input[3]);
				while (true)
				{
    				std::cout << "Enter Phone Number:" << std::endl;
    				std::getline(std::cin, input[3]);
					if (is_num(input[3]))
        				break;
    				std::cout << "Invalid phone number! Please enter digits only." << std::endl;
				}
				std::cout << "Enter Darkest Secret:" << std::endl;
				while (true)
				{
				    std::getline(std::cin, input[4]);
				    if (!input[4].empty() && is_alpha(input[4]))
				        break;
				    std::cout << "Darkest Secret cannot be empty or numeric. Try again:" << std::endl;
				}
				phonebook.addContact(contactCount, input);
				contactCount++;
			}
			else
			{
				if(oldest >=8)
					oldest = 0;
				std::cout << "Enter First Name:" << std::endl;
				while (true)
				{
				    std::getline(std::cin, input[0]);
				    if (!input[0].empty() && is_alpha(input[0]))
				        break;
				    std::cout << "First Name cannot be empty. Try again:" << std::endl;
				}
				std::cout << "Enter Last Name:" << std::endl;
				while (true)
				{
				    std::getline(std::cin, input[1]);
				    if (!input[1].empty())
				        break;
				    std::cout << "Last Name cannot be empty. Try again:" << std::endl;
				}
				std::cout << "Enter Nick Name:" << std::endl;
				while (true)
				{
				    std::getline(std::cin, input[2]);
				    if (!input[2].empty())
				        break;
				    std::cout << "Nick Name cannot be empty. Try again:" << std::endl;
				}
				std::cout << "Enter Phone Number:" << std::endl;
				while (true)
				{
    				std::getline(std::cin, input[3]);
					if (is_num(input[3]))
        				break;
    				std::cout << "Invalid phone number! Please enter digits only." << std::endl;
				}
				std::cout << "Enter Darkest Secret:" << std::endl;
				while (true)
				{
				    std::getline(std::cin, input[4]);
				    if (!input[4].empty())
				        break;
				    std::cout << "Darkest Secret cannot be empty. Try again:" << std::endl;
				}
				phonebook.addContact(oldest, input);
				oldest++;
				// contactCount artmıyor, çünkü max 8
			}
		}
		else if(command == "SEARCH")
		{
				std::cout << "|     Index|First Name| Last Name| Nick Name|" << std::endl;
				phonebook.displayContacts(contactCount);
				std::cout << "Enter the index of the contact you want to see details for:";
				std::getline(std::cin, command);
				temp_index = std::stoi(command);
				if(temp_index < 0 || temp_index >= contactCount)
				{
					std::cout << "Invalid index!" << std::endl;
					continue;
				}
				else
					phonebook.displayContactDetails(temp_index);

		}
		else if(command == "EXIT")
			break;
		else
			continue;
	}

	return 0;
}