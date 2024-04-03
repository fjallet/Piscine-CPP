#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class	Span {

	public:

		Span();
		Span(unsigned int n);
		Span(Span const & src);
		Span& operator=(Span const & rhs);
		~Span();

		int							getSize() const;
		std::vector<int>			getVect() const;
		std::vector<int>::iterator	getIt() const;

		void	addNumber(int a);
		void	fill(int n);
		int		shortestSpan() const;
		int		longestSpan() const;

		class SpanFullException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class SpanEmptyException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
	
	private:

		int		findShort(int a);
		int		findLong(int a);
	
		unsigned int				_n;
		std::vector<int>			_vect;
		int							_short;
		int							_long;
		std::vector<int>::iterator	_it;
};

std::ostream &	operator<<(std::ostream & o, Span const & i);

#endif