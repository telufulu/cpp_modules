/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:46:29 by telufulu          #+#    #+#             */
/*   Updated: 2025/09/28 20:55:44 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* ************************************************************************** */
/*									CONSTRUCTORS							* */
/* ************************************************************************** */
Fixed::Fixed ( void ) : _fixedPoint(0)
{
	//std::cout << "Default constructor called"<< std::endl;
	return ;
}

Fixed::Fixed ( const Fixed &cpy )
{
	//std::cout << "Copy constructor called" << std::endl;
	if (this == &cpy)
		return ;
	this->_fixedPoint = cpy.getRawBits();
	return ;
}

Fixed::Fixed ( const int &c )
{
	//std::cout << "Int constructor called"<< std::endl;
	this->_fixedPoint = c << this->_fracBits;
	return ;
}

Fixed::Fixed ( const float &c )
{
	//std::cout << "Float constructor called"<< std::endl;
	this->_fixedPoint = static_cast<int>(roundf(c * (1 << this->_fracBits)));;
	return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
// Arithmetic operators
Fixed	&Fixed::operator=( const Fixed &rhs )
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	this->_fixedPoint = rhs.getRawBits();
	return *this;
}

Fixed	Fixed::operator+( const Fixed &rhs )
{
	//std::cout << "Plus operator called" << std::endl;
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-( const Fixed &rhs )
{
	//std::cout << "Minus operator called" << std::endl;
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*( const Fixed &rhs )
{
	//std::cout << "Multi operator called" << std::endl;
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/( const Fixed &rhs )
{
	//std::cout << "Div operator called" << std::endl;
	return Fixed(this->toFloat() / rhs.toFloat());
}

// Comparision operators
bool	Fixed::operator>( const Fixed &rhs )
{
	if (this->_fixedPoint > rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<( const Fixed &rhs )
{
	if (this->_fixedPoint < rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=( const Fixed &rhs )
{
	if (this->_fixedPoint >= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=( const Fixed &rhs )
{
	if (this->_fixedPoint <= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==( const Fixed &rhs )
{
	if (this->_fixedPoint == rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=( const Fixed &rhs )
{
	if (this->_fixedPoint != rhs.getRawBits())
		return true;
	return false;
}

// Increment and decrement operators
Fixed	&Fixed::operator++( void )
{
	++this->_fixedPoint;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed tmp = *this;
	++this->_fixedPoint;
	return tmp;
}

Fixed	&Fixed::operator--( void )
{
	--this->_fixedPoint;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed tmp = *this;
	--this->_fixedPoint;
	return tmp;
}

/* ************************************************************************** */
/*									DESTRUCTOR								* */
/* ************************************************************************** */
Fixed::~Fixed ( void )
{
	//std::cout << "Destructor called" << std::endl;
	return ;
}

/* ************************************************************************** */
/*								MEMBER FUNCTIONS							* */
/* ************************************************************************** */
int		Fixed::getRawBits( void ) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits( const int raw )
{
	//std::cout << "setRawBits member function called" << std::endl;
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

Fixed	&Fixed::min( Fixed &a, Fixed &b )
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

const Fixed	&Fixed::min( const Fixed &a, const Fixed &b )
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	return a;
}

Fixed	&Fixed::max( Fixed &a, Fixed &b )
{
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}

const Fixed	&Fixed::max( const Fixed &a, const Fixed &b )
{
	if (a.getRawBits() < b.getRawBits())
		return b;
	return a;
}

/* ************************************************************************** */
/*								NON MEMBER FUNCTIONS						* */
/* ************************************************************************** */
std::ostream	&operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}
