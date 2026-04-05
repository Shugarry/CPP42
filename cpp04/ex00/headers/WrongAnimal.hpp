#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal& other);
		WrongAnimal& operator=(WrongAnimal& other);
		virtual ~WrongAnimal();
		
		virtual void makeSound() const;

	protected:
		std::string type;
};

#endif
