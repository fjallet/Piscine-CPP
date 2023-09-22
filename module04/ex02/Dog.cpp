#include "Dog.hpp"

Dog::Dog(void){
	this->type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog& src ){
	*this = src;
	std::cout << "Dog copy constructor called" << std::endl;
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

Dog& Dog::operator=( const Dog& src )
{
	if (this != &src)
	{
		this->type = src.type;
		this->_brain = new Brain( *src._brain );
	}
	return *this;
}