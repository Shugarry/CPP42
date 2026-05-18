#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/Bureaucrat.hpp"
#include <iostream>
#include <fstream>

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat)
{
	if (get_is_signed() == false)
		throw AForm::FormNotSignedException();
	else if (bureaucrat.get_grade() > get_grade_to_execute())
		throw AForm::GradeTooLowException();
	else
	{
		std::string filename = target + "_shrubbery";
		std::ofstream file(filename.c_str());
		if (file.is_open() == false)
		{
			std::cerr << "Failed to open file\n";
			return ;
		}
		file << "          *          \n"
			<< "         ***         \n"
			<< "        *****        \n"
			<< "       *******       \n"
			<< "      *********      \n"
			<< "     ***********     \n"
			<< "    *************    \n"
			<< "   ***************   \n"
			<< "  *****************  \n"
			<< " ******************* \n"
			<< "*********************\n"
			<< "         ***         \n"
			<< "         ***         \n"
			<< "         ***         \n";
		file.close();
	}
}

