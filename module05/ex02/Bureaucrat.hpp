#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Form;

class	Bureaucrat{

	public:

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		virtual ~Bureaucrat();

		Bureaucrat(Bureaucrat const & rhs);
		Bureaucrat &	operator=(Bureaucrat const & cpy);

		std::string const	getName() const;
		int					getGrade() const;
		void				setGrade(int grade);

		void				signForm(Form a);
		void				upgrade();
		void				downgrade();
		
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
		int					_grade;

};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & i);

#endif