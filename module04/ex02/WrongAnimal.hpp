#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal{

	public:

	WrongAnimal(void);
	virtual ~WrongAnimal(void);
	WrongAnimal(WrongAnimal const & rhs);

	WrongAnimal &	operator=(WrongAnimal const & cpy);

	void			makeSound(void) const;
	std::string		getType(void) const;

	protected:
	
	std::string	type;

};

#endif