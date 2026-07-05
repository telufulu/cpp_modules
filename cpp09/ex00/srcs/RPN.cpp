/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:01:21 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/05 23:44:00 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// cout
#include "RPN.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/

RPN::RPN ( void )
{
	//std::cout << "\033[90mVoid RPN constructor called\033[0m" << std::endl;
	return ;
}

RPN::RPN( const std::string &argv )
{
	//std::cout << "\033[90mDefault RPN constructor called\033[0m" << std::endl;
	for( size_t i = argv.size() - 1; i + 1; --i)
	{
		if (_stack.size() == 19)
			throw "Error: ";
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
/*								OPERATORS										*/
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
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

RPN::~RPN ( void )
{
	//std::cout << "\033[90mRPN destructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*									GETERS										*/
/* ****************************************************************************	*/
const std::stack<int>	&RPN::getStack( void ) const
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
			res += " ";
		res += stack.top();
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
/*									SETERS										*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*								MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
int	RPN::solve( void )
{
	std::stack<int>	values;
	char			token;
	int				a;
	int				b;

	while (!_stack.empty())
	{
		token = _stack.top();
		_stack.pop();

		if (token >= '0' && token <= '9')
			values.push(token - '0');
		else
		{
			if (values.size() < 2)
				throw "Error";

			b = values.top();
			values.pop();

			a = values.top();
			values.pop();

			switch (token)
			{
				case '-':
					values.push(a - b);
					break ;
				case '+':
					values.push(a + b);
					break ;
				case '*':
					values.push(a * b);
					break ;
				case '/':
					if (b == 0)
						throw "Error";
					values.push(a / b);
					break ;
				default:
					throw "Error";
			}
		}
	}
	if (values.size() != 1)
		throw "Error";
	return (values.top());
}

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const RPN &obj)
{
	std::string	res = obj.getStringStack();

	out << res;
	return out;
}
