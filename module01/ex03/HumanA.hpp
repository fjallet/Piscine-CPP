#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA{
	
public:

	HumanA(std::string name, Weapon type);
	~HumanA(void);

	void	attack();
	void	setWeapon(Weapon type);

private:
	std::string	name;
	Weapon		*type;
};

#endif