#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form{

	public:

		Form();
		Form(std::string name, int gradesign, int gradeexec);
		virtual ~Form();

		Form(Form const & rhs);
		Form &	operator=(Form const & cpy);

		std::string const	getName() const;
		int					getGradeSign() const;
		int					getGradeExec() const;
		bool				getSigned() const;

		void				beSigned(Bureaucrat a);
		void				formExecute(Bureaucrat const & executor);
		virtual void		execute(Bureaucrat const & executor) = 0;
		
		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

	private:

		std::string const	_name;
		int const			_gradesign;
		int const			_gradeexec;
		bool				_signed;

};

std::ostream &	operator<<(std::ostream & o, Form const & i);

#endif