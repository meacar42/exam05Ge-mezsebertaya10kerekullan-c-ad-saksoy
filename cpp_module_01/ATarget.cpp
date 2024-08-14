#include "ATarget.hpp"

ATarget::ATarget(std::string type) 
{
	this->type =type;
}

ATarget & ATarget::operator=(ATarget const & rhs)
{
	type = rhs.type;
	return *this;
}

ATarget::ATarget(ATarget const & obj)
{
	*this = obj;
}

ATarget::~ATarget()
{

}

std::string ATarget::getType() const
{
	return this->type;
}

void	ATarget::getHitBySpell(ASpell const & spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}
