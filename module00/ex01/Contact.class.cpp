#include "ex01.hpp"

Contact::Contact(void){
	std::cout << "Constructor called" << std::endl;
}

Contact::~Contact(void){
	std::cout << "Destructor called" << std::endl;
}

std::string	Contact::GetLastName(void) const{
	return (this->_lastname);
}

std::string	Contact::GetFirstName(void) const{
	return (this->_firstname);
}

std::string	Contact::GetSurname(void) const{
	return (this->_surname);
}

std::string	Contact::GetPhoneNum(void) const{
	return (this->_phonenum);
}

std::string	Contact::GetHeavySecret(void) const{
	return (this->_heavysecret);
}

void		Contact::SetLastName(std::string str){
	this->_lastname = str;
}

void		Contact::SetFirstName(std::string str){
	this->_firstname = str;
}

void		Contact::SetSurname(std::string str){
	this->_surname = str;
}

void		Contact::SetPhoneNum(std::string str){
	this->_phonenum = str;
}

void		Contact::SetHeavySecret(std::string str){
	this->_heavysecret = str;
}
