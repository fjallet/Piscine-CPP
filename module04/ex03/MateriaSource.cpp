#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void){
	for(int i = 0; i < 4; i++){
		this->_inv[i] = NULL;
	}
	//std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & cpy){
	*this = cpy;
	//std::cout << "MateriaSource copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource(){
	for(int i = 0; i < 4; i++){
		if (this->_inv[i] != NULL)
			delete (this->_inv[i]);
	}
	//std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & rhs){
	for(int i = 0; i < 4; i++){
		if (rhs._inv[i] == NULL)
			this->_inv[i] = NULL;
		else
			this->_inv[i] = rhs._inv[i]->clone();
	}
	return (*this);
}

void		MateriaSource::learnMateria(AMateria* m){
	if (m == NULL)
		return ;
	for(int i = 0; i < 4; i++){
		if (this->_inv[i] == NULL)
		{
			this->_inv[i] = m;
			return ;
		}
	}
}

AMateria*		MateriaSource::createMateria(std::string const & type){
	for(int i = 0; i < 4; i++){
		if (this->_inv[i] && this->_inv[i]->getType() == type)
			return (this->_inv[i]->clone());
	}
	return (NULL);
}
