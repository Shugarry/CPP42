#include "../headers/Form.hpp"
#include "../headers/Bureaucrat.hpp"
#include <iostream>

Form::Form(std::string name, bool is_signed, int grade_to_sign, int grade_to_execute):
	name(name), is_signed(is_signed), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw GradeTooHighException();
	if (grade_to_sign > 150 || grade_to_execute > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& b)
{
	out << "name: " << b.get_name() << ", is signed: " << b.get_is_signed()
		<< ", grade to sign: " << b.get_grade_to_sign()
		<< ", grade to execute: " << b.get_grade_to_execute();
	return out;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		is_signed = other.is_signed;
	return *this;
}

std::string Form::get_name() const
{
	return name;
}

bool Form::get_is_signed() const
{
	return is_signed;
}

int Form::get_grade_to_sign() const
{
	return grade_to_sign;
}

int Form::get_grade_to_execute() const
{
	return grade_to_execute;
}

void Form::be_signed(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.get_grade() <= get_grade_to_sign())
		is_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "grade too low";
}
