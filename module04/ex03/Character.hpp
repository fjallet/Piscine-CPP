#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"


class Character : public ICharacter{

public:
	Character(std::string name);
	virtual ~Character();

	Character(Character const & rhs);
	Character &	operator=(Character const & cpy);

	std::string const & getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria*	_inv[4];

};

#endif
