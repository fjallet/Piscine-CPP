#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

class Contact{
	
public:
	Contact(void);
	~Contact(void);

	std::string	GetLastName(void) const;
	std::string	GetFirstName(void) const;
	std::string	GetSurname(void) const;
	std::string	GetPhoneNum(void) const;
	std::string	GetHeavySecret(void) const;
	void		SetLastName(std::string str);
	void		SetFirstName(std::string str);
	void		SetSurname(std::string str);
	void		SetPhoneNum(std::string str);
	void		SetHeavySecret(std::string str);

private:
	std::string	_lastname;
	std::string	_firstname;
	std::string	_surname;
	std::string	_phonenum;
	std::string	_heavysecret;

};

#endif