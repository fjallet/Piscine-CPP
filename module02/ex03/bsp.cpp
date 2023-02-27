#include "bsp.hpp"

Fixed	ft_scalaire(Point const a, Point const b, Point const c){
	return ((a.getX() - c.getX()) * (b.getY() - c.getY()) - \
	(a.getY() - c.getY()) * (b.getX() - c.getX()));
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	Fixed	pv1(ft_scalaire(a, b, point));
	Fixed	pv2(ft_scalaire(b, c, point));
	Fixed	pv3(ft_scalaire(c, a, point));
	if (pv1 >= 0 && pv2 >= 0 && pv3 >= 0)
		return (true);
	if (pv1 >= 0 && pv2 >= 0 && pv3 >= 0)
		return (true);
	return (false);
}