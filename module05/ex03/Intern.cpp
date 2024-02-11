#include "Intern.hpp"

Intern::Intern(){
	_formnames[0] = "Shrubbery creation";
	_formnames[1] = "robotomy request";
	_formnames[2] = "presidential pardon";
	_formptr[0] = &Intern::makeShrubbery;
	_formptr[1] = &Intern::makeRobotomy;
	_formptr[2] = &Intern::makePresidential;
}

Intern::Intern(Intern const & rhs){
	*this = rhs;
}

Intern& Intern::operator=(const Intern& other) {
	return *this;
}

Intern::~Intern() {
}

AForm*	Intern::makeForm(std::string name, std::string target){
	AForm* form = NULL;
	for(int i = 0; i < 3; i++){
		if (_formnames[i] == name){
			form = (this->*_formptr[i])(target);
			std::cout << "Intern create " << form->getName() << std::endl;
			return form;
		}
	}
	std::cout << "Intern can't create " << name << " : Invalid form name" << std::endl;
	return NULL;
}

AForm*	Intern::makePresidential(std::string target) const {
	AForm*	form = new PresidentialPardonForm(target);
	return form;
}

AForm*	Intern::makeRobotomy(std::string target) const {
	AForm*	form = new RobotomyRequestForm(target);
	return form;
}

AForm*	Intern::makeShrubbery(std::string target) const {
	AForm*	form = new ShrubberyCreationForm(target);
	return form;
}