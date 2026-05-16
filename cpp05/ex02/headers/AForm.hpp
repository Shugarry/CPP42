#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>

class Bureaucrat;

class AForm
{
	public:
		AForm(): name("default"), is_signed(false),
			grade_to_sign(1), grade_to_execute(1) {};
		AForm(const AForm& other): name(other.name), is_signed(other.is_signed),
			grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {};
		AForm& operator=(const AForm& other);
		virtual ~AForm() {};

		AForm(std::string name, std::string target, int grade_to_sign, int grade_to_execute):
			name(name),
			target(target),
			is_signed(false),
			grade_to_sign(grade_to_sign),
			grade_to_execute(grade_to_execute) {};

		std::string get_name() const;
		bool get_is_signed() const;
		std::string get_target() const;
		int get_grade_to_sign() const;
		int get_grade_to_execute() const;
		void be_signed(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat& bureaucrat) = 0;
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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	
	private:
		const std::string name;

	protected:
		std::string target;

	private: 
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;
};

std::ostream& operator<<(std::ostream& out, const AForm& b);

#endif
