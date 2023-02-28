#include "Cat.hpp"

Cat::Cat(void){
	this->type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void){
	delete(this->_brain);
	std::cout << "Cat destructor called" << std::endl;
}

std::string		Cat::getType(void) const{
	return(this->type);
}

void	Cat::makeSound(void) const{
	std::cout << "miaou ;3" << std::endl;
}