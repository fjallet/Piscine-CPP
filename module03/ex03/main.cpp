#include "DiamondTrap.hpp"

int	main(void){
	DiamondTrap	jean("jean");
	std::cout << "-------------------------jean------------------------------" << std::endl;
	std::cout << "Hit Points :" << jean.getHitPoints() << std::endl;
	std::cout << "Energy Points :" << jean.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage :" << jean.getAttackDamage() << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
	jean.attack("denis");
	jean.whoAmI();
	return (0);
}