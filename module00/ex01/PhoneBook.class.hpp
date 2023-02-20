#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

class PhoneBook{
	
public:

	PhoneBook(void);
	~PhoneBook(void);

	void	ADD(void);

private:
	Contact	_list[8];

};

#endif