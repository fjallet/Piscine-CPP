#ifndef CURE_HPP
# define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class	Cure : public AMateria{

	public:

	Cure();
	virtual ~Cure();

	Cure(Cure const & rhs);
	Cure &	operator=(Cure const & cpy);

	std::string const & getType() const;
	virtual AMateria*	clone() const;
	virtual void	use(ICharacter& target);

};

#endif