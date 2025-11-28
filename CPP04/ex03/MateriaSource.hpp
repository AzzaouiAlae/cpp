#pragma once
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
	int idx;
	AMateria *slot[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource& obj);
	MateriaSource& operator=(const MateriaSource& obj);
	void learnMateria(AMateria* m);
	AMateria* createMateria(string const & type);
};