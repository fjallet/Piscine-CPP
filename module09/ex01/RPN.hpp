#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <locale>

class	RPN {

	public:

		RPN(std::string input);
		RPN(RPN const & rhs);
		RPN& operator=(RPN const & rhs);
		~RPN();

		void	parsing(std::string date);

		void	print();

		void	sum();
		void	sub();
		void	mul();
		void	div();

		class WrongInputFormaException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class AccessFileException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class NegativeNumberException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class WrongDateException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class TooLargeException : public std::exception{
			public:
				virtual const char* what() const throw();
		};
	
	private:

		std::stack<int>	_stack;
};

std::ostream &	operator<<(std::ostream & o, RPN const & i);

#endif