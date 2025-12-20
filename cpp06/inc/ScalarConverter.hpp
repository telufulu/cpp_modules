/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:24:00 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/19 11:24:01 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>	// cout

class ScalarConverter
{
	public:
		// Constructors
		ScalarConverter( const ScalarConverter &cpy );

		// Arithmetic operators
		ScalarConverter &operator=( const ScalarConverter &rhs );

		// Static methods
		static void	convert (const char *literal);

		// Destructor
		~ScalarConverter( void );

	private:
		_ScalarConverter( void );
};

std::ostream &operator<<(std::ostream &out, const ScalarConverter &obj);
#endif
