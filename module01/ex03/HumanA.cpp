#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA(std::string name1, Weapon& type1) : name(name1), type(type1) {
	std::cout << "HumanA constructor called" << std::endl;
}

HumanA::~HumanA(void){
	std::cout << "HumanA destructor called" << std::endl;
	return;
}

void	HumanA::attack(void){
	std::cout << this->name << " attacks with their " << this->type.getType() << std::endl;
	return;
}

void	HumanA::setWeapon(Weapon& type){
	this->type = type;
}