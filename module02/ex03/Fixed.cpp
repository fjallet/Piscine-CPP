#include "bsp.hpp"

int const	Fixed::_nbf = 8;

Fixed::Fixed(void) : _nvf(0){
	//std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const n){
	this->_nvf = (int)((float)n * 256);
	//std::cout << "Fixed constructor called with an integer " << n << std::endl;
	return;
}

Fixed::Fixed(float const n){
	this->_nvf = (int)(n * 256.0f);
	this->_nvf++;
	//std::cout << "Fixed constructor called with a float " << n << std::endl;
	return;
}

Fixed::Fixed(Fixed const & src){
	*this = src;
	//std::cout << "Copy constructor called" << std::endl;
	return;
}

Fixed::~Fixed(void){
	//std::cout << "Destructor called" << std::endl;
	return;
}

int			Fixed::getRawBits(void) const{
	//std::cout << "getRawBits member fonction called" << std::endl;
	return (this->_nvf);
}

void		Fixed::setRawBits(int const raw){
	this->_nvf = raw;
	return;
}

/*void		Fixed::setRawBits(float const raw){
	this->_nvf = (int)(raw * 256.0f);
	return;
}*/

float		Fixed::toFloat(void) const{
	return ((float)((float)this->_nvf / 256.0f));
}

int			Fixed::toInt(void) const{
	return(roundf(this->toFloat()));
}

Fixed &		Fixed::operator=(Fixed const & rhs){
	//std::cout << "Copy assignement called" << std::endl;
	this->_nvf = rhs.getRawBits();
	return (*this);
}

Fixed		Fixed::operator+(Fixed const & rhs) const{
	Fixed	result;
	result.setRawBits(this->_nvf + rhs.getRawBits());
	return (result);
}

Fixed		Fixed::operator-(Fixed const & rhs) const{
	Fixed	result;
	result.setRawBits(this->_nvf - rhs.getRawBits());
	return (result);
}

Fixed		Fixed::operator*(Fixed const & rhs) const{
	long long	produit = (long long)this->_nvf * rhs.getRawBits();
	int	fixe = (int)(produit >> 8);
	Fixed	result;
	result.setRawBits(fixe);
	return (result);
}

Fixed		Fixed::operator/(Fixed const & rhs) const{
	Fixed	result;
	long long	numerateur = (long long)this->_nvf << 8;
	int	fixe = numerateur / rhs.getRawBits();
	result.setRawBits(fixe);
	return (result);
}

bool		Fixed::operator>(Fixed const & rhs) const{
	return (this->toFloat() > rhs.toFloat());
}

bool		Fixed::operator<(Fixed const & rhs) const{
	return (this->toFloat() < rhs.toFloat());
}

bool		Fixed::operator>=(Fixed const & rhs) const{
	return (this->toFloat() >= rhs.toFloat());
}

bool		Fixed::operator<=(Fixed const & rhs) const{
	return (this->toFloat() <= rhs.toFloat());
}

bool		Fixed::operator==(Fixed const & rhs) const{
	return (this->toFloat() == rhs.toFloat());
}

bool		Fixed::operator!=(Fixed const & rhs) const{
	return (this->toFloat() != rhs.toFloat());
}

Fixed &	Fixed::operator++(void){
	this->_nvf += 1;
	return(*this);
}

Fixed &	Fixed::operator--(void){
	this->_nvf -= 1;
	return(*this);
}

Fixed	Fixed::operator++(int){
	Fixed	temp(*this);
	this->_nvf += 1;
	return(temp);
}

Fixed	Fixed::operator--(int){
	Fixed	temp(*this);
	this->_nvf -= 1;
	return(temp);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & i){
	o << i.toFloat();
	return (o);
}

Fixed	Fixed::min(Fixed & a, Fixed & b){
	if (a > b)
		return (b);
	return (a);
}

Fixed	Fixed::min(Fixed const & a, Fixed const & b){
	if (a > b)
		return (b);
	return (a);
}

Fixed	Fixed::max(Fixed & a, Fixed & b){
	if (a > b)
		return (a);
	return (b);
}
Fixed	Fixed::max(Fixed const & a, Fixed const & b){
	if (a > b)
		return (a);
	return (b);
}