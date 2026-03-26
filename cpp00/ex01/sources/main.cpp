#include "../headers/phonebook.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>

int	main(void)
{
	PhoneBook phonebook;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string secret;

	std::string command;
	while (true)
	{
		std::cout << "EXIT | ADD | SEARCH" << std::endl;
		if (!std::getline(std::cin, command))
			std::exit(1);
		if (command == "EXIT")
			return 1;
		else if (command == "ADD")
		{
			std::cout << "input first name" << std::endl;
			if (!std::getline(std::cin, first_name))
				std::exit(0);
			std::cout << "input last name" << std::endl;
			if (!std::getline(std::cin, last_name))
				std::exit(0);
			std::cout << "input nickname" << std::endl;
			if (!std::getline(std::cin, nickname))
				std::exit(0);
			std::cout << "input number" << std::endl;
			if (!std::getline(std::cin, number))
				std::exit(0);
			std::cout << "input secret" << std::endl;
			if (!std::getline(std::cin, secret))
				std::exit(0);
			phonebook.add(first_name, last_name, nickname, number, secret);
		}
		else if (command == "SEARCH")
		{
			if (phonebook.get_count() == 0)
			{
				std::cout << "No contacts in list" << std::endl;
				continue ;
			}
			std::string tmp;
			phonebook.print_contacts();
			std::cout << "Type an index from 0 - " << phonebook.get_len() - 1 << " to view that contact" << std::endl;
			if (!std::getline(std::cin, tmp))
				std::exit(0);
			tmp.resize(9);
			bool flag = false;
			for (int i = 0; tmp[i]; i++)
			{
				if (isdigit(tmp[i]) == 0)
				{
					std::cout << "Only numbers from 0 - " << phonebook.get_len() - 1 << "  are accepted, aborting SEARCH" << std::endl;
					flag = true;
					break ;
				}
			}
			if (flag == true)
				continue ;
			int index = atoi(tmp.c_str());
			if (index < 0 || index > phonebook.get_len() - 1)
			{
				std::cout << "Only numbers from 0 - " << phonebook.get_len() - 1 << "  are accepted, aborting SEARCH" << std::endl;
				continue ;
			}
			phonebook.print_index(index);
		}
		else
			continue ;
	}

	return 0;
}
