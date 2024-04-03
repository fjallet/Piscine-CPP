#ifndef ITER_HPP_
# define ITER_HPP_

#include <iostream>

template<typename T>
void	iter(T * adr, std::size_t len, void (*f)(T const &)){
	for (std::size_t i = 0; i < len; i++){
		f(adr[i]);
	}
}

template<typename T>
void	iter(T * adr, std::size_t len, void (*f)(T &)){
	for (std::size_t i = 0; i < len; i++){
		f(adr[i]);
	}
}


#endif