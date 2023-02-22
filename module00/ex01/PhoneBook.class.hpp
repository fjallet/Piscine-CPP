#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

class PhoneBook{
	
public:

	PhoneBook(void);
	~PhoneBook(void);

	void	add(void);
	void	search(void) const;

private:
	Contact	_list[8];
	int		_numc;

	std::string	_justasking(std::string qst);
	void	_displaylist(void) const;
	void	_subdisplay(std::string str) const;
	void	_displaycontact(int i) const;
};

#endif