#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class	ShrubberyCreationForm : public AForm{

	public:

		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm& src);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm& rhs);
		~ShrubberyCreationForm();

		std::string		getTarget();

		void			execute(Bureaucrat const & executor);
	
	private:

		std::string		_target;
};

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const & i);

#endif