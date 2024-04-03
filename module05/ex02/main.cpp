#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(){
	try{
	Bureaucrat	alex("alex", 150);
	Bureaucrat	boris("boris", 2);
	PresidentialPardonForm form1("felix");
	RobotomyRequestForm form2("nico");
	ShrubberyCreationForm form3("meh");
	form1.execute(boris);
	alex.signForm(form1);
	boris.signForm(form1);
	form1.execute(boris);
	form1.execute(alex);
	std::cout << "-----------------------------------------------" << std::endl;
	alex.signForm(form2);
	boris.signForm(form2);
	form2.execute(boris);
	form2.execute(alex);
	std::cout << "-----------------------------------------------" << std::endl;
	alex.signForm(form3);
	boris.signForm(form3);
	form3.execute(boris);
	form3.execute(alex);
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}