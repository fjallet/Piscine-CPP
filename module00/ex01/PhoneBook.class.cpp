#include "ex01.hpp"

PhoneBook::PhoneBook(void){
	for (int i = 0; i < 8; i++)
		this->_list[i] = NULL;
	this->_list
	std::cout << "Constructor called" << std::endl;
}

PhoneBook::~PhoneBook(void){
	std::cout << "Destructor called" << std::endl;
}

void	PhoneBook::ADD(void){
	Contact	c;

	std::cout << "what is your last name" << std::endl;
	std::cin >> c.lastname;
	std::cout << "what is your first name" << std::endl;
	std::cin >> c.firstname;
	std::cout << "what is your surname" << std::endl;
	std::cin >> c.surname;
	std::cout << "what is your phone number" << std::endl;
	std::cin >> c.phonenum;
	std::cout << "what is your heavy secret" << std::endl;
	std::cin >> c.heavysecret;
	for (int i = 0; i < 8; i++)
	{
		if (this->_list[i] == NULL)
		{
			this->_list[i].lastname = c;
			return;
		}
	}
	for (int i = 0; i < 7; i++)
	{
		this->_list[i] = this->_list[i + 1];
	}
	this->_list[7] = c;
}