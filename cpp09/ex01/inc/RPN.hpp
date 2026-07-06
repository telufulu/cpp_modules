/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:01:32 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/05 19:13:13 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>		// ostream
# include <stack>			// stack
# include <string>			// string

class RPN
{
	public:
		// Constructors
		RPN( const std::string &argv );
		RPN( const RPN &cpy );

		// Arithmetic operators
		RPN &operator=( const RPN &rhs );

		// Destructor
		~RPN( void );

		// Geters and seters
		const std::stack<int>	&getStack( void ) const;
		std::string				getStringStack( void ) const;
		char					top( void );
		void					pop( void );
		bool					empty( void ) const;

		// Member functions
		int	solve( void );
	private:
		// Constructors
		RPN( void );
		
		std::stack<int>	_stack;
};

std::ostream &operator<<(std::ostream &out, const RPN &obj);
#endif
