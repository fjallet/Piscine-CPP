#include "Dog.hpp"

Dog::Dog(void){
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void){
	delete(this->_brain);
	std::cout << "Dog destructor called" << std::endl;
}

std::string		Dog::getType(void) const{
	return(this->type);
}

void	Dog::makeSound(void) const{
	std::cout << "bark bark" << std::endl;
}