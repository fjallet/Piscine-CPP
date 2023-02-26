#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{

public:

	Fixed(void);
	Fixed(int const n);
	Fixed(float const n);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed &	operator=(Fixed const & rhs);

	bool	operator>(Fixed const & rhs) const;
	bool	operator<(Fixed const & rhs)const;
	bool	operator>=(Fixed const & rhs)const;
	bool	operator<=(Fixed const & rhs)const;
	bool	operator==(Fixed const & rhs)const;
	bool	operator!=(Fixed const & rhs)const;

	Fixed	operator+(Fixed const & rhs)const;
	Fixed	operator-(Fixed const & rhs)const;
	Fixed	operator*(Fixed const & rhs)const;
	Fixed	operator/(Fixed const & rhs)const;

	Fixed &	operator++(void);
	Fixed &	operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed	min(Fixed & a, Fixed & b);
	static Fixed	min(Fixed const & a, Fixed const & b);
	static Fixed	max(Fixed & a, Fixed & b);
	static Fixed	max(Fixed const & a, Fixed const & b);

private:

	int	_nvf;
	static int const _nbf;

};

std::ostream &	operator<<(std::ostream & o, Fixed const & i);

#endif