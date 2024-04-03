#ifndef EASYFIND_TPP_
# define EASYFIND_TPP_

#include "easyfind.hpp"
#include <algorithm>
#include <iostream>

template<typename T>
typename T::iterator	easyfind(T & cont, int i){
	typename T::iterator it = std::find(cont.begin(), cont.end(), i);
	return it;
}

#endif