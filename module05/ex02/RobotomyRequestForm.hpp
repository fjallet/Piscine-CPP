#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class	RobotomyRequestForm : public AForm{

	public:

		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm& src);
		RobotomyRequestForm& operator=(RobotomyRequestForm& rhs);
		~RobotomyRequestForm();

		std::string		getTarget();

		void			execute(Bureaucrat const & executor);
	
	private:

		std::string		_target;
};

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const & i);

#endif