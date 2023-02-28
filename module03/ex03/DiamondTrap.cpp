#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void){
	this->_name = getName();
	std::cout << "DiamondTrap constructor called named random" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name), ClapTrap(name), _name(name){
	FragTrap::setHitPoints();
	ScavTrap::setEnergyPoints();
	FragTrap::setAttackDamage();
	std::cout << "DiamondTrap constructor called named " << name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & cpy) : ScavTrap(cpy), FragTrap(cpy), ClapTrap(cpy){
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