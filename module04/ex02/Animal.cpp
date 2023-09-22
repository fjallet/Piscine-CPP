#include "Animal.hpp"

Animal::Animal(void){
	this->type = "Animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const & cpy){
	*this = cpy;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void){
	std::cout << "Animal destructor called" << std::endl;
}

Animal &	Animal::operator=(Animal const & rhs){
	this->type = rhs.getType();
	return (*this);
}

std::string		Animal::getType(void) const{
	return(this->type);
}

void	Animal::makeSound(void) const{
	std::cout << "*unknown sound*" << std::endl;
}