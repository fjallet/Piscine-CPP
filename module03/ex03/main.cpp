#include "DiamondTrap.hpp"

int	main(void){
	DiamondTrap	jean("jean");
	jean.takeDamage(20);
	std::cout << "-------------------------jean------------------------------" << std::endl;
	std::cout << "Hit Points    : " << jean.getHitPoints() << std::endl;
	std::cout << "Energy Points : " << jean.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage : " << jean.getAttackDamage() << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
	DiamondTrap	jean2(jean);
	std::cout << "-------------------------jean2-----------------------------" << std::endl;
	std::cout << "Hit Points    : " << jean2.getHitPoints() << std::endl;
	std::cout << "Energy Points : " << jean2.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage : " << jean2.getAttackDamage() << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
	jean.attack("denis");
	jean.whoAmI();
	jean.guardGate();
	jean.highFivesGuys();
	return (0);
}