#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	RobotomyRequestForm : public Form{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string name, int gradesign, int gradeexec);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm(RobotomyRequestForm const & rhs);
		RobotomyRequestForm &	operator=(RobotomyRequestForm const & cpy);

		std::string const	getName() const;
		int					getGradeSign() const;
		int					getGradeExec() const;

		bool				getSigned() const = 0;
		void				beSigned(Bureaucrat a);
		
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

	private:

		std::string const	_name;
		int const			_gradesign;
		int const			_gradeexec;
		bool				_signed;

};

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const & i);

#endif