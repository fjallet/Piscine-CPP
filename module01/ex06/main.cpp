#include "Harl.hpp"

int	main(void)
{
	Harl	test;
	test.complain("DEBUG");
	std::cout << "---------------------------" << std::endl;
	test.complain("INFO");
	std::cout << "---------------------------" << std::endl;
	test.complain("WARNING");
	std::cout << "---------------------------" << std::endl;
	test.complain("ERROR");
	return (0);
}