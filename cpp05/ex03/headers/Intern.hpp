#ifndef INTERN_HPP
# define INTERN_HPP

#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"

class Intern
{
	public:
		Intern() {};
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern() {};

		AForm* make_form(std::string name, std::string target);
};

#endif
