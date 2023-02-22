#include "ex01.hpp"

int	main(){
	std::string line;
	PhoneBook vieuxlivre;
	do{
		getline(std::cin, line);
		if (line.compare("ADD") == 0)
			vieuxlivre.add();
		if (line.compare("SEARCH") == 0)
			vieuxlivre.search();
	}while (line.compare("EXIT") != 0);
	return (0);
}