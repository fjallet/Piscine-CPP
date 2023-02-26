#ifndef BSP_HPP
# define BSP_HPP

#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"

typedef struct	s_vect{
	Fixed	a;
	Fixed	b;
}		t_vect;

bool bsp( Point const a, Point const b, Point const c, Point const point);


#endif