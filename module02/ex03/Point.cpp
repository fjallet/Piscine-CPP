#include "bsp.hpp"

Point::Point(void) : _x(0), _y(0){
	return;
}

Point::Point(Fixed const a, Fixed const b) : _x(a), _y(b){
	return;
}

Point::Point(Point const & a){
	*this = a;
	return;
}

Point::~Point(void){
	return;
}

Point &	Point::operator=(Point const & rhs){
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return (*this);
}

Fixed	Point::getX(void) const{
	return(this->_x);
}

Fixed	Point::getY(void) const{
	return(this->_y);
}