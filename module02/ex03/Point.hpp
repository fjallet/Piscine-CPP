#ifndef POINT_HPP
# define POINT_HPP

class	Point{

	public:

	Point(void);
	Point(Fixed const a, Fixed const b);
	Point(Point const & point);
	~Point(void);

	Point &	operator=(Point const & rhs);

	Fixed	getX(void) const;
	Fixed	getY(void) const;

	private:

	Fixed	_x;
	Fixed	_y;
};

#endif