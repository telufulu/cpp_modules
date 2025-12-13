#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>	// cout
# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm :	public AForm
{
	public:
		// Constructors
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm &cpy );

		// Arithmetic operators
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &rhs );

		// Member functions
		void	execute( Bureaucrat const &executor) const;

		// Destructor
		~ShrubberyCreationForm( void );
	private:
		const std::string	_target;
};

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &obj);
#endif
