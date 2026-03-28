#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(std::string name): name(name) {};
		Zombie() {};
		~Zombie();
		void set_name(std::string name);
		void announce();

};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie *zombieHorde(int n, std::string name);

#endif
