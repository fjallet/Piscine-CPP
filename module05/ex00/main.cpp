#include "Bureaucrat.hpp"

int main(){
	try{
	Bureaucrat denis("denis", 5);
	std::cout << denis << std::endl;
	denis.upgrade();
	std::cout << denis << std::endl;
	denis.downgrade();
	std::cout << denis << std::endl;
	denis.setGrade(150);
	std::cout << denis << std::endl;
	//std::cout << "-----------------------------------------------" << std::endl;
	//Bureaucrat jean("jean", 0);
	//Bureaucrat jean2("jean", 151);
	//std::cout << "-----------------------------------------------" << std::endl;
	//Bureaucrat jean3("jean", 1);
	//std::cout << jean3 << std::endl;
	//jean3.upgrade();
	//std::cout << jean3 << std::endl;
	//jean3.downgrade();
	//std::cout << jean3 << std::endl;
	//std::cout << "-----------------------------------------------" << std::endl;
	//Bureaucrat jean4("jean", 150);
	//std::cout << jean4 << std::endl;
	//.downgrade();
	//std::cout << jean4 << std::endl;
	//jean4.upgrade();
	//std::cout << jean4 << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}