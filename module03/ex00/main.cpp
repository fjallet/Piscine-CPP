#include "ClapTrap.hpp"

int	main(void){
	ClapTrap	denis("denis");
	ClapTrap	eude("eude");
	denis.attack("eude");
	eude.takeDamage(10);
	eude.attack("denis");
	denis.attack("eude");
	denis.beRepaired(2);
	denis.beRepaired(3);
	denis.beRepaired(4);
	denis.beRepaired(5);
	denis.beRepaired(6);
	denis.beRepaired(7);
	denis.beRepaired(8);
	denis.beRepaired(9);
	denis.beRepaired(10);
	denis.beRepaired(11);
	return (0);
}