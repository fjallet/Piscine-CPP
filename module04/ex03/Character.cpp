#include "Character.hpp"

Character::Character(std::string name){
	this->_name = name;
	for(int i = 0; i < 4; i++){
		this->_inv[i] = NULL;
	}
	//std::cout << "Character constructor called" << std::endl;
}

Character::Character(Character const & cpy){
	*this = cpy;
	//std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character(){
	for(int i = 0; i < 4; i++){
		if (this->_inv[i] != NULL)
			delete (this->_inv[i]);
	}
	//std::cout << "Character destructor called" << std::endl;
}

Character &	Character::operator=(Character const & rhs){
	this->_name = rhs.getName();
	for(int i = 0; i < 4; i++){
		if (rhs._inv[i] == NULL)
			this->_inv[i] = NULL;
		else
			this->_inv[i] = rhs._inv[i]->clone();
	}
	return (*this);
}

std::string const &	Character::getName(void) const{
	return(this->_name);
}

void				Character::equip(AMateria* m){
	for(int i = 0; i < 4; i++){
		if (this->_inv[i] == NULL)
		{
			this->_inv[i] = m;
			return ;
		}
	}
}

void				Character::unequip(int idx){
	if (idx >= 0 && idx < 4 && this->_inv[idx] != NULL)
		this->_inv[idx] = NULL;
}

void				Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx < 4 && this->_inv[idx])
	{
		this->_inv[idx]->use(target);
	}
}