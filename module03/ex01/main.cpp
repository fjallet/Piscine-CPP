#include "ScavTrap.hpp"

int	main(void){
	ScavTrap	jean("jean");
	std::cout << "-------------------------jean------------------------------" << std::endl;
	std::cout << "Hit Points :" << jean.getHitPoints() << std::endl;
	std::cout << "Energy Points :" << jean.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage :" << jean.getAttackDamage() << std::endl;
	jean.takeDamage(2);
	ScavTrap	jean2(jean);
	std::cout << "-------------------------jean2-----------------------------" << std::endl;
	std::cout << "Hit Points :" << jean2.getHitPoints() << std::endl;
	std::cout << "Energy Points :" << jean2.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage :" << jean2.getAttackDamage() << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
	jean.attack("eude");
	jean.guardGate();
	jean.beRepaired(2);
	jean.takeDamage(98);
	jean.beRepaired(2);
	jean.takeDamage(6);
	jean.attack("himself");
	return (0);
}