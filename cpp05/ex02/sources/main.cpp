#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat weak("Weak", 150);
	Bureaucrat strong("Strong", 1);
	Bureaucrat mid("Mid", 72);

	std::cout << "\n-- ShrubberyCreationForm --\n";
	{
		ShrubberyCreationForm shrub("home");
		weak.sign_form(shrub);
		strong.execute_form(shrub);
		strong.sign_form(shrub);
		strong.execute_form(shrub);
	}

	std::cout << "\n-- RobotomyRequestForm --\n";
	{
		RobotomyRequestForm robot("Bender");
		weak.sign_form(robot);
		strong.execute_form(robot);
		strong.sign_form(robot);
		strong.execute_form(robot);
	}

	std::cout << "\n-- PresidentialPardonForm --\n";
	{
		PresidentialPardonForm pardon("Marvin");
		weak.sign_form(pardon);
		strong.execute_form(pardon);
		strong.sign_form(pardon);
		strong.execute_form(pardon);
	}

	std::cout << "\n-- Edge case: sign but not execute --\n";
	{
		RobotomyRequestForm robot("Marvin");
		mid.sign_form(robot);
		mid.execute_form(robot);
		strong.execute_form(robot);
	}

	return 0;
}
