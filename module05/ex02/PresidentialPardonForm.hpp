#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class	PresidentialPardonForm : public AForm{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		void			beSigned(Bureaucrat a);
		void			execute(Bureaucrat const & executor);
	
	private:

		std::string		_target
};

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const & i);

#endif