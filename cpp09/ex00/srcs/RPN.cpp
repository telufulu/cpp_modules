/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:01:21 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/05 18:58:02 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// cout
#include "RPN.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS				*/
/* ****************************************************************************	*/

RPN::RPN ( void )
{
	//std::cout << "\033[90mVoid RPN constructor called\033[0m" << std::endl;
	return ;
}

RPN::RPN( const std::string &argv )
{
	//std::cout << "\033[90mDefault RPN constructor called\033[0m" << std::endl;
	size_t	len = argv.size();
	
	for( size_t i = 0; i < len; ++i)
	{
		if (_stack.size() == 10)
			throw ;
		else if (argv[i] == ' ')
			continue ;
		_stack.push(argv[i]);
	}
	return ;
}

RPN::RPN ( const RPN &cpy)
{
	//std::cout << "\033[90mCopy RPN constructor called\033[0m" << std::endl;
	if (this == &cpy)
		return ;
	this->_stack = cpy.getStack();
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS				*/
/* ****************************************************************************	*/

RPN	&RPN::operator=( const RPN  &rhs )
{
	//std::cout << "\033[90mCopy RPN operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	this->_stack = rhs.getStack();
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR				*/
/* ****************************************************************************	*/

RPN::~RPN ( void )
{
	//std::cout << "\033[90mRPN destructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*									GETERS				*/
/* ****************************************************************************	*/
const std::stack<char>	&RPN::getStack( void ) const
{
	return _stack;
}

std::string	RPN::getStringStack( void ) const
{
	RPN	stack(*this);
	std::string	res;

	while (!stack.empty())
	{
		if (!res.empty())
			res = " " + res;
		res = stack.top() + res;
		stack.pop();
	}
	return res;
}

char	RPN::top( void )
{
	return _stack.top();
}

void	RPN::pop( void )
{
	_stack.pop();
	return ;
}

bool	RPN::empty( void ) const
{
	return _stack.empty();
}
/* ****************************************************************************	*/
/*									SETERS				*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*								MEMBER FUNCTIONS			*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS				*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const RPN &obj)
{
	std::string	res = obj.getStringStack();

	out << res;
	return out;
}
