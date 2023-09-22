#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class	Brain{

	public:

	Brain(void);
	~Brain(void);
	Brain(Brain const & rhs);

	Brain &	operator=(Brain const & cpy);

	std::string	ideas[100];
};

#endif