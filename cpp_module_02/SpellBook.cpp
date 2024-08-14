#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const & src)
{
	*this = src;
}

SpellBook & SpellBook::operator=(SpellBook const & src)
{
	this->spelbok= src.spelbok;
	return (*this);
}

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{

}

void SpellBook::learnSpell(ASpell* spell)
{
	if (spell)
	{
		spelbok[spell->getName()] = spell->clone();
	}
}

void SpellBook::forgetSpell(std::string const & name)
{
	std::map<std::string, ASpell*>::iterator it = spelbok.find(name);
	if (it != spelbok.end())
	{
		delete it->second;
		spelbok.erase(it);
	}
}

ASpell* SpellBook::createSpell(std::string const &name)
{
	ASpell* tmp = NULL;
	if (spelbok.find(name) != spelbok.end())
		tmp = spelbok[name];
	return (tmp);
}