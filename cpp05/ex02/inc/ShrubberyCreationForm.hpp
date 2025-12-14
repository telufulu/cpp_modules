/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:57:17 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/13 22:57:20 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>	// cout
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm :	public AForm
{
	public:
		// Constructors
		ShrubberyCreationForm( const std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &cpy );

		// Arithmetic operators
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &rhs );

		// Member functions
		void	formExecution( Bureaucrat const &executor) const;

		// Destructor
		~ShrubberyCreationForm( void );
	private:
		ShrubberyCreationForm( void );
		const std::string	_target;
};

#endif
