#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		slot[i] = NULL;
	idx = 0;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (slot[i])
			delete slot[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (obj.slot[i])
			slot[i] = obj.slot[i]->clone();
		else
			slot[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (slot[i])
			delete slot[i];
		if (obj.slot[i])
			slot[i] = obj.slot[i]->clone();
		else
			slot[i] = NULL;
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (idx > 3)
		return;
	slot[idx] = m; 
	idx++;
}

AMateria* MateriaSource::createMateria(string const & type)
{
	for(int i = 0; i < idx; i++)
	{
		if (slot[i] && type == slot[i]->getType())
			return slot[i]->clone();
	}
	return 0;
}
