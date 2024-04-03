#include "RPN.hpp"

int	main(int argc, char** argv){
	if (argc != 2){
		std::cerr << "Error : input one string please" << std::endl;
		return (1);
	}
	try{
		RPN	rpn(argv[1]);
		rpn.print();
	}
	catch (const RPN::WrongInputFormaException& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}