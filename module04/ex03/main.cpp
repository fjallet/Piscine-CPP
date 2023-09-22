#include <iostream>
#include "Character.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(4, *bob);
	me->use(-4, *bob);
	me->unequip(1);
	me->use(1, *bob);
	src->learnMateria(tmp);
	Character* denis = new Character("denis");
	denis->equip(src->createMateria("cure"));
	Character* denis2 = new Character(*denis);
	delete denis;
	denis2->use(0, *me);
	delete denis2;
	delete tmp;
	delete bob;
	delete me;
	delete src;
	return 0;
}