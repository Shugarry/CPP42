#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon
{
	private:
		std::string type;

	public:
		Weapon(std::string type): type(type) {};
		~Weapon() {};

		void set_type(std::string type);
		std::string get_type() const;
};

#endif
