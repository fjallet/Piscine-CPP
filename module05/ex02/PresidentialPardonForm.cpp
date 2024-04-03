#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target), \
AForm("PresidentialPardonForm", 25, 5){
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& src) : AForm("PresidentialPardonForm", 25, 5), _target( src._target ) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& rhs){
	this->_target = rhs.getTarget();
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor){
	try{
		if (this->getSigned() == false)
			throw AForm::NotSignedException();
		if (executor.getGrade() > this->getGradeExec())
			throw AForm::GradeTooLowException();
		std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
	}
	catch (AForm::GradeTooLowException& e){
		std::cout << executor.getName() << " coulnd't execute " << this->getName() << " because " << e.what() << std::endl;
	}
	catch (AForm::NotSignedException& e){
		std::cout << executor.getName() << " coulnd't execute " << this->getName() << " because " << e.what() << std::endl;
	}
}

std::string		PresidentialPardonForm::getTarget(){
	return(this->_target);
}

PresidentialPardonForm::~PresidentialPardonForm(){
}
