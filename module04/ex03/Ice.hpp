#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class	Ice : public AMateria{

	public:

	Ice();
	virtual ~Ice();

	Ice(Ice const & rhs);
	Ice &	operator=(Ice const & cpy);

	std::string const & getType() const;
	virtual AMateria*	clone() const;
	virtual void	use(ICharacter& target);

};

#endif