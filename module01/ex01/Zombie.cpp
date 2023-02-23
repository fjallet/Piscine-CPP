#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->name = name;
	std::cout << "A wild Zombie named " << name << " has just appeared" << std::endl;
	return;
}

Zombie::Zombie(void){
	this->name = "";
	return;
}

Zombie::~Zombie(void){
	std::cout << this->name << " desintegrates" << std::endl;
	return;
}

void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::initname(std::string name){
	if (this->name.empty())
		this->name = name;
	return;
}