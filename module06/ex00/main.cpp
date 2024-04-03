#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cout << "Error: no parameters" << std::endl;
		return 1;
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}