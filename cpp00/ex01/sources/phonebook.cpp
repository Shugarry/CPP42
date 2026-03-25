#include "../headers/phonebook.hpp"
#include <iostream>
#include <iomanip>

int	PhoneBook::get_count(void)
{
	return count;
}

void	PhoneBook::set_count(int count)
{
	this->count = count;
}

void	PhoneBook::add(std::string first_name, std::string last_name, \
		std::string nickname, std::string number, std::string secret)
{
	if (first_name.empty() || last_name.empty() || nickname.empty()
		|| number.empty() || secret.empty())
	{
		std::cout << "One of the contact fields is empty, aborting ADD" << std::endl;
		return ;
	}
	set_count(count + 1);
	contacts[(count - 1) % 8].set_first_name(first_name);
	contacts[(count - 1) % 8].set_last_name(last_name);
	contacts[(count - 1) % 8].set_nickname(nickname);
	contacts[(count - 1) % 8].set_number(number);
	contacts[(count - 1) % 8].set_secret(secret);
}

std::string truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::print_contacts()
{
    int count = this->count;
    if (count > 8)
        count = 8;

    std::cout << std::right
              << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << std::right
                  << std::setw(10) << i << "|"
                  << std::setw(10) << truncate(contacts[i].get_first_name()) << "|"
                  << std::setw(10) << truncate(contacts[i].get_last_name()) << "|"
                  << std::setw(10) << truncate(contacts[i].get_nickname()) << std::endl;
    }
}

void PhoneBook::print_index(int index)
{
	std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
	std::cout << "Number: " << contacts[index].get_number() << std::endl;
	std::cout << "Secret: " << contacts[index].get_secret() << std::endl;
}

int PhoneBook::get_len()
{
	if (count > 7)
		return 7;
	return count;
}

// std::string	create_column(std::string str)
// {
// 	std::string column;
// 	int len;
//
// 	if (str.length() > 10)
// 	{
// 		column = str;
// 		column.resize(10);
// 		column[10] = '.';
// 	}
// 	else
// 	{
// 		len = 10 - str.length();
// 		std::string	tmp(len, ' ');
// 		column = tmp + str;
// 		column.resize(10);
// 	}
// 	return column;
// }
//
// void	PhoneBook::print_contacts()
// {
// 	
// 	int count = this->count;
// 	if (count > 8)
// 		count = 8;
//
// 	int i = 0;
// 	std::string column;
// 	while (i < count)
// 	{
// 		column = create_column(contacts[i].get_first_name());
// 		std::cout << column << "|";
// 		column = create_column(contacts[i].get_last_name());
// 		std::cout << column << "|";
// 		column = create_column(contacts[i].get_nickname());
// 		std::cout << column << "|";
// 		column = create_column(contacts[i].get_number());
// 		std::cout << column << std::endl;
// 		i++;
// 	}
// }
