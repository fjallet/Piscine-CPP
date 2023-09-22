#ifndef MATERIALSOURCE_HPP
# define MATERIALSOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{

public:

MateriaSource(void);
virtual ~MateriaSource();

MateriaSource(MateriaSource const & rhs);
MateriaSource &	operator=(MateriaSource const & cpy);

void learnMateria(AMateria*);
AMateria* createMateria(std::string const & type);

private:

AMateria* _inv[4];
};

#endif