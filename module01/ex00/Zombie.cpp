#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << "A wild Zombie named " << name << " has just appeared" << std::endl;
	return;
}

Zombie::~Zombie(void){
	std::cout << this->name << " desintegrates" << std::endl;
	return;
}

void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}