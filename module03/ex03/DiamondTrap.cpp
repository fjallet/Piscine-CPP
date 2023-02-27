#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void){
	this->_name = getName();
	std::cout << "DiamondTrap constructor called named random" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name), ClapTrap(name)\
,_name(name){
	this->_AttackDamage = this->getAttackDamage();
	this->_EnergyPoints = this->getEnergyPoints();
	this->_HitPoints = this->getHitPoints();
	std::cout << "DiamondTrap constructor called named " << name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & cpy){
	*this = cpy;
	std::cout << "DiamondTrap copy constructor called named " << this->_name << std::endl;
}

DiamondTrap::~DiamondTrap(void){
	std::cout << "DiamondTrap destructor called named " << this->_name << std::endl;
}

void	DiamondTrap::whoAmI(void){
	std::cout << "DiamonTrap name : " << this->_name << std::endl;
	std::cout << "ClapTrap name : " << getName() << std::endl;
}