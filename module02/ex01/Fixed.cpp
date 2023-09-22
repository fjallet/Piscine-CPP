#include "Fixed.hpp"

int const	Fixed::_nbf = 8;

Fixed::Fixed(void) : _nvf(0){
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const n){
	this->_nvf = (int)((float)n * 256);
	std::cout << "Fixed constructor called with an integer " << n << std::endl;
	return;
}

Fixed::Fixed(float const n){
	this->_nvf = (int)(n * 256.0f);
	this->_nvf++;
	std::cout << "Fixed constructor called with a float " << n << std::endl;
	return;
}

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

float		Fixed::toFloat(void) const{
	return ((float)((float)this->_nvf / 256.0f));
}

int			Fixed::toInt(void) const{
	return(this->_nvf / 256);
}

Fixed &		Fixed::operator=(Fixed const & rhs){
	std::cout << "Copy assignement called" << std::endl;
	this->_nvf = rhs.getRawBits();
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i){
	o << i.toFloat();
	return (o);
}