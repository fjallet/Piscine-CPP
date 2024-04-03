#ifndef WHATEVER_HPP_
# define WHATEVER_HPP_

template<typename T>
void	swap( T & a, T & b){
	T temp;
	temp = a;
	a = b;
	b = temp;
	return ;
}

template<typename T>
T	min(T const & a, T const & b){
	if (b <= a)
		return (b);
	return (a);
}

template<typename T>
T	max(T const & a, T const & b){
	if (b >= a)
		return (b);
	return (a);
}

#endif