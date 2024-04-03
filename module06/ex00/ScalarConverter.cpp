#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter& src){}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& rhs){
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

void	ScalarConverter::convert(const std::string& str){
	std::string pseudolit[8] = {"inff", "-inff", "+inff", "nanf", "inf", "-inf", "+inf", "nan"};
	std::string	c = "";
	int			i = 0;
	float		f = 0;
	double		d = 0;

	if ((str.size() > 1 && !std::isdigit(str[0]) && !std::isdigit(str[1])) || str == ""){
		std::cout << "char : 'non displayable'" << std::endl;
		std::cout << "int : 0" << std::endl;
		std::cout << "float : 0.0f" << std::endl;
		std::cout << "double : 0.0" << std::endl;
		return ;
	}
	if ((str.size() > 1 && !std::isdigit(str[0]) && str[0] != '-' \
	&& str[0] != '+' && std::isdigit(str[1])) || str == ""){
		std::cout << "char : 'non displayable'" << std::endl;
		std::cout << "int : 0" << std::endl;
		std::cout << "float : 0.0f" << std::endl;
		std::cout << "double : 0.0" << std::endl;
		return ;
	}
	for(int j = 0; j < 8; j++){
		if (str == pseudolit[j]){
			std::cout << "char : " << "impossible" << std::endl;
			std::cout << "char : " << "impossible" << std::endl;
			if (j < 4){
				std::cout << "char : " << pseudolit[j] << std::endl;
				std::cout << "int : " << pseudolit[j + 4] << std::endl;
			}
			else{
				std::cout << "float : " << pseudolit[j - 4] << std::endl;
				std::cout << "double : " << pseudolit[j] << std::endl;
			}
			return;
		}
	}
	if (str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0])){
		c = str[0];
		std::cout << "char : '" << c << "'" << std::endl;
		std::cout << "int : " << static_cast<int>(c[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(c[0]) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(c[0]) << ".0" << std::endl;
		return;
	}
	if (str[str.length() - 1] == 'f'){
		f = std::stof(str);
		i = static_cast<int>(f);
		if (i <= 127 && i >= 0 && std::isprint(i))
			std::cout << "char : '" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char : '" << "non displayable" << "'" << std::endl;
		std::cout << "int : " << static_cast<int>(f) << std::endl;
		std::cout << "float : " << f << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(f) << std::endl;
		return;
	}
	i = std::atoi(str.c_str());
	d = std::stod(str);
	f = std::stof(str);
	if (i <= 127 && i >= 0 && std::isprint(i))
		std::cout << "char : '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char : '" << "non displayable" << "'" << std::endl;
	std::cout << "int : " << i << std::endl;
	std::cout << "float : " << f << ".0f" << std::endl;
	std::cout << "double : " << d << std::endl;
}


