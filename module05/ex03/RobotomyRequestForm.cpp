#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : _target(target), \
AForm("RobotomyRequestForm", 72, 45){
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& src) : AForm("RobotomyRequestForm", 72, 45), _target( src._target ) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& rhs){
	this->_target = rhs.getTarget();
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor){
	try{
		if (this->getSigned() == false)
			throw AForm::NotSignedException();
		if (executor.getGrade() > this->getGradeExec())
			throw AForm::GradeTooLowException();
		std::srand(static_cast<unsigned int>(std::time(0)));
		int i = std::rand();
		std::cout << "Bzzrzzzzrz..." << std::endl;
		if (i % 2 == 0)
			std::cout << _target << " has been successfully robotomized!" << std::endl;
		else
			std::cout << "The robotomy failed on " << _target << std::endl;
	}
	catch (AForm::GradeTooLowException& e){
		std::cout << executor.getName() << " coulnd't execute " << this->getName() << " because " << e.what() << std::endl;
	}
	catch (AForm::NotSignedException& e){
		std::cout << executor.getName() << " coulnd't execute " << this->getName() << " because " << e.what() << std::endl;
	}
}

std::string		RobotomyRequestForm::getTarget(){
	return(this->_target);
}

RobotomyRequestForm::~RobotomyRequestForm(){
}
