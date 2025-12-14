/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 22:57:29 by telufulu          #+#    #+#             */
/*   Updated: 2025/12/14 17:59:49 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>						// ofstream

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/
ShrubberyCreationForm::ShrubberyCreationForm ( void ) :
	AForm("ShrubberyCreation", 145, 137)
{
	std::cout << "\033[90mVoid constructor called\033[0m" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const std::string target ) :
	AForm("ShrubberyCreation", 145, 137),
	_target(target)
{
	std::cout << "\033[90mDefault constructor called\033[0m" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm ( const ShrubberyCreationForm &cpy) :
	AForm(cpy.getName(), cpy.getSignPerm(), cpy.getExecPerm())
{
	std::cout << "\033[90mCopy constructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( const ShrubberyCreationForm  &rhs )
{
	std::cout << "\033[90mCopy operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

ShrubberyCreationForm::~ShrubberyCreationForm ( void )
{
	std::cout << "\033[90mDestructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*							MEMBER FUNCTIONS									*/
/* ****************************************************************************	*/
void	ShrubberyCreationForm::formExecution( Bureaucrat const &executor ) const
{
	std::string		fileName = this->_target + "_shrubbery";
	std::ofstream	file(fileName.c_str());

	file << std::endl << "            /*\\" << std::endl
	<< "           /***\\" << std::endl
	<< "          /*o*o*\\" << std::endl
	<< "         /***o***\\" << std::endl
	<< "        /*o*****o*\\" << std::endl
	<< "       /***o**o****\\" << std::endl
	<< "      /*o*********o*\\" << std::endl
	<< "     /***o****o******\\" << std::endl
	<< "    /*o*************o*\\" << std::endl
	<< "   /***o********o******\\" << std::endl
	<< "  /*o******o**********o*\\" << std::endl
	<< " /***o*****o*****o*******\\" << std::endl
	<< "/*o*********************o*\\" << std::endl
	<< "           |||" << std::endl
	<< "           |||" << std::endl
	<< "         __|||__" << std::endl
	<< "        [_______]" << std::endl;
	std::cout << executor.getName() << " schubberies a tree in " << this->_target << std::endl;
}

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
