#include "../headers/phonebook.hpp"

void Contact::set_first_name(std::string s)
{
	if (s.empty())
		return ;
	first_name = s;
}

void	Contact::set_last_name(std::string s)
{
	if (s.empty())
		return ;
	last_name = s;
}

void	Contact::set_nickname(std::string s)
{
	if (s.empty())
		return ;
	nickname = s;
}

void	Contact::set_secret(std::string s)
{
	if (s.empty())
		return ;
	secret = s;
}

void	Contact::set_number(std::string s)
{
	if (s.empty())
		return ;
	number = s;
}

std::string	Contact::get_first_name(void) const
{
	return first_name;
}

std::string	Contact::get_last_name(void) const
{
	return last_name;
}

std::string	Contact::get_nickname(void) const
{
	return nickname;
}

std::string	Contact::get_secret(void) const
{
	return secret;
}

std::string	Contact::get_number(void) const
{
	return number;
}
