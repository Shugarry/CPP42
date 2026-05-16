#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat)
{
	if (get_is_signed() == false)
		throw AForm::FormNotSignedException();
	else if (bureaucrat.get_grade() > get_grade_to_execute())
		throw AForm::GradeTooLowException();
	else
	{
		std::srand(std::time(0));
		int x = std::rand() % 2;
		std::cout << "* DRILLING NOISES *" << std::endl;
		if (x == 0)
			std::cout << "target: " << target << " has been robotomized successfully" << std::endl;
		else 
			std::cout << "target: " << target << " couldn't be robotomized due to random failure" << std::endl;
	}
}

