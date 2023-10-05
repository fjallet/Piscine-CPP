#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _name("ShrubberyCreationForm"), _gradesign(145), _gradeexec(137){
	this->_signed = false;
	//std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, int gradesign, int gradeexec) : _name(name), _gradesign(gradesign), _gradeexec(gradeexec){
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
		std::cout << "Wrong grade: ShrubberyCreationForm " << name << " sign required " << e.what() << std::endl;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: ShrubberyCreationForm " << name << " sign required " <<e.what() << std::endl;
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
		std::cout << "Wrong grade: ShrubberyCreationForm " << name << " execute required " << e.what() << std::endl;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: ShrubberyCreationForm " << name << " execute required " <<e.what() << std::endl;
	}
	//std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & rhs) : _name(rhs.getName()), _gradesign(rhs.getGradeSign()), _gradeexec(rhs.getGradeExec()){
	*this = rhs;
	//std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm& copy){
	if (this != &copy)
	{
		this->_signed = copy.getSigned();
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	//std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string const	ShrubberyCreationForm::getName() const{
	return (this->_name);
}

int					ShrubberyCreationForm::getGradeSign() const{
	return (this->_gradesign);
}

int					ShrubberyCreationForm::getGradeExec() const{
	return (this->_gradeexec);
}

bool				ShrubberyCreationForm::getSigned() const{
	return (this->_signed);
}

void				ShrubberyCreationForm::beSigned(Bureaucrat a){
	try{
		if (this->getGradeSign() < 1){
			throw GradeTooHighException();
		}
		else if (this->getGradeSign() > 150){
			throw GradeTooLowException();
		}
	}
	catch (GradeTooHighException e){
		std::cout << "Wrong grade: ShrubberyCreationForm " << this->getName() << " sign required " << e.what() << std::endl;
		return;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: ShrubberyCreationForm " << this->getName() << " sign required " <<e.what() << std::endl;
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

const char*			ShrubberyCreationForm::GradeTooHighException::what() const throw(){
	return ("grade is too high");
}

const char*			ShrubberyCreationForm::GradeTooLowException::what() const throw(){
	return ("grade is too low");
}

std::ostream &		operator<<(std::ostream & o, ShrubberyCreationForm const & i){
	o << i.getName() << ", ShrubberyCreationForm need grade " << i.getGradeSign() << " to sign and grade " << i.getGradeExec() << " to execute, actual status: ";
	if (i.getSigned())
		o << "signed";
	else
		o << "yet to be signed";
	return (o);
}