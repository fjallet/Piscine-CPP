#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(){
	Intern		denis;
	AForm *	form1 = denis.makeForm("Shrubbery creation", "meh");
	AForm *	form2 = denis.makeForm("robotomy request", "nico");
	AForm *	form3 = denis.makeForm("presidential pardon", "felix");
	try{
	Bureaucrat	alex("alex", 150);
	Bureaucrat	boris("boris", 2);
	alex.signForm(*form1);
	boris.signForm(*form1);
	form1->execute(boris);
	//form->execute(alex);
	std::cout << "-----------------------------------------------" << std::endl;
	alex.signForm(*form2);
	boris.signForm(*form2);
	form2->execute(boris);
	//form2->execute(alex);
	std::cout << "-----------------------------------------------" << std::endl;
	alex.signForm(*form3);
	boris.signForm(*form3);
	form3->execute(boris);
	//form3->execute(alex);
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	delete form1;
	delete form2;
	delete form3;
	return (0);
}