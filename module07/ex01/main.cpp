#include "iter.hpp"

template<typename T>
void	display(T const & param){
	std::cout << param << "  ";
}

template<typename T>
void	increment(T const & param){
	(const_cast<T&>(param))++;
}


int main(){
	int	array[9] = {1,2,3,4,5,6,7,8,9};

	iter(array, 9, &display);
	std::cout << std::endl;
	::iter(array, 9, &increment);
	::iter(array, 9, &display);
	std::cout << std::endl;
	return (0);
}