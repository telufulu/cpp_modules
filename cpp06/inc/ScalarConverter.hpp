#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>				// ostream

class ScalarConverter
{
	public:
		// Constructors
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter &cpy );

		// Arithmetic operators
		ScalarConverter &operator=( const ScalarConverter &rhs );

		// Destructor
		~ScalarConverter( void );
	private:
		int	_data;
};

std::ostream &operator<<(std::ostream &out, const ScalarConverter &obj);
#endif
