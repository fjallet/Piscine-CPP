#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB(std::string name1){
	this->name = name1;
	std::cout << "HumanB constructor called" << std::endl;
	//this->type = &Weapon("");
	return;
}

HumanB::~HumanB(void){
	std::cout << "HumanB destructor called" << std::endl;
	return;
}

void	HumanB::attack(void){
	if (this->type->getType().empty())
		std::cout << "Get a weapon before attacking !!" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->type->getType() << std::endl;
	return;
}

void	HumanB::setWeapon(Weapon& type){
	this->type = &type;
}