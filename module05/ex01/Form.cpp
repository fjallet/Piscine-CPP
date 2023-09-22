#include "Form.hpp"

Form::Form() : _name("Form"), _gradesign(150), _gradeexec(150){
	this->_signed = false;
	//std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name, int gradesign, int gradeexec) : _name(name), _gradesign(gradesign), _gradeexec(gradeexec){
	this->_signed = false;
	try{
		if (gradesign < 1){
			throw GradeTooHighException();
		}
		else if (gradesign > 150){
			throw GradeTooLowException();
		}
	}
	catch (GradeTooHighException e){
		std::cout << "Wrong grade: Form " << name << " sign required " << e.what() << std::endl;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: Form " << name << " sign required " <<e.what() << std::endl;
	}
	try{
		if (gradeexec < 1){
			throw GradeTooHighException();
		}
		else if (gradeexec > 150){
			throw GradeTooLowException();
		}
	}
	catch (GradeTooHighException e){
		std::cout << "Wrong grade: Form " << name << " execute required " << e.what() << std::endl;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: Form " << name << " execute required " <<e.what() << std::endl;
	}
	//std::cout << "Form constructor called" << std::endl;
}

Form::Form( Form const & rhs) : _name(rhs.getName()), _gradesign(rhs.getGradeSign()), _gradeexec(rhs.getGradeExec()){
	*this = rhs;
	//std::cout << "Form copy constructor called" << std::endl;
}

Form&	Form::operator=( const Form& copy){
	if (this != &copy)
	{
		this->_signed = copy.getSigned();
	}
	return *this;
}

Form::~Form(){
	//std::cout << "Form destructor called" << std::endl;
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
	try{
		if (this->getGradeSign() < 1){
			throw GradeTooHighException();
		}
		else if (this->getGradeSign() > 150){
			throw GradeTooLowException();
		}
	}
	catch (GradeTooHighException e){
		std::cout << "Wrong grade: Form " << this->getName() << " sign required " << e.what() << std::endl;
		return;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: Form " << this->getName() << " sign required " <<e.what() << std::endl;
		return;
	}
	try{
		if (a.getGrade() > this->getGradeSign())
			throw GradeTooLowException();
		else
			this->_signed = true;
	}
	catch (GradeTooLowException e){
		std::cout << a << ": " << e.what() << std::endl;
	}
	a.signForm(*this);
}

const char*			Form::GradeTooHighException::what() const throw(){
	return ("grade is too high");
}

const char*			Form::GradeTooLowException::what() const throw(){
	return ("grade is too low");
}

std::ostream &		operator<<(std::ostream & o, Form const & i){
	o << i.getName() << ", Form need grade " << i.getGradeSign() << " to sign and grade " << i.getGradeExec() << " to execute, actual status: ";
	if (i.getSigned())
		o << "signed";
	else
		o << "yet to be signed";
	return (o);
}
