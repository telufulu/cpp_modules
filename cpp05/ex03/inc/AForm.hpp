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

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>		// cout

class Bureaucrat;

class AForm
{
	public:
		// Constructors
		AForm( const std::string _name, const int gradeToSign,
				const int gradeToExec);
		AForm( const AForm &cpy );

		// Arithmetic operators
		AForm &operator=( const AForm &rhs );

		// Member functions
		std::string		getName( void ) const;
		bool			isSigned( void ) const;
		int				getSignPerm( void ) const;
		int				getExecPerm( void ) const;
		void			beSigned( Bureaucrat &obj );
		void			execute( Bureaucrat const &executor) const;
		virtual	void	formExecution( Bureaucrat const &executor ) const = 0;
	
		// Exceptions classes
		class	GradeTooLowException :	public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class	NotSignedException :	public std::exception
		{
			public:
				const char	*what() const throw();
		};
		
		// Destructor
		virtual	~AForm( void );

	private:
		AForm( void );
		
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);
#endif
