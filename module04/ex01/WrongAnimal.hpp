#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class	WrongAnimal{

	public:

	WrongAnimal(void);
	~WrongAnimal(void);

	void			makeSound(void) const;
	std::string		getType(void) const;

	protected:
	
	std::string	type = "WrongAnimal";

};

#endif