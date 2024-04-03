#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	std::cout << "-----------------------------------------------" << std::endl;
	Bureaucrat	alex("alex", 150);
	Bureaucrat	boris("boris", 2);
	Form		contrat("CDD", 100, 5);
	std::cout << contrat;
	//contrat.beSigned(alex);
	//std::cout << contrat << std::endl;
	contrat.beSigned(boris);
	std::cout << contrat;
	std::cout << "-----------------------------------------------" << std::endl;
	//Form		a("a", 151, 0);
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}