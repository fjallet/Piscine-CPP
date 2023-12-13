#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	ShrubberyCreationForm : public AForm{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name, int gradesign, int gradeexec);
		virtual ~ShrubberyCreationForm();

		ShrubberyCreationForm(ShrubberyCreationForm const & rhs);
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & cpy);

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

std::ostream &	operator<<(std::ostream & o, Form const & i);

#endif