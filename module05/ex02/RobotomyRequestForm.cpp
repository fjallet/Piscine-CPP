#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _name("RobotomyRequestForm"), _gradesign(72), _gradeexec(45){
	this->_signed = false;
	//std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name, int gradesign, int gradeexec) : _name(name), _gradesign(gradesign), _gradeexec(gradeexec){
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
		std::cout << "Wrong grade: RobotomyRequestForm " << name << " sign required " << e.what() << std::endl;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: RobotomyRequestForm " << name << " sign required " <<e.what() << std::endl;
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
		std::cout << "Wrong grade: RobotomyRequestForm " << name << " execute required " << e.what() << std::endl;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: RobotomyRequestForm " << name << " execute required " <<e.what() << std::endl;
	}
	//std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & rhs) : _name(rhs.getName()), _gradesign(rhs.getGradeSign()), _gradeexec(rhs.getGradeExec()){
	*this = rhs;
	//std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm& copy){
	if (this != &copy)
	{
		this->_signed = copy.getSigned();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	//std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string const	RobotomyRequestForm::getName() const{
	return (this->_name);
}

int					RobotomyRequestForm::getGradeSign() const{
	return (this->_gradesign);
}

int					RobotomyRequestForm::getGradeExec() const{
	return (this->_gradeexec);
}

bool				RobotomyRequestForm::getSigned() const{
	return (this->_signed);
}

void				RobotomyRequestForm::beSigned(Bureaucrat a){
	try{
		if (this->getGradeSign() < 1){
			throw GradeTooHighException();
		}
		else if (this->getGradeSign() > 150){
			throw GradeTooLowException();
		}
	}
	catch (GradeTooHighException e){
		std::cout << "Wrong grade: RobotomyRequestForm " << this->getName() << " sign required " << e.what() << std::endl;
		return;
	}
	catch (GradeTooLowException e){
		std::cout << "Wrong grade: RobotomyRequestForm " << this->getName() << " sign required " <<e.what() << std::endl;
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

const char*			RobotomyRequestForm::GradeTooHighException::what() const throw(){
	return ("grade is too high");
}

const char*			RobotomyRequestForm::GradeTooLowException::what() const throw(){
	return ("grade is too low");
}

std::ostream &		operator<<(std::ostream & o, RobotomyRequestForm const & i){
	o << i.getName() << ", RobotomyRequestForm need grade " << i.getGradeSign() << " to sign and grade " << i.getGradeExec() << " to execute, actual status: ";
	if (i.getSigned())
		o << "signed";
	else
		o << "yet to be signed";
	return (o);
}
