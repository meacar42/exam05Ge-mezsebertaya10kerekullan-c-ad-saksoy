#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
	this->name = name;
	this->title =title;
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock()
{
}

Warlock & Warlock::operator=(Warlock const & rhs)
{
	this->name = rhs.name;
	this->title = rhs.title;
	return *this;
}

Warlock::Warlock(Warlock const & obj)
{
	*this = obj;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
}

std::string const & Warlock::getName() const
{
	return this->name;
}

std::string const & Warlock::getTitle() const
{
	return this->title;
}

void	Warlock::setTitle(std::string const & title)
{
	this->title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	if (spell)
		if (spelbok.find(spell->getName()) == spelbok.end())
			spelbok[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string name)
{
	std::map<std::string, ASpell*>::iterator it = spelbok.find(name);

	if(it != spelbok.end())
	{
		delete it->second;
		spelbok.erase(name);
	}
}

void Warlock::launchSpell(std::string name, ATarget const & obj)
{
	if (spelbok.find(name) != spelbok.end())
		spelbok[name]->launch(obj);
}