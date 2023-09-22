#include "AMateria.hpp"

AMateria::AMateria(void){
	this->_type = "";
	//std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type){
	this->_type = type;
	//std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & cpy){
	*this = cpy;
	//std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria(void){
	//std::cout << "AMateria destructor called" << std::endl;
}

AMateria &	AMateria::operator=(AMateria const & rhs){
	this->_type = rhs.getType();
	return (*this);
}

std::string const &	AMateria::getType(void) const{
	return(this->_type);
}

void				AMateria::use(ICharacter& target){

}

AMateria* AMateria::clone() const{
	return (AMateria*)this;
}

