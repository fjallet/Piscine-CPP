#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

class ICharacter;

class	AMateria{

	public:
	AMateria(void);
	AMateria(std::string const &type);
	virtual ~AMateria(void);
	
	AMateria(AMateria const & rhs);
	AMateria &	operator=(AMateria const & cpy);

	std::string const & getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void	use(ICharacter& target);

	protected:
	
	std::string	_type;

};

#endif