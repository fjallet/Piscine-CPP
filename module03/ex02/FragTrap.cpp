#include "FragTrap.hpp"

FragTrap::FragTrap(void){
	this->_name = "random";
	this->_AttackDamage = 30;
	this->_EnergyPoints = 100;
	this->_HitPoints = 100;
	std::cout << "FragTrap constructor called named random" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->_AttackDamage = 30;
	this->_EnergyPoints = 100;
	this->_HitPoints = 100;
	std::cout << "FragTrap constructor called named " << name << std::endl;
}

FragTrap::FragTrap(FragTrap const & cpy){
	*this = cpy;
	std::cout << "FragTrap copy constructor called named " << this->_name << std::endl;
}

FragTrap::~FragTrap(void){
	std::cout << "FragTrap destructor called named " << this->_name << std::endl;
}

void	FragTrap::highFivesGuys(void) const{
	std::cout << "FragTrap named " << this->_name << " want to do a high-five" << std::endl;
}