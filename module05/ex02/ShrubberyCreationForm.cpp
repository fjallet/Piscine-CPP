#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target), \
AForm("ShrubberyCreationForm", 145, 137){
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& src) : AForm("ShrubberyCreationForm", 145, 137), _target( src._target ) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& rhs){
	this->_target = rhs.getTarget();
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor){
	try{
		if (this->getSigned() == false)
			throw AForm::NotSignedException();
		if (executor.getGrade() > this->getGradeExec())
			throw AForm::GradeTooLowException();
		std::ofstream file( this->getTarget() + "_shrubbery" );
		file << "          &&& &&  & &&" << std::endl;
		file << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
		file << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
		file << "   &() &\\/&|()|/&\\/ '%\" & ()" << std::endl;
		file << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
		file << "&&   && & &| &| /& & % ()& /&&" << std::endl;
		file << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
		file << "     &&     \\|||" << std::endl;
		file << "             |||" << std::endl;
		file << "             |||" << std::endl;
		file << "             |||" << std::endl;
		file << "       , -=-~  .-^- _" << std::endl;
	}
	catch (AForm::GradeTooLowException& e){
		std::cout << executor.getName() << " coulnd't execute " << this->getName() << " because " << e.what() << std::endl;
	}
	catch (AForm::NotSignedException& e){
		std::cout << executor.getName() << " coulnd't execute " << this->getName() << " because " << e.what() << std::endl;
	}

}

std::string		ShrubberyCreationForm::getTarget(){
	return(this->_target);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}
