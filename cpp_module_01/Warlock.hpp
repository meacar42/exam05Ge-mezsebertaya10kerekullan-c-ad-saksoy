#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock {

	private :
		Warlock & operator=(Warlock const & rhs);
		Warlock(Warlock const & obj);
		Warlock();
		std::string name;
		std::string title;
		std::map < std::string, ASpell * > spelbok;

	public :
		Warlock(std::string const &name, std::string const &title);
		~Warlock();
		std::string const & getName() const;
		std::string const & getTitle() const;
		void	setTitle(std::string const & title);
		void	introduce() const;
		void learnSpell(ASpell* spell);
		void forgetSpell(std::string name);
		void launchSpell(std::string name, ATarget const & obj);
};