#include "Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(void){
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const & cpy){
	*this = cpy;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &	Brain::operator=(Brain const & rhs){
	if (this != &rhs){
		for(int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}