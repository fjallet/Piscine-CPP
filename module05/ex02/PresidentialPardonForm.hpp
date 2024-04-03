#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class	PresidentialPardonForm : public AForm{

	public:

		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm& src);
		PresidentialPardonForm& operator=(PresidentialPardonForm& rhs);
		~PresidentialPardonForm();

		std::string		getTarget();

		void			execute(Bureaucrat const & executor);
	
	private:

		std::string		_target;
};

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const & i);

#endif