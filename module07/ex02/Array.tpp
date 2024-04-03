#ifndef ARRAY_TPP_
# define ARRAY_TPP_
#include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(NULL), _n(0){
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _n(n){
}

template<typename T>
Array<T>::Array(Array& rhs) : _array(NULL), _n(0){
	*this = rhs;
}

template<typename T>
Array<T>& Array<T>::operator=(Array const & rhs){
	if (this == &rhs)
		return (*this);
	if (_array != NULL){
		delete[] _array;
		_array = NULL;
	}
	_n = 0;
	_n = rhs.size();
	_array = new T[_n];
	for(unsigned int i = 0; i < _n; i++){
		_array[i] = rhs[i];
	}
	return (*this);
}

template<typename T>
T &				Array<T>::operator[](unsigned int index){
	if (index >= _n || index < 0)
		throw Array::OutOfBoundException();
	else
		return (_array[index]);
}

template<typename T>
T const &		Array<T>::operator[](unsigned int index) const{
	if (index >= _n || index < 0)
		throw Array::OutOfBoundException();
	else
		return (_array[index]);
}

template<typename T>
unsigned int	Array<T>::size() const{
	return (this->_n);
}

template<typename T>
const char*			Array<T>::OutOfBoundException::what() const throw(){
	return ("index is out of bound!");
}

template<typename T>
Array<T>::~Array(){
	delete[] _array;
}

#endif