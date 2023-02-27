#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap{

	public:

	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const & ScavTrap);
	~ScavTrap(void);

	void	attack(const std::string& target);
	int		getEnergyPoints(void) const;

	void	guardGate(void) const;
};

#endif