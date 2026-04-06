#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void set_idea(std::string idea, int i);
		std::string get_idea(int i) const;

	private:
		std::string ideas[100];
};

#endif
