/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:53:15 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/28 13:53:20 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// cout
#include "PmergeMe.hpp"

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
			throw std::runtime_error("argument is too large");
		i++;
	}
	if (n < 0)
		throw std::runtime_error("numbers must be unsigned");
	return (static_cast<int>(n));
}

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/

PmergeMe::PmergeMe ( void )
{
	//std::cout << "\033[90mVoid PmergeMe constructor called\033[0m" << std::endl;
	return ;
}

PmergeMe::PmergeMe ( int argc, char **argv )
{
	//std::cout << "\033[90mDefault PmergeMe constructor called\033[0m" << std::endl;
	int	n;
	int	i;

	if (argc < 2)
		throw std::runtime_error("not enough arguments");
	_vector.clear();
	_deque.clear();
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			throw std::runtime_error("all arguments must be numbers");
		n = to_int(argv[i]);
		_vector.push_back(n);
		_deque.push_back(n);
		++i;
	}
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
/*								OPERATORS										*/
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
/*								MEMBER FUNCTIONS								*/
/* ****************************************************************************	*/
// Vector
void	PmergeMe::solveVector( void )
{
	clock_t	start;
	clock_t	end;
	double	vector_time;

	std::cout << "Before:\t";
	_printVector();
	start = clock();
	_vector = _sortVector(_vector);
	end = clock();
	vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After:\t";
	_printVector();
	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector\t: " << vector_time << " us" << std::endl;
}

void	PmergeMe::_printVector( void ) const
{
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << " " << _vector[i];
	std::cout << std::endl;
}

std::vector<int>	PmergeMe::_sortVector( std::vector<int> v )
{
	std::vector<int>	main;
	std::vector<int>	small;
	std::vector<int>	big;
	int					rest;
	bool				has_rest;
	size_t				size = v.size();

	if (size <= 1)
		return (v);
	has_rest = false;
	//pop the last if is odd
	if (size % 2 != 0)
	{
		rest = v.back();
		v.pop_back();
		has_rest = true;
	}
	//push each number to big/small group
	for (size_t i = 0; i < size; i += 2)
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
	}
	main = _sortVector(big);
	_insertVector(main, small, big);
	if (has_rest)
		main.insert(_binaryVector(main, rest, main.end()), rest);
	return (main);
}

void	PmergeMe::_insertVector( std::vector<int> &main, std::vector<int> &small, std::vector<int> &big )
{
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	end;

	for (size_t i = 0; i < small.size(); ++i)
	{
		end = std::find(main.begin(), main.end(), big[i]);
		it = _binaryVector(main, small[i], end);
		main.insert(it, small[i]);
	}
}

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

// Deque
void	PmergeMe::solveDeque( void )
{
	clock_t	start;
	clock_t	end;
	double	deque_time;

	start = clock();
	_deque = _sortDeque(_deque);
	end = clock();
	deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque\t: " << deque_time << " us" << std::endl;
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
	int				rest;
	bool			has_rest;
	unsigned int	i;

	if (d.size() <= 1)
		return (d);
	has_rest = false;
	if (d.size() % 2 != 0)
	{
		rest = d.back();
		d.pop_back();
		has_rest = true;
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
	if (has_rest)
		main.insert(_binaryDeque(main, rest, main.end()), rest);
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
