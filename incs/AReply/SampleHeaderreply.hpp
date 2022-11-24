#ifndef NAME_HPP
# define NAME_HPP

# include <iostream>

class Name {
	private:

	public:
		Name();
		Name(Name const &);
		Name & operator=(Name const &);
		~Name();

};

#endif