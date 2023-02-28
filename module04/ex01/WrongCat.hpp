#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal{

	public:

	WrongCat(void);
	~WrongCat(void);

	void	makeSound(void) const;
	std::string		getType(void) const;

	protected:
	
	std::string	type;

};

#endif