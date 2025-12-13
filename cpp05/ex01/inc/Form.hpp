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

# include <iostream>	// cout

class Form
{
	public:
		// Constructors
		Form( const std::string, const int gradeToSign,
				const int gradeToExec) const;
		Form( const Form &cpy );

		// Arithmetic operators
		Form &operator=( const Form &rhs );

		// Destructor
		~Form( void );

	private:
		Form( void );
		
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
};

#endif
