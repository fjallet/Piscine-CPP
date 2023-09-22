#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	/*Bureaucrat denis("denis", 5);
	std::cout << denis << std::endl;
	denis.upgrade();
	std::cout << denis << std::endl;
	denis.downgrade();
	std::cout << denis << std::endl;
	denis.setGrade(150);
	std::cout << denis << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	Bureaucrat jean("jean", 0);
	Bureaucrat jean2("jean", 151);
	std::cout << "-----------------------------------------------" << std::endl;
	Bureaucrat jean3("jean", 1);
	std::cout << jean3 << std::endl;
	jean3.upgrade();
	std::cout << jean3 << std::endl;
	jean3.downgrade();
	std::cout << jean3 << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	Bureaucrat jean4("jean", 150);
	std::cout << jean4 << std::endl;
	jean4.downgrade();
	std::cout << jean4 << std::endl;
	jean4.upgrade();
	std::cout << jean4 << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;*/
	Bureaucrat	alex("alex", 150);
	Bureaucrat	boris("boris", 2);
	Form		contrat("CDD", 100, 5);
	std::cout << contrat << std::endl;
	contrat.beSigned(alex);
	std::cout << contrat << std::endl;
	contrat.beSigned(boris);
	std::cout << contrat << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	Form		a("a", 151, 0);
	a.beSigned(alex);
	std::cout << a<< std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
	Form		b("b", 0, 151);
	b.beSigned(alex);
	std::cout << b << std::endl;
	return (0);
}