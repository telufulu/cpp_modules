/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 16:45:29 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/14 16:45:31 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>	// cout

class AForm;

class Intern
{
	public:
		// Constructors
		Intern( void );
		Intern( const Intern &cpy );

		// Arithmetic operators
		Intern &operator=( const Intern &rhs );

		// Member function
		AForm	*makeForm(const std::string form, const std::string target);

		// Exceptions classes
		class	IDontKnowException :	public std::exception
		{
			public:
				const char	*what() const throw();
		};

		// Destructor
		~Intern( void );
};

std::ostream &operator<<(std::ostream &out, const Intern &obj);
#endif
