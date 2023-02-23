#include "Zombie.hpp"

Zombie	*newZombie(std::string name){
	Zombie	*random = new Zombie(name);
	return (random);
}