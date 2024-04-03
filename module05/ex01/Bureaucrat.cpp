#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	if (grade < 1){
		throw GradeTooHighException();
	}
	if (grade > 150){
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat( Bureaucrat const & rhs) : _name(rhs.getName()){
	*this = rhs;
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat& copy){
	if (this != &copy)
	{
		this->_grade = copy.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){
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
	if (this->_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void				Bureaucrat::downgrade(){
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

void				Bureaucrat::signForm(Form& a){
	try{
		a.beSigned(* this);
		std::cout << _name << " signed " << a.getName() << std::endl;
	}
	catch (Form::GradeTooLowException& e){
		std::cout << _name << " couldn't sign " << a.getName() << " because" << e.what() << std::endl;
	}
}

const char*			Bureaucrat::GradeTooHighException::what() const throw(){
	return ("grade too high");
}

const char*			Bureaucrat::GradeTooLowException::what() const throw(){
	return ("grade too low");
}

std::ostream &		operator<<(std::ostream & o, Bureaucrat const & i){
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return (o);
}