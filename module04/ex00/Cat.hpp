#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal{

	public:

	Cat(void);
	~Cat(void);

	virtual void	makeSound(void) const;
	virtual std::string		getType(void) const;

	protected:
	
	std::string	type;

};

#endif