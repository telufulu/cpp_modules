#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>				// ostream

class RPN
{
	public:
		// Constructors
		RPN( void );
		RPN( const RPN &cpy );

		// Arithmetic operators
		RPN &operator=( const RPN &rhs );

		// Destructor
		~RPN( void );
	private:
		int	_data;
};

std::ostream &operator<<(std::ostream &out, const RPN &obj);
#endif
