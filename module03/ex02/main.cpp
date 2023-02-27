#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void){
	ScavTrap	jean("jean");
	FragTrap	denis("denis");
	std::cout << "-----------------------------------------------------------" << std::endl;
	jean.guardGate();
	denis.highFivesGuys();
	std::cout << "-------------------------jean------------------------------" << std::endl;
	std::cout << "Hit Points :" << jean.getHitPoints() << std::endl;
	std::cout << "Energy Points :" << jean.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage :" << jean.getAttackDamage() << std::endl;
	std::cout << "-------------------------denis-----------------------------" << std::endl;
	std::cout << "Hit Points :" << denis.getHitPoints() << std::endl;
	std::cout << "Energy Points :" << denis.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage :" << denis.getAttackDamage() << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
	jean.attack("denis");
	denis.takeDamage(20);
	denis.attack("jean");
	jean.takeDamage(30);
	std::cout << "-------------------------jean------------------------------" << std::endl;
	std::cout << "Hit Points :" << jean.getHitPoints() << std::endl;
	std::cout << "Energy Points :" << jean.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage :" << jean.getAttackDamage() << std::endl;
	std::cout << "-------------------------denis-----------------------------" << std::endl;
	std::cout << "Hit Points :" << denis.getHitPoints() << std::endl;
	std::cout << "Energy Points :" << denis.getEnergyPoints() << std::endl;
	std::cout << "Attack Damage :" << denis.getAttackDamage() << std::endl;
	std::cout << "-----------------------------------------------------------" << std::endl;
	return (0);
}