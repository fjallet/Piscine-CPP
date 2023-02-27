#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap{

	public:

	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const & DiamondTrap);
	~DiamondTrap(void);

	void	whoAmI(void);
	using	ScavTrap::attack;
	using	ScavTrap::getEnergyPoints;
	using	FragTrap::getAttackDamage;
	using	FragTrap::getHitPoints;

	private :

	std::string	_name;
};

#endif