#include "../headers/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.get_name() << ", bureaucrat grade " << b.get_grade() << ".";
	return out;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		grade = other.grade;
	return *this;
}

std::string Bureaucrat::get_name() const
{
	return name;
}

int Bureaucrat::get_grade() const
{
	return grade;
}

void Bureaucrat::increment_grade()
{
	if (grade <= 1)
		throw GradeTooHighException();
	++grade;
}

void Bureaucrat::decrement_grade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	--grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}
