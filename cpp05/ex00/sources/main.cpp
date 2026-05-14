#include "../headers/Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat a("Bob", 1);
		std::cout << a.get_name() << " grade: " << a.get_grade() << std::endl;
		a.increment_grade();
	}
	catch (const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b("Alice", 150);
		std::cout << b.get_name() << " grade: " << b.get_grade() << std::endl;
		b.decrement_grade();
	}
	catch (const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Wrong", 200);
	}
	catch (const std::exception& e)
	{
		std::cout << "Constructor exception: " << e.what() << std::endl;
	}

	return 0;
}
