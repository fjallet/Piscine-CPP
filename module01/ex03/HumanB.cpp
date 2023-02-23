#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
	//this->type = Weapon("");
	return;
}

HumanB::~HumanB(void){
	std::cout << "HumanA constructor called" << std::endl;
	return;
}

void	HumanB::attack(void){
	if (this->type->getType().empty())
		std::cout << "Get a weapon before attacking !!" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->type->getType() << std::endl;
	return;
}

void	HumanB::setWeapon(Weapon type){
	this->type = &type;
}