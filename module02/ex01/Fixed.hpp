#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{

public:

	Fixed(void);
	Fixed(int const n);
	Fixed(float const n);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &	operator=(Fixed const & rhs);
	int		getRawBits(void) const;
	void	setRawBits( int const raw );
	float	toFloat(void) const;
	int		toInt(void) const;

private:

	int	_nvf;
	static int const _nbf;

};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif