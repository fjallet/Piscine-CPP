#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class	PresidentialPardonForm : public Form{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string name, int gradesign, int gradeexec);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm(PresidentialPardonForm const & rhs);
		PresidentialPardonForm &	operator=(PresidentialPardonForm const & cpy);

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

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const & i);

#endif