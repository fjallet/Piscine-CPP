#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap{

	public:

	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const & FragTrap);
	~FragTrap(void);

	void	highFivesGuys(void) const;

	protected:

	void		setHitPoints(void);
	void		setAttackDamage(void);

};

#endif