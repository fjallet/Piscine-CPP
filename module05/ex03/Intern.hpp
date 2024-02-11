#ifndef INTERN_HPP_
# define INTERN_HPP_

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern {
	public:
	
		Intern();
		Intern(Intern const & other);
		Intern& operator=(const Intern& other);

		~Intern();

		AForm* makeForm(std::string name, std::string target);
		AForm*	makeShrubbery(std::string target) const;
		AForm*	makeRobotomy(std::string target) const;
		AForm*	makePresidential(std::string target) const;

	private:
		std::string	_formnames[3];
		AForm *	(Intern::*_formptr[3])(std::string target) const;

};

#endif