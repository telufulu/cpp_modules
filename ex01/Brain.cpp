/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 10:17:12 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 19:07:12 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ************************************************************************** */
/*									CONSTRUCTORS							* */
/* ************************************************************************** */
Brain::Brain	( void )
{
    int i = -1;

    while (++i < 100)
        this->_ideas[i] = "";
    std::cout << "\033[90mBrain default constructor called\033[0m" << std::endl;
	return ;
}

Brain::Brain	( const Brain &cpy )
{
    int i = -1;

	std::cout << "\033[90mBrain copy constructor called\033[0m" << std::endl;
	if (this == &cpy)
        return ;
    while (++i < 100)
        this->_ideas[i] = cpy._ideas[i];
    return ;
}

/* ************************************************************************** */
/*									OPERATORS								* */
/* ************************************************************************** */
Brain	&Brain::operator=( const Brain &rhs )
{
    int i = 0;

	if (this == &rhs)
		return *this;
    while (i < 100)
    {
        this->_ideas[i] = rhs._ideas[i];
        ++i;
    }
    return *this;
}

/* ************************************************************************** */
/*									DESTRUCTOR								* */
/* ************************************************************************** */
Brain::~Brain	( void )
{
	std::cout << "\033[90mBrain destructor called\033[0m" << std::endl;
	return ;
}

/* ************************************************************************** */
/*								MEMBER FUNCTIONS    						* */
/* ************************************************************************** */
void	Brain::setIdea( std::string idea )
{
	int		i = 0;

	if (idea.empty())
		return ;
	while (!this->_ideas[i].empty())
	{
        ++i;
        if (i >= 100)
            return ;
    }
    this->_ideas[i] = idea;
	return ;

}

const std::string   &Brain::getIdea( int i ) const
{
    if (i < 100 && !this->_ideas[i].empty())
        return this->_ideas[i];
    return this->_ideas[99];
}
