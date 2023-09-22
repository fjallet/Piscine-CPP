#include "Fixed.hpp"

int const	Fixed::_nbf = 8;

Fixed::Fixed(void) : _nvf(0){
	std::cout << "Default constructor called" << std::endl;
	return;
}

/*Fixed::Fixed(int n) : _nvf(n){
	std::cout << "Fixed constructor called with value" << n << std::endl;
	return;
}*/

Fixed::Fixed(Fixed const & src){
	*this = src;
	std::cout << "Copy constructor called" << std::endl;
	return;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	return;
}

int			Fixed::getRawBits(void) const{
	std::cout << "getRawBits member fonction called" << std::endl;
	return (this->_nvf);
}

void		Fixed::setRawBits(int const raw){
	this->_nvf = raw;
	return;
}

Fixed &		Fixed::operator=(Fixed const & rhs){
	std::cout << "Copy assignement called" << std::endl;
	if (this != &rhs)
		this->_nvf = rhs.getRawBits();
	return (*this);
}