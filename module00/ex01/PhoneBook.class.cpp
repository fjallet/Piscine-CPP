#include "ex01.hpp"

PhoneBook::PhoneBook(void){
	this->_numc = 0;
	std::cout << "Constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Destructor called" << std::endl;
}

std::string	PhoneBook::_justasking(std::string qst){
	std::string	str;

	do{
		std::cout << "what is your " << qst << std::endl;
		std::cin >> str;
		if (str.empty())
			std::cout << "empty sentence please answer at least something" << std::endl;
	} while (str.empty());
	return(str);
}

void	PhoneBook::add(void){
	Contact	c;

	c.lastname = _justasking("last name");
	c.firstname = _justasking("fist name");
	c.surname = _justasking("surname");
	c.phonenum = _justasking("phone number");
	c.heavysecret = _justasking("heavy secret");
	for (int i = 0; i < 8; i++)
	{
		if (this->_list[i].lastname.empty())
		{
			this->_list[i] = c;
			this->_numc += 1;
			return;
		}
	}
	for (int i = 0; i < 7; i++)
	{
		this->_list[i] = this->_list[i + 1];
	}
	this->_list[7] = c;
	this->_numc += 1;
}

void	PhoneBook::_subdisplay(std::string str) const {
	if (str.size() > 10)
	{
		std::cout << str.substr(0,9) << ".";
	}
	else
	{
		str.resize(10,' ');
		std::cout << str;
	}
}

void	PhoneBook::_displaylist(void) const {
	std::cout << "  index   |last name |first name| surname" << std::endl;
	for(int i = 0; i < 8 && !this->_list[i].lastname.empty() ; i++)
	{
		std::cout << "    " << i + 1 << "     |";
		_subdisplay(this->_list[i].lastname);
		std::cout << "|";
		_subdisplay(this->_list[i].firstname);
		std::cout << "|";
		_subdisplay(this->_list[i].surname);
		std::cout << std::endl;
	}
}

void	PhoneBook::_displaycontact(int i) const {
	std::cout << "last name : " << this->_list[i].lastname << std::endl;
	std::cout << "fist name : " << this->_list[i].firstname << std::endl;
	std::cout << "surname : " << this->_list[i].surname << std::endl;
	std::cout << "phone number :" << this->_list[i].phonenum << std::endl;
	std::cout << "heavy secret : " << this->_list[i].heavysecret << std::endl;
}

void	PhoneBook::search(void) const {
	int			i = 0;
	std::string	str;

	if (this->_numc == 0)
	{
		std::cout << "Pease add at least one contact before searching again !!" << std::endl;
		return;
	}
	_displaylist();
	do{
		std::cout << "wich contact would you want to check ?" << std::endl;
		while(std::cin >> str)
		{
			try {
				i = std::stoi(str);
				break;
			} catch (...) {
				std::cout << "It is not an integer" << std::endl;
			}
		}
		if ((i < 1 || i > 8) || this->_list[i - 1].lastname.empty())
			std::cout << "There is no contact with this index !!" << std::endl;
	}while (i < 1 || i > 8 || this->_list[i - 1].lastname.empty());
	_displaycontact(i - 1);
}