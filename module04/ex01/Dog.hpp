#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal{

	public:

	Dog(void);
	~Dog(void);

	virtual void	makeSound(void) const;
	virtual std::string		getType(void) const;

	protected:
	
	std::string	type;

	private:

	Brain*		_brain;

};

#endif