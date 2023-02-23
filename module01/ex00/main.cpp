#include "Zombie.hpp"

int	main(void){
	Zombie *jean_eude;

	jean_eude = newZombie("Jean-Eude");
	jean_eude->announce();
	randomChump("Denis");
	randomChump("Jean-Christophe");
	delete jean_eude;

	return (0);
}