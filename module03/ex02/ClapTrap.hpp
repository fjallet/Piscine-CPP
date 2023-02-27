#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap{

	public:

	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & ClapTrap);
	~ClapTrap(void);

	ClapTrap &	operator=(ClapTrap const & rhs);

	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);

	std::string	getName(void) const;
	int			getHitPoints(void) const;
	int			getEnergyPoints(void) const;
	int			getAttackDamage(void) const;

	protected :
	
	std::string	_name;
	int			_HitPoints;
	int			_EnergyPoints;
	int			_AttackDamage;

};

#endif