#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>	// cout

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange &cpy );

		// Arithmetic operators
		BitcoinExchange &operator=( const BitcoinExchange &rhs );

		// Destructor
		~BitcoinExchange( void );
	private:
		int	_data;
};

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &obj);
#endif
