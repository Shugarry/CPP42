#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanB(std::string name): name(name), weapon(NULL) {};
		~HumanB() {};

		void attack() const;
		void set_weapon(Weapon &weapon);
};

#endif
