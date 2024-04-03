#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>

class	BitcoinExchange {

	public:

		BitcoinExchange(std::string const & data);
		BitcoinExchange(BitcoinExchange const & rhs);
		BitcoinExchange& operator=(BitcoinExchange const & rhs);
		~BitcoinExchange();

		void	btc(std::string input);

		std::map<std::string, float>	getMap() const;

		class WrongDataFormaException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

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

		void	findData(std::string date, float value);
		void	checkDate(std::string date);

		std::map<std::string, float>	_data;
};

std::ostream &	operator<<(std::ostream & o, BitcoinExchange const & i);

#endif