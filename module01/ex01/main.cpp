#include "Zombie.hpp"

int	main(void){
	Zombie *pierre;
	int n = 5;
	pierre = zombieHorde(n,"Pierre");
	for (int i = 0; i < n; i++){
		pierre[i].announce();
	}
	delete [] pierre;
	return (0);
}