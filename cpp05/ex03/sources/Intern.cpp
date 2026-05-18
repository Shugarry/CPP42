#include "../headers/Intern.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm* Intern::make_form(std::string name, std::string target)
{
	AForm* form = NULL;
	std::string shrub = "ShrubberyCreationForm";
	std::string robot = "RobotomyRequestForm";
	std::string president = "PresidentialPardonForm";
	if (name == shrub)
		form = new ShrubberyCreationForm(target);
	if (name == robot)
		form = new RobotomyRequestForm(target);
	if (name == president)
		form = new PresidentialPardonForm(target);
	return form;
}
