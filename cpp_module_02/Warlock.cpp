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

void	Warlock::setTitle(std::string const & str)
{
	this->title = str;
}

void	Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
	if(spell)
		spelbok.learnSpell(spell);
}

void Warlock::forgetSpell(std::string name)
{
	spelbok.forgetSpell(name);
}

void Warlock::launchSpell(std::string name, ATarget const & obj)
{
	if (spelbok.createSpell(name))
		spelbok.createSpell(name)->launch(obj);
}