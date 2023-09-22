#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal{

	public:

	Cat(void);
	virtual ~Cat(void);

	Cat( const Cat& src );
	Cat& operator=( const Cat& src );

	virtual void	makeSound(void) const;
	virtual std::string		getType(void) const;

	private:

	Brain*		_brain;
};

#endif