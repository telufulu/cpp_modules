/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:57:17 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/13 22:57:20 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>	// cout
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm :	public AForm
{
	public:
		// Constructors
		PresidentialPardonForm( const std::string target );
		PresidentialPardonForm( const PresidentialPardonForm &cpy );

		// Arithmetic operators
		PresidentialPardonForm &operator=( const PresidentialPardonForm &rhs );

		// Member functions
		void	formExecution( Bureaucrat const &executor) const;

		// Destructor
		~PresidentialPardonForm( void );
	private:
		PresidentialPardonForm( void );
		const std::string	_target;
};

#endif
