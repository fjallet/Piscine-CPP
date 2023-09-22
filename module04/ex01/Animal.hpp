#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal{

	public:

	Animal(void);
	virtual ~Animal(void);
	Animal(Animal const & rhs);

	Animal &	operator=(Animal const & cpy);

	virtual void			makeSound(void) const;
	virtual std::string		getType(void) const;

	protected:
	
	std::string	type;

};

#endif