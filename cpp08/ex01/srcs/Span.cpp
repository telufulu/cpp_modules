/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 21:36:45 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/26 21:36:46 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// cout
#include <stdexcept>	// length_error
#include <limits>		// max
#include <algorithm>	// sort
#include "Span.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/

Span::Span ( void ) : _size(0), _span(0)
{
	//std::cout << "\033[90mVoid Span constructor called\033[0m" << std::endl;
	return ;
}

Span::Span ( unsigned int size ) : _size(size), _span(0)
{
	//std::cout << "\033[90mDefault Span constructor called\033[0m" << std::endl;
	return ;
}

Span::Span ( const Span &cpy)
{
	//std::cout << "\033[90mCopy Span constructor called\033[0m" << std::endl;
	this->_size = cpy._size;
	this->_span = cpy._span;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/

Span	&Span::operator=( const Span  &rhs )
{
	//std::cout << "\033[90mCopy Span operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	this->_size = rhs._size;
	this->_span = rhs._span;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

Span::~Span ( void )
{
	//std::cout << "\033[90mSpan destructor called\033[0m" << std::endl;
	return ;
}
/* ****************************************************************************	*/
/*								GETERS											*/
/* ****************************************************************************	*/
unsigned int	Span::getNum( unsigned int pos ) const
{
	return _span[pos];
}

unsigned int	Span::getSize( void ) const
{
	return _span.size();
}

/* ****************************************************************************	*/
/*								MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
void	Span::addNumber( unsigned int num )
{
	if (_span.size() == _size)
		throw std::length_error("container is full");
	_span.push_back(num);
}

unsigned int	Span::shortestSpan( void ) const
{
	unsigned int	size = _span.size();
	std::vector<unsigned int>	sorted(_span);
	unsigned int	res = std::numeric_limits<unsigned int>::max();

	if (size <= 1)
		throw std::length_error("not enough numbers in Span");

	std::sort(sorted.begin(), sorted.end());
	for (unsigned int i = 1; i < size; ++i)
	{
		if (i)
		{
			unsigned int	diff = sorted[i] - sorted[i - 1];
			if (diff < res)
				res = diff;
		}
	}
	return res;
}

unsigned int	Span::longestSpan( void ) const
{
	unsigned int	max = 0;
	unsigned int	size = _span.size();
	unsigned int	min = std::numeric_limits<unsigned int>::max();

	if (size <= 1)
		throw std::length_error("not enough numbers in Span");
	for (unsigned int i = 0; i < size; ++i)
	{
		if (min > _span[i])
			min = _span[i];
	}
	for (unsigned int i = 0; i < size; ++i)
	{
		if (max < _span[i])
			max = _span[i];	
	}
	return max - min;
}

void	Span::fillSpan( void )
{
	if (!_size)
		throw std::length_error("container is full");
	for (unsigned int i = 0; i < _size; ++i)
		addNumber(i);
}

void	Span::addRange( void )
{
	unsigned int				x[] = {100, 150, 200, 23, 1234, 1};
	std::vector<unsigned int>	range(x, x + 4);

	_span = range;
}

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const Span &obj)
{
	unsigned int	size = obj.getSize();

	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << obj.getNum(i) << " ";
	}
	return out;
}
