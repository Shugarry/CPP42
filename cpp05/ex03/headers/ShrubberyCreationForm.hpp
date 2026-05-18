#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm():
			AForm("ShrubberyCreationForm", "default", 145, 137) {};
		ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {};
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm() {};

		ShrubberyCreationForm(std::string target):
			AForm("ShrubberyCreationForm", target, 145, 137) {};

		void execute(const Bureaucrat& bureaucrat);

};

#endif
