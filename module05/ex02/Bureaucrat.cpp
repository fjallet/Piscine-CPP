#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150){
	//std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name){
	try{
		if (grade < 1){
			this->_grade = 1;
			throw GradeTooHighException();
		}
		else if (grade > 150){
			this->_grade = 150;
			throw GradeTooLowException();
		}
		else
			this->_grade = grade;
	}
	catch (GradeTooHighException e){
		std::cout << "Bureaucrat " << name << " " << e.what() << std::endl;
	}
	catch (GradeTooLowException e){
		std::cout << "Bureaucrat " << name << " " <<e.what() << std::endl;
	}
	//std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & rhs) : _name(rhs.getName()){
	*this = rhs;
	//std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& copy){
	if (this != &copy)
	{
		this->_grade = copy.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){
	//std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string const	Bureaucrat::getName() const{
	return (this->_name);
}

int					Bureaucrat::getGrade() const{
	return (this->_grade);
}

void				Bureaucrat::setGrade(int grade){
	this->_grade = grade;
}

void				Bureaucrat::upgrade(){
	try{
		if (this->_grade == 1)
			throw GradeTooHighException();
		else
			this->_grade--;
	}
	catch (GradeTooHighException e){
		std::cout << "Bureaucrat " << this->getName() << " " << e.what() << ": cannot upgrade" << std::endl;
	}
}

void				Bureaucrat::downgrade(){
	try{
		if (this->_grade == 150)
			throw GradeTooLowException();
		else
			this->_grade++;
	}
	catch (GradeTooLowException e){
		std::cout << "Bureaucrat " << this->getName() << " " << e.what() << ": cannot downgrade" << std::endl;
	}
}

void				Bureaucrat::signForm(Form a){
	if (a.getSigned())
		std::cout << this->_name << " signed " << a.getName() << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << a.getName() << " because he need at least grade " << a.getGradeSign() << " to sign" << std::endl;
}

const char*			Bureaucrat::GradeTooHighException::what() const throw(){
	return ("grade is too high");
}

const char*			Bureaucrat::GradeTooLowException::what() const throw(){
	return ("grade is too low");
}

std::ostream &		operator<<(std::ostream & o, Bureaucrat const & i){
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return (o);
}