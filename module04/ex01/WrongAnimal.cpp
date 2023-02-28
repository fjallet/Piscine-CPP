#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string		WrongAnimal::getType(void) const{
	return(this->type);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "AGAKGAKGAKGAK !" << std::endl;
}