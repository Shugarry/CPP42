#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& f)
{
	out << f.get_name() << ", bureaucrat grade " << f.get_grade() << ".";
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
	--grade;
}

void Bureaucrat::decrement_grade()
{
	if (grade >= 150)
		throw GradeTooLowException();
	++grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

void Bureaucrat::sign_form(Form& form)
{
	try
	{
		form.be_signed(*this);
		std::cout << name << " signed " << form.get_name() << std::endl;
	}
	catch (const Form::GradeTooLowException& e)
	{
		std::cout << name << " couldn't sign "
			<< form.get_name() << " because " << e.what() << std::endl;
	}
}
