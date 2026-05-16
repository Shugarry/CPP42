#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm():
			AForm("RobotomyRequestForm", "default", 72, 45) {};
		RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {};
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm() {};

		RobotomyRequestForm(std::string target):
			AForm("RobotomyRequestForm", target, 72, 45) {};

		void execute(const Bureaucrat& bureaucrat);

};

#endif
