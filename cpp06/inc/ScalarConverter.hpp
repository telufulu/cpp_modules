/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:24:00 by telufulu          #+#    #+#             */
/*   Updated: 2026/01/13 21:42:07 by telufulu         ###   ########.fr       */
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
		static void	_parseChar(long literal);
		static void	_parseInt(long literal);
};

std::ostream &operator<<(std::ostream &out, const ScalarConverter &obj);
#endif
