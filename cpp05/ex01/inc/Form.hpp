/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:38:34 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/13 17:57:59 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>		// cout

class Bureaucrat;

class Form
{
	public:
		// Constructors
		Form( const std::string _name, const int gradeToSign,
				const int gradeToExec);
		Form( const Form &cpy );

		// Arithmetic operators
		Form &operator=( const Form &rhs );

		// Member functions
		std::string	getName( void ) const;
		bool		isSigned( void ) const;
		int			getSignPerm( void ) const;
		int			getExecPerm( void ) const;
		void		beSigned( Bureaucrat &obj );
		
		// Exceptions classes
		class	GradeTooLowException :	public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		// Destructor
		~Form( void );

	private:
		Form( void );
		
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
};

std::ostream &operator<<(std::ostream &out, const Form &obj);
#endif
