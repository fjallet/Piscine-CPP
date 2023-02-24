#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon(std::string type1){
	this->type = type1;
	std::cout << "Weapon constructor called" << std::endl;
	return;
}

//Weapon::Weapon(std::string* type1) : type(type1){
//	std::cout << "Weapon constructor called" << std::endl;
//	return;
//}

Weapon::Weapon(void){
	this->type = "fist";
	std::cout << "Weapon constructor called" << std::endl;
	return;
}

Weapon::~Weapon(void){
	std::cout << "Weapon destructor called" << std::endl;
}

std::string	Weapon::getType(void) const{
	return(this->type);
}

void		Weapon::setType(std::string type){
	this->type = type;
	return;
}