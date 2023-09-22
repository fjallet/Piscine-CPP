#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & cpy){
	*this = cpy;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & rhs){
	this->type = rhs.getType();
	return (*this);
}

std::string		WrongAnimal::getType(void) const{
	return(this->type);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "AGAKGAKGAKGAK !" << std::endl;
}