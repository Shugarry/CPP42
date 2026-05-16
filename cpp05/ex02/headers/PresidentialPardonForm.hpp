#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm():
			AForm("PresidentialPardonForm", "default", 25, 5) {};
		PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {};
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm() {};

		PresidentialPardonForm(std::string target):
			AForm("PresidentialPardonForm", target, 25, 5) {};

		void execute(const Bureaucrat& bureaucrat);

};

#endif
