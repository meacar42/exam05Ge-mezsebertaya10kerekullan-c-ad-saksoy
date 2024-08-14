#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const & src)
{
	*this = src;
}

TargetGenerator & TargetGenerator::operator=(TargetGenerator const & src)
{
	target = src.target;
	return (*this);
}


TargetGenerator::TargetGenerator()
{
	
}

TargetGenerator::~TargetGenerator()
{

}

void TargetGenerator::learnTargetType(ATarget* tar)
{
	if (tar)
	{
		target[tar->getType()] = tar;
	}
}

void TargetGenerator::forgetTargetType(std::string const & name)
{
	if (target.find(name) != target.end())
			target.erase(target.find(name));
}

ATarget* TargetGenerator::createTarget(std::string const &name)
{
	ATarget* tmp = NULL;
	if (target.find(name) != target.end())
		tmp = target[name];
	return (tmp);
}