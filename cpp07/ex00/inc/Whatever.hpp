#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>				// ostream

class Whatever
{
	public:
		// Constructors
		Whatever( void );
		Whatever( const Whatever &cpy );

		// Arithmetic operators
		Whatever &operator=( const Whatever &rhs );

		// Destructor
		~Whatever( void );
	private:
		int	_data;
};

std::ostream &operator<<(std::ostream &out, const Whatever &obj);
#endif
