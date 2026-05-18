#include "../headers/Intern.hpp"
#include "iostream"

int main()
{
	Intern intern;
	AForm* form;

	form = intern.make_form("ShrubberyCreationForm", "default");
	std::cout << *form << std::endl;
	delete form;
	form = intern.make_form("RobotomyRequestForm", "default");
	std::cout << *form << std::endl;
	delete form;
	form = intern.make_form("PresidentialPardonForm", "default");
	std::cout << *form << std::endl;
	delete form;
	form = intern.make_form("NonexistantForm", "default");
	std::cout << form << std::endl;
}
