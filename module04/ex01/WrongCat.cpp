#include "WrongCat.hpp"

WrongCat::WrongCat(void){
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat destructor called" << std::endl;
}

std::string		WrongCat::getType(void) const{
	return(this->type);
}

void	WrongCat::makeSound(void) const{
	std::cout << "miaou ;3" << std::endl;
}