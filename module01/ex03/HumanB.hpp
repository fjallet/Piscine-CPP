#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB{
	
public:

	HumanB(std::string name1);
	~HumanB(void);

	void	attack();
	void	setWeapon(Weapon& type);

private:
	std::string	name;
	Weapon*		type;
};

#endif