#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
	//std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure( Cure const & rhs) : AMateria("Cure"){
	*this = rhs;
	//std::cout << "Cure copy constructor called" << std::endl;
}

Cure&	Cure::operator=( const Cure& copy){
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return *this;
}

Cure::~Cure(){
	//std::cout << "Cure destructor called" << std::endl;
}

void				Cure::use(ICharacter& target){
	std::cout << "* shoots an Cure bolt at " << target.getName() << " *" << std::endl;
}

AMateria*			Cure::clone() const{
	AMateria* a = new Cure(*this);
	return (a);
}
