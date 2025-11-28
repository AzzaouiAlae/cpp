#include "Brain.hpp"


Brain::Brain()
{
	for(int i = 0; i < 100; i++)
		ideas[i] = "";
	cout << "Brain object created\n";
}
Brain::~Brain()
{
	cout << "Brain object destroyde\n";
}
Brain::Brain(const Brain& obj)
{
	for(int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	cout << "Brain object copyed\n";
}
Brain &Brain::operator=(const Brain& obj)
{
	for(int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
	cout << "Brain object use assignment(=) operator\n";
	return *this;
}