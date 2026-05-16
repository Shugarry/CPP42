#include "../headers/AForm.hpp"
#include "../headers/Bureaucrat.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& out, const AForm& b)
{
	out << "name: " << b.get_name() << ", is signed: " << b.get_is_signed()
		<< ", grade to sign: " << b.get_grade_to_sign()
		<< ", grade to execute: " << b.get_grade_to_execute()
		<< ", target: " << b.get_target();
	return out;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		is_signed = other.is_signed;
	return *this;
}

std::string AForm::get_name() const
{
	return name;
}

std::string AForm::get_target() const
{
	return target;
}

bool AForm::get_is_signed() const
{
	return is_signed;
}

int AForm::get_grade_to_sign() const
{
	return grade_to_sign;
}

int AForm::get_grade_to_execute() const
{
	return grade_to_execute;
}

void AForm::be_signed(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.get_grade() <= get_grade_to_sign())
		is_signed = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "form not signed";
}
