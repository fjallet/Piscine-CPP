#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _name("PresidentialPardonForm"), _gradesign(25), _gradeexec(5){
	this->_signed = false;
	//std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string name, int gradesign, int gradeexec) : _name(name), _gradesign(gradesign), _gradeexec(gradeexec){
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
		std::cout << "Wrong grade: PresidentialPardonForm " << name << " sign required " << e.what() << std::endl;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: PresidentialPardonForm " << name << " sign required " <<e.what() << std::endl;
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
		std::cout << "Wrong grade: PresidentialPardonForm " << name << " execute required " << e.what() << std::endl;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: PresidentialPardonForm " << name << " execute required " <<e.what() << std::endl;
	}
	//std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & rhs) : _name(rhs.getName()), _gradesign(rhs.getGradeSign()), _gradeexec(rhs.getGradeExec()){
	*this = rhs;
	//std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm& copy){
	if (this != &copy)
	{
		this->_signed = copy.getSigned();
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	//std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

std::string const	PresidentialPardonForm::getName() const{
	return (this->_name);
}

int					PresidentialPardonForm::getGradeSign() const{
	return (this->_gradesign);
}

int					PresidentialPardonForm::getGradeExec() const{
	return (this->_gradeexec);
}

bool				PresidentialPardonForm::getSigned() const{
	return (this->_signed);
}

void				PresidentialPardonForm::beSigned(Bureaucrat a){
	try{
		if (this->getGradeSign() < 1){
			throw GradeTooHighException();
		}
		else if (this->getGradeSign() > 150){
			throw GradeTooLowException();
		}
	}
	catch (GradeTooHighException e){
		std::cout << "Wrong grade: PresidentialPardonForm " << this->getName() << " sign required " << e.what() << std::endl;
		return;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: PresidentialPardonForm " << this->getName() << " sign required " <<e.what() << std::endl;
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

const char*			PresidentialPardonForm::GradeTooHighException::what() const throw(){
	return ("grade is too high");
}

const char*			PresidentialPardonForm::GradeTooLowException::what() const throw(){
	return ("grade is too low");
}

std::ostream &		operator<<(std::ostream & o, PresidentialPardonForm const & i){
	o << i.getName() << ", PresidentialPardonForm need grade " << i.getGradeSign() << " to sign and grade " << i.getGradeExec() << " to execute, actual status: ";
	if (i.getSigned())
		o << "signed";
	else
		o << "yet to be signed";
	return (o);
}
