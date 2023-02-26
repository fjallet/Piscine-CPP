#include "bsp.hpp"

Fixed	ft_region(Point const a, Point const b, Point const point){
	if ((point.getY() - a.getY()) / (b.getX() - a.getX()) > \
	(b.getY() - a.getY()) / (b.getX() - a.getX()))
		return (1);
	return (0);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
	
	if (ft_region(a, b, point) == ft_region(b, c, point) && \
	ft_region(b, c, point) == ft_region(c, a, point))
		return (true);
	return (false);
}