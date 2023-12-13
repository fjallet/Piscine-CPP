#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _target("anything") AForm("Form", 25, 5){
	//std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target) \
AForm("Form", 25, 5){
	
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor){

	std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}

//PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & rhs) : _name(rhs.getName()), _gradesign(rhs.getGradeSign()), _gradeexec(rhs.getGradeExec()){
//	*this = rhs;
//	//std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
//}
//
//PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& copy){
//	if (this != &copy)
//	{
//		this->_signed = copy.getSigned();
//	}
//	return *this;
//}

PresidentialPardonForm::~PresidentialPardonForm(){
	//std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
