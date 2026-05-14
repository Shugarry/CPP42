#ifndef FORM_HPP
# define FORM_HPP

#include <string>

class Bureaucrat;

class Form
{
	public:
		Form(): name("default"), is_signed(false),
			grade_to_sign(1), grade_to_execute(1) {};
		Form(const Form& other): name(other.name), is_signed(other.is_signed),
			grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {};
		Form& operator=(const Form& other);
		~Form() {};

		Form(std::string name, bool is_signed,
			const int grade_to_sign, const int grade_to_execute);

		std::string get_name() const;
		bool get_is_signed() const;
		int get_grade_to_sign() const;
		int get_grade_to_execute() const;
		void be_signed(const Bureaucrat& bureaucrat);
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
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;
};

std::ostream& operator<<(std::ostream& out, const Form& b);

#endif
