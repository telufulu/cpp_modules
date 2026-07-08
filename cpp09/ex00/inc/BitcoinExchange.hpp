/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 20:38:13 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/08 20:58:14 by telufulu         ###   ########.fr       */
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
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange &cpy );

		// Arithmetic operators
		BitcoinExchange &operator=( const BitcoinExchange &rhs );

		// Destructor
		~BitcoinExchange( void );
	private:
		std::map<std::string, int>	_db;
};

std::ostream &operator<<(std::ostream &out, const BitcoinExchange &obj);
#endif
