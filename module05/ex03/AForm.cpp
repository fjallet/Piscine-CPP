#include "AForm.hpp"

AForm::AForm(std::string name, int gradesign, int gradeexec) : _name(name), _gradesign(gradesign), _gradeexec(gradeexec){
	this->_signed = false;
	if (gradesign < 1 || gradeexec < 1){
		throw GradeTooHighException();
	}
	if (gradesign > 150 || gradeexec > 150){
		throw GradeTooLowException();
	}
}

AForm::AForm( AForm const & rhs) : _name(rhs.getName()), _gradesign(rhs.getGradeSign()), _gradeexec(rhs.getGradeExec()){
	*this = rhs;
}

AForm&	AForm::operator=( const AForm& copy){
	if (this != &copy)
	{
		this->_signed = copy.getSigned();
	}
	return *this;
}

AForm::~AForm(){
}

std::string const	AForm::getName() const{
	return (this->_name);
}

int					AForm::getGradeSign() const{
	return (this->_gradesign);
}

int					AForm::getGradeExec() const{
	return (this->_gradeexec);
}

bool				AForm::getSigned() const{
	return (this->_signed);
}

void				AForm::beSigned(Bureaucrat a){
	if (a.getGrade() > this->getGradeSign()){
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
}

const char*			AForm::GradeTooHighException::what() const throw(){
	return ("grade too high");
}

const char*			AForm::GradeTooLowException::what() const throw(){
	return ("grade too low");
}

const char*			AForm::NotSignedException::what() const throw(){
	return ("form not signed");
}

std::ostream &		operator<<(std::ostream & o, AForm const & i){
	o << i.getName() << ", AForm need grade " << i.getGradeSign() << " to sign and grade " << i.getGradeExec() << " to execute, actual status: ";
	if (i.getSigned() == true)
		o << "signed" << std::endl;
	else
		o << "not signed" << std::endl;
	return (o);
}

