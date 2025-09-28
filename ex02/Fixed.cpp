/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:46:29 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/27 18:57:42 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*									CONSTRUCTORS							* */
/* ************************************************************************** */
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

Fixed::Fixed ( const int &c )
{
	std::cout << "Int constructor called"<< std::endl;
	this->_fixedPoint = c << this->_fracBits;
	return ;
}

Fixed::Fixed ( const float &c )
{
	std::cout << "Float constructor called"<< std::endl;
	this->_fixedPoint = static_cast<int>(roundf(c * (1 << this->_fracBits)));;
	return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
Fixed	&Fixed::operator=( const Fixed &rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_fixedPoint = rhs.getRawBits();
	return *this;
}

Fixed	&Fixed::operator+( const Fixed &rhs )
/* ************************************************************************** */
/*									DESTRUCTOR								* */
/* ************************************************************************** */
Fixed::~Fixed ( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/*								MEMBER FUNCTIONS							* */
/* ************************************************************************** */
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

int		Fixed::toInt( void ) const 
{
	return (this->_fixedPoint >> this->_fracBits);
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->_fixedPoint) / (1 << this->_fracBits));
}

/* ************************************************************************** */
/*								NON MEMBER FUNCTIONS						* */
/* ************************************************************************** */
std::ostream	&operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}
