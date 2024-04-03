#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class	ScalarConverter{

	public:

		~ScalarConverter();

		static void	convert(const std::string& str);

	private:

		ScalarConverter();
		ScalarConverter(ScalarConverter& src);
		ScalarConverter& operator=(ScalarConverter& rhs);

};

#endif