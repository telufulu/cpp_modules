/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:57:17 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/13 22:57:20 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>	// cout
# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm :	public AForm
{
	public:
		// Constructors
		RobotomyRequestForm( const std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &cpy );

		// Arithmetic operators
		RobotomyRequestForm &operator=( const RobotomyRequestForm &rhs );

		// Member functions
		void	formExecution( Bureaucrat const &executor) const;

		// Exception class
		class	RobotomyException :	public std::exception
		{
			public:
				const char	*what() const throw();
		};

		// Destructor
		~RobotomyRequestForm( void );
	private:
		RobotomyRequestForm( void );
		const std::string	_target;
		int					_num_rand;
};

#endif
