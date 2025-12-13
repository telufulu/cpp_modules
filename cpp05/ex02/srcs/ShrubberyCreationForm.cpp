#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/
ShrubberyCreationForm::ShrubberyCreationForm ( void ) :
	AForm("ShrubberyCreation", 145, 137)
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
void	ShrubberyCreationForm::execute( Bureaucrat const &executor ) const
{
	if (executor.getGrade() > this->getExecPerm())
		throw AForm::GradeTooLowException();
	std::cout << "VAS BIEN" << std::endl;
	// Prints a tree of ASCII characters
	(void)executor;
}

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &obj)
{
	(void)obj;
	out << "This is the overload of '<<' for the ShrubberyCreationForm class" << std::endl;
	return out;
}
