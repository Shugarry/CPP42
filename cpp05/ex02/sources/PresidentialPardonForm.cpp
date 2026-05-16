#include "../headers/PresidentialPardonForm.hpp"
#include "../headers/Bureaucrat.hpp"
#include <iostream>

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat)
{
	if (get_is_signed() == false)
		throw AForm::FormNotSignedException();
	else if (bureaucrat.get_grade() > get_grade_to_execute())
		throw AForm::GradeTooLowException();
	else
		std::cout << "target: " << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

