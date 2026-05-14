#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(): name("default"), grade(1) {};
		Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {};
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat() {};

		Bureaucrat(std::string name, int grade);

		std::string get_name() const;
		int get_grade() const;
		void increment_grade();
		void decrement_grade();
		void sign_form(Form& form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string name;
		int grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
