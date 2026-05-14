#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	public:
		Bureaucrat(): name("default"), grade(1) {};
		Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade) {};
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat() {};

		std::string get_name();
		int get_grade();

	private:
		const std::string name;
		int grade;
};

#endif
