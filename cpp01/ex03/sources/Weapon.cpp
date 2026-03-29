#include "../headers/Weapon.hpp"

void Weapon::set_type(std::string type)
{
	this->type = type;
}

std::string Weapon::get_type() const
{
	return type;
}
