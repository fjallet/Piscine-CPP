#include "Form.hpp"

Form::Form(std::string name, int gradesign, int gradeexec) : _name(name), _gradesign(gradesign), _gradeexec(gradeexec){
	this->_signed = false;
	if (gradesign < 1 || gradeexec < 1){
		throw GradeTooHighException();
	}
	if (gradesign > 150 || gradeexec > 150){
		throw GradeTooLowException();
	}
}

Form::Form( Form const & rhs) : _name(rhs.getName()), _gradesign(rhs.getGradeSign()), _gradeexec(rhs.getGradeExec()){
	*this = rhs;
}

Form&	Form::operator=( const Form& copy){
	if (this != &copy)
	{
		this->_signed = copy.getSigned();
	}
	return *this;
}

Form::~Form(){
}

std::string const	Form::getName() const{
	return (this->_name);
}

int					Form::getGradeSign() const{
	return (this->_gradesign);
}

int					Form::getGradeExec() const{
	return (this->_gradeexec);
}

bool				Form::getSigned() const{
	return (this->_signed);
}

void				Form::beSigned(Bureaucrat a){
	if (a.getGrade() > this->getGradeSign()){
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
}

const char*			Form::GradeTooHighException::what() const throw(){
	return ("grade too high");
}

const char*			Form::GradeTooLowException::what() const throw(){
	return ("grade too low");
}

std::ostream &		operator<<(std::ostream & o, Form const & i){
	o << i.getName() << ", Form need grade " << i.getGradeSign() << " to sign and grade " << i.getGradeExec() << " to execute, actual status: ";
	if (i.getSigned() == true)
		o << "signed" << std::endl;
	else
		o << "not signed" << std::endl;
	return (o);
}
