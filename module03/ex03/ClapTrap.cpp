#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("random"){
	this->_AttackDamage = 0;
	this->_EnergyPoints = 10;
	this->_HitPoints = 10;
	std::cout << "ClapTrap constructor called named random" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name + "_clap_name"){
	this->_AttackDamage = 0;
	this->_EnergyPoints = 10;
	this->_HitPoints = 10;
	std::cout << "ClapTrap constructor called named " << this->_name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & cpy){
	*this = cpy;
	std::cout << "ClapTrap copy constructor called named " << this->_name << std::endl;
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap destructor called named " << this->_name << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & rhs){
	this->_name = rhs.getName();
	this->_AttackDamage = rhs.getAttackDamage();
	this->_EnergyPoints = rhs.getEnergyPoints();
	this->_HitPoints = rhs.getHitPoints();
	return (*this);
}

void		ClapTrap::setName(std::string name){
	std::cout << "Changing name of ClapTrap from " << this->_name << " to " << name << std::endl;
	this->_name = name;
}

std::string	ClapTrap::getName(void) const{
	return(this->_name);
}

int			ClapTrap::getHitPoints(void) const{
	return(this->_HitPoints);
}

int			ClapTrap::getEnergyPoints(void) const{
	return(this->_EnergyPoints);
}

int			ClapTrap::getAttackDamage(void) const{
	return(this->_AttackDamage);
}

void	ClapTrap::attack(const std::string& target){
	if (this->_EnergyPoints == 0){
		std::cout << "ClapTrap " << this->_name << \
		" have 0 Energy thus can't take any action!" << std::endl;
		return;
	}
	if (this->_HitPoints == 0){
		std::cout << "ClapTrap " << this->_name << \
		" have 0 hit points and thus can't take any action!" << std::endl;
		return;
	}
	this->_EnergyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " \
	<< this->_AttackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->_EnergyPoints == 0){
		std::cout << "ClapTrap " << this->_name << \
		" have 0 Energy thus can't take any action!" << std::endl;
		return;
	}
	if (this->_HitPoints == 0){
		std::cout << "ClapTrap " << this->_name << \
		" have 0 hit points and thus can't take any action!" << std::endl;
		return;
	}
	this->_EnergyPoints--;
	this->_HitPoints -= amount;
	if (this->_HitPoints < 0)
		this->_HitPoints = 0;
	std::cout << "ClapTrap " << this->_name << " take damage, causing " \
	<< amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_EnergyPoints == 0){
		std::cout << "ClapTrap " << this->_name << \
		" have 0 Energy thus can't take any action!" << std::endl;
		return;
	}
	if (this->_HitPoints == 0){
		std::cout << "ClapTrap " << this->_name << \
		" have 0 hit points and thus can't take any action!" << std::endl;
		return;
	}
	this->_EnergyPoints--;
	this->_HitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired from " \
	<< amount << " hit point!" << std::endl;
}