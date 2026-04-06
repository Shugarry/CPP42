#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();

		void makeSound() const;
		void set_idea(std::string idea, int i);
		std::string get_idea(int i) const;

	private:
		Brain* brain;
};

#endif
