#include "PmergeMe.hpp"

int	main( int argc, char **argv )
{
	try
	{
		PmergeMe	p;

		p.solveVector(argc, argv);
		p.solveDeque(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << "\033[0mError:\033[0m " << e.what() << std::endl;
		return (1);
	}
	return (0);
}