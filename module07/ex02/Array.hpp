#ifndef ARRAY_HPP_
# define ARRAY_HPP_

#include <iostream>

template<typename T>
class	Array{

	public:

		Array();
		Array(unsigned int n);
		Array(Array& rhs);
		Array& operator=(Array const & rhs);
		~Array();

		T &				operator[](unsigned int index);
		T const &		operator[](unsigned int index) const;

		unsigned int	size() const;

		class OutOfBoundException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

	private:

		T*				_array;
		unsigned int	_n;

};

#endif