/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:46:29 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/27 16:53:54 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed ( void ) : _fixedPoint(0)
{
	std::cout << "Default constructor called"<< std::endl;
	return ;
}

Fixed::Fixed ( const Fixed &cpy )
{
	std::cout << "Copy constructor called" << std::endl;
	if (this == &cpy)
		return ;
	this->_fixedPoint = cpy.getRawBits();
	return ;
}

Fixed	&Fixed::operator=( const Fixed &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_fixedPoint = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( const int raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
	return ;
}
