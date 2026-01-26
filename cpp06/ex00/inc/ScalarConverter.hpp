/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:24:00 by telufulu          #+#    #+#             */
/*   Updated: 2026/01/26 20:29:46 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>	// cout

class ScalarConverter
{
	public:
		// Arithmetic operators
		ScalarConverter &operator=( const ScalarConverter &rhs );

		// Static methods
		// Is static because I need to call it without instanciate the class
		static void	convert (const char *literal);

		// Exception classes
		class	ImpossibleException :	public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class	NonDisplayableException :	public std::exception
		{
			public:
				const char	*what() const throw();
		};
		// Destructor
		~ScalarConverter( void );

	private:
		// Constructors
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter &cpy );

		// Helpers
		static void	_parseChar(const char *literal);
		static void	_parseInt(const char *literal);
		static void _parseFloat(const char *literal);
};

std::ostream &operator<<(std::ostream &out, const ScalarConverter &obj);
#endif
