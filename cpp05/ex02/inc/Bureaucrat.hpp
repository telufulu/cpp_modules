/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 00:10:57 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/09 00:10:58 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>	// cout

class	AForm;

class	Bureaucrat
{
	public:
		// Constructors
		Bureaucrat( const std::string name, const int grade );
		Bureaucrat( const Bureaucrat &cpy );

		// Arithmetic operators
		Bureaucrat &operator=( const Bureaucrat &rhs );

		// Member functions
		std::string	getName( void ) const;
		int			getGrade( void ) const;
		void		incrementGrade( void );
		void		decrementGrade( void );
		void		signForm( AForm &obj );

		// Destructor
		~Bureaucrat( void );

		// Exception classes
		class	GradeTooLowException:	public std::exception
		{
			public:
				const char	*what() const throw();
		};
		class	GradeTooHighException:	public std::exception
		{
			public:
				const char	*what() const throw();
		};
	
	private:
		Bureaucrat( void );
		int					_grade;
		const std::string	_name;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);
#endif
