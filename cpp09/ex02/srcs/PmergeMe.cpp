#include <iostream>		// cout
#include "PmergeMe.hpp"

/* ****************************************************************************	*/
/*								CONSTRUCTORS				*/
/* ****************************************************************************	*/

PmergeMe::PmergeMe ( void )
{
	//std::cout << "\033[90mDefault PmergeMe constructor called\033[0m" << std::endl;
	return ;
}

PmergeMe::PmergeMe ( const PmergeMe &cpy)
{
	//std::cout << "\033[90mCopy PmergeMe constructor called\033[0m" << std::endl;
	if (this == &cpy)
		return ;
	this->_vector = cpy._vector;
	this->_deque = cpy._deque;
	return ;
}

/* ****************************************************************************	*/
/*								OPERATORS				*/
/* ****************************************************************************	*/

PmergeMe	&PmergeMe::operator=( const PmergeMe  &rhs )
{
	//std::cout << "\033[90mCopy PmergeMe operator called\033[0m" << std::endl;
	if (this == &rhs)
		return *this;
	this->_vector = rhs._vector;
	this->_deque = rhs._deque;
	return *this;
}

/* ****************************************************************************	*/
/*								DESTRUCTOR										*/
/* ****************************************************************************	*/

PmergeMe::~PmergeMe ( void )
{
	//std::cout << "\033[90mPmergeMe destructor called\033[0m" << std::endl;
	return ;
}

/* ****************************************************************************	*/
/*									GETERS										*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*									SETERS										*/
/* ****************************************************************************	*/

/* ****************************************************************************	*/
/*								AUX FUNCTIONS									*/
/* ****************************************************************************	*/
static bool	is_number( char *s )
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (false);
	while (s[i])
	{
		if (!std::isdigit(s[i]))
			return (false);
		i++;
	}
	return (true);
}

static int	to_int( char *s )
{
	long	n;
	int		i;

	n = 0;
	i = 0;
	while (s[i])
	{
		n = n * 10 + (s[i] - '0');
		if (n > INT_MAX)
			throw std::runtime_error("Error");
		i++;
	}
	if (n <= 0)
		throw std::runtime_error("Error");
	return (static_cast<int>(n));
}

/* ****************************************************************************	*/
/*								MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
void	PmergeMe::solveVector( int argc, char **argv )
{
	clock_t	start;
	clock_t	end;
	double	vector_time;

	_parseVector(argc, argv);
	_printVector("Before:\t", _vector);
	start = clock();
	_parseVector(argc, argv);
	_vector = _sortVector(_vector);
	end = clock();
	vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	_printVector("After:\t", _vector);
	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector\t: " << vector_time << " us" << std::endl;
}

void	PmergeMe::solveDeque( int argc, char **argv )
{
	clock_t	start;
	clock_t	end;
	double	deque_time;

	start = clock();
	_parseDeque(argc, argv);
	_deque = _sortDeque(_deque);
	end = clock();
	deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque\t: " << deque_time << " us" << std::endl;
}

// Vector
std::vector<int>::iterator	PmergeMe::_binaryVector( std::vector<int> &v, int n, std::vector<int>::iterator end )
{
	std::vector<int>::iterator	first;
	std::vector<int>::iterator	mid;
	int							size;
	int							step;

	first = v.begin();
	while (first != end)
	{
		size = std::distance(first, end);
		step = size / 2;
		mid = first;
		std::advance(mid, step);
		if (n < *mid)
			end = mid;
		else
		{
			first = mid;
			++first;
		}
	}
	return (first);
}

void	PmergeMe::_insertVector( std::vector<int> &main, std::vector<int> &small, std::vector<int> &big )
{
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	end;
	unsigned int				i;

	i = 0;
	while (i < small.size())
	{
		end = std::find(main.begin(), main.end(), big[i]);
		it = _binaryVector(main, small[i], end);
		main.insert(it, small[i]);
		i++;
	}
}

std::vector<int>	PmergeMe::_sortVector( std::vector<int> v )
{
	std::vector<int>	main;
	std::vector<int>	small;
	std::vector<int>	big;
	int					straggler;
	bool				has_straggler;
	unsigned int		i;

	if (v.size() <= 1)
		return (v);
	has_straggler = false;
	if (v.size() % 2 != 0)
	{
		straggler = v.back();
		v.pop_back();
		has_straggler = true;
	}
	i = 0;
	while (i < v.size())
	{
		if (v[i] < v[i + 1])
		{
			small.push_back(v[i]);
			big.push_back(v[i + 1]);
		}
		else
		{
			small.push_back(v[i + 1]);
			big.push_back(v[i]);
		}
		i += 2;
	}
	main = _sortVector(big);
	_insertVector(main, small, big);
	if (has_straggler)
		main.insert(_binaryVector(main, straggler, main.end()), straggler);
	return (main);
}

void	PmergeMe::_printVector( std::string msg, std::vector<int> v ) const
{
	unsigned int	i;

	std::cout << msg;
	i = 0;
	while (i < v.size())
	{
		std::cout << " " << v[i];
		i++;
	}
	std::cout << std::endl;
}

void	PmergeMe::_parseVector( int ac, char **av )
{
	int	n;
	int	i;

	if (ac < 2)
		throw std::runtime_error("Error");
	_vector.clear();
	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			throw std::runtime_error("Error");
		n = to_int(av[i]);
		_vector.push_back(n);
		i++;
	}
}

// Deque
void	PmergeMe::_parseDeque( int ac, char **av )
{
	int	n;
	int	i;

	if (ac < 2)
		throw std::runtime_error("Error");
	_deque.clear();
	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			throw std::runtime_error("Error");
		n = to_int(av[i]);
		_deque.push_back(n);
		i++;
	}
}

std::deque<int>::iterator	PmergeMe::_binaryDeque( std::deque<int> &d, int n, std::deque<int>::iterator end )
{
	std::deque<int>::iterator	first;
	std::deque<int>::iterator	mid;
	int							size;
	int							step;

	first = d.begin();
	while (first != end)
	{
		size = std::distance(first, end);
		step = size / 2;
		mid = first;
		std::advance(mid, step);
		if (n < *mid)
			end = mid;
		else
		{
			first = mid;
			++first;
		}
	}
	return (first);
}

void	PmergeMe::_insertDeque( std::deque<int> &main,
	std::deque<int> &small, std::deque<int> &big )
{
	std::deque<int>::iterator	it;
	std::deque<int>::iterator	end;
	unsigned int				i;

	i = 0;
	while (i < small.size())
	{
		end = std::find(main.begin(), main.end(), big[i]);
		it = _binaryDeque(main, small[i], end);
		main.insert(it, small[i]);
		i++;
	}
}

std::deque<int>	PmergeMe::_sortDeque( std::deque<int> d )
{
	std::deque<int>	main;
	std::deque<int>	small;
	std::deque<int>	big;
	int				straggler;
	bool			has_straggler;
	unsigned int	i;

	if (d.size() <= 1)
		return (d);
	has_straggler = false;
	if (d.size() % 2 != 0)
	{
		straggler = d.back();
		d.pop_back();
		has_straggler = true;
	}
	i = 0;
	while (i < d.size())
	{
		if (d[i] < d[i + 1])
		{
			small.push_back(d[i]);
			big.push_back(d[i + 1]);
		}
		else
		{
			small.push_back(d[i + 1]);
			big.push_back(d[i]);
		}
		i += 2;
	}
	main = _sortDeque(big);
	_insertDeque(main, small, big);
	if (has_straggler)
		main.insert(_binaryDeque(main, straggler, main.end()), straggler);
	return (main);
}

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS				*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const PmergeMe &obj)
{
	(void)obj;
	out << "This is the overload of '<<' for the PmergeMe class" << std::endl;
	return out;
}