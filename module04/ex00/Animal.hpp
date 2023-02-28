#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class	Animal{

	public:

	Animal(void);
	~Animal(void);

	virtual void			makeSound(void) const;
	virtual std::string		getType(void) const;

	protected:
	
	std::string	type = "Animal";

};

#endif