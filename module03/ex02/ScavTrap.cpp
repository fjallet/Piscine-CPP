#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
	this->_name = "random";
	this->_AttackDamage = 20;
	this->_EnergyPoints = 50;
	this->_HitPoints = 100;
	std::cout << "ScavTrap constructor called named random" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->_AttackDamage = 20;
	this->_EnergyPoints = 50;
	this->_HitPoints = 100;
	std::cout << "ScavTrap constructor called named " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & cpy){
	*this = cpy;
	std::cout << "ScavTrap copy constructor called named " << this->_name << std::endl;
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap destructor called named " << this->_name << std::endl;
}

void	ScavTrap::guardGate(void) const{
	std::cout << "ScavTrap named " << this->_name << " has entered guard mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target){
	if (this->_EnergyPoints == 0){
		std::cout << "ScavTrap " << this->_name << \
		" have 0 Energy thus can't take any action!" << std::endl;
		return;
	}
	if (this->_HitPoints == 0){
		std::cout << "ScavTrap " << this->_name << \
		" have 0 hit points and thus can't take any action!" << std::endl;
		return;
	}
	this->_EnergyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " \
	<< this->_AttackDamage << " points of damage!" << std::endl;
}