/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 20:38:13 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/11 15:07:05 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>	// cout
# include <string>
# include <map>

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange( const char *file_path );
		BitcoinExchange( const BitcoinExchange &cpy );

		// Arithmetic operators
		BitcoinExchange &operator=( const BitcoinExchange &rhs );

		// Destructor
		~BitcoinExchange( void );

		// Member functions
		void	processInput( const char *file_path ) const;

	private:
		BitcoinExchange( void );

		// Auxiliar functions
		std::string	_getDate( const std::string &line, size_t sep) const;
		double		_getValue( const std::string &line, size_t sep ) const;
		bool		_isValidDate( const std::string &date ) const;
		bool		_isValidValue( const std::string &valueStr, double &value ) const;
		double		_getRateForDate( const std::string &date ) const;

		std::map<std::string, double>	_db;
};

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &obj);
#endif
