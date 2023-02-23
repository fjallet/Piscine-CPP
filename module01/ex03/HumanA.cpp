#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA(std::string name, Weapon type){
	this->name = name;
	this->type = &type;
}

HumanA::~HumanA(void){
	std::cout << "HumanA constructor called" << std::endl;
	return;
}

void	HumanA::attack(void){
	if (this->type->getType().empty())
		std::cout << "Get a weapon before attacking !!" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->type->getType() << std::endl;
	return;
}

void	HumanA::setWeapon(Weapon type){
	this->type = &type;
}