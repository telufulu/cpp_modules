/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:53:15 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/28 15:06:44 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// cout
#include <cctype>		// isdigit
#include <cstdlib>		// atoi
#include <cstddef>		// size_t
#include <climits>		// INT_MAX
#include <stdexcept>	// runtime_error
#include <algorithm>	// find, lower_bound
#include <ctime>		// clock
#include <iomanip>		// fixed, setprecision
#include "PmergeMe.hpp"

/* ************************************************************************** */
/*                              AUX FUNCTIONS                                  */
/* ************************************************************************** */

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
	return (static_cast<int>(n));
}

static bool	contains_number( const std::vector<int> &v, int n )
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (v[i] == n)
			return (true);
	}
	return (false);
}

static std::vector<size_t>	get_jacobsthal_order( size_t size )
{
	std::vector<size_t>	order;
	size_t				jacob_prev;
	size_t				jacob_curr;
	size_t				jacob_next;
	size_t				end;

	if (size == 0)
		return (order);
	order.push_back(0);
	jacob_prev = 1;
	jacob_curr = 1;
	while (order.size() < size)
	{
		// Take the current number, add two copies of the previous number, and that will be the next one.
		jacob_next = jacob_curr + 2 * jacob_prev;
		end = jacob_next;
		if (end > size)
			end = size;
		while (end > jacob_curr)
		{
			order.push_back(end - 1);
			if (order.size() == size)
				break ;
			--end;
		}
		jacob_prev = jacob_curr;
		jacob_curr = jacob_next;
	}
	return (order);
}

/* ************************************************************************** */
/*                              CONSTRUCTORS                                   */
/* ************************************************************************** */

PmergeMe::PmergeMe( void )
{
	return ;
}

PmergeMe::PmergeMe( int argc, char **argv )
{
	int	n;

	if (argc < 2)
		throw std::runtime_error("not enough arguments");
	_vector.clear();
	_deque.clear();
	for (int i = 1; i < argc; ++i)
	{
		if (!is_number(argv[i]))
			throw std::runtime_error("all arguments must be numbers");
		n = to_int(argv[i]);
		if (n <= 0)
			throw std::runtime_error("numbers must be positive");
		if (contains_number(_vector, n))
			throw std::runtime_error("duplicate numbers are not allowed");
		_vector.push_back(n);
		_deque.push_back(n);
	}
	return ;
}

PmergeMe::PmergeMe( const PmergeMe &cpy )
{
	*this = cpy;
	return ;
}

/* ************************************************************************** */
/*                               OPERATORS                                     */
/* ************************************************************************** */

PmergeMe	&PmergeMe::operator=( const PmergeMe &rhs )
{
	if (this != &rhs)
	{
		_vector = rhs._vector;
		_deque = rhs._deque;
	}
	return (*this);
}

/* ************************************************************************** */
/*                               DESTRUCTOR                                    */
/* ************************************************************************** */

PmergeMe::~PmergeMe( void )
{
	return ;
}

/* ************************************************************************** */
/*                            MEMBER FUNCTIONS                                 */
/* ************************************************************************** */

void	PmergeMe::printVector( void ) const
{
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << " " << _vector[i];
	std::cout << std::endl;
}

void	PmergeMe::solveVector( void )
{
	clock_t	start;
	clock_t	end;
	double	vector_time;

	std::cout << "Before:";
	printVector();

	start = clock();
	_vector = _sortVector(_vector);
	end = clock();

	vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "After:";
	printVector();

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector : " << vector_time << " us" << std::endl;
}

std::vector<int>	PmergeMe::_sortVector( std::vector<int> v )
{
	std::vector<int>				main;
	std::vector<int>				small;
	std::vector<int>				big;
	std::vector<size_t>			order;
	std::vector<int>::iterator	it;
	std::vector<int>::iterator	end;
	int							rest;
	bool						has_rest;
	size_t						size;
	size_t						index;

	size = v.size();
	if (size <= 1)
		return (v);
	has_rest = false;
	if (size % 2 != 0)
	{
		rest = v.back();
		v.pop_back();
		has_rest = true;
		--size;
	}
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
	order = get_jacobsthal_order(small.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		index = order[i];
		end = std::find(main.begin(), main.end(), big[index]);
		it = std::lower_bound(main.begin(), end, small[index]);
		main.insert(it, small[index]);
	}
	if (has_rest)
	{
		it = std::lower_bound(main.begin(), main.end(), rest);
		main.insert(it, rest);
	}
	return (main);
}

void	PmergeMe::solveDeque( void )
{
	clock_t	start;
	clock_t	end;
	double	deque_time;

	start = clock();
	_deque = _sortDeque(_deque);
	end = clock();

	deque_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _deque.size()
		<< " elements with std::deque  : " << deque_time << " us" << std::endl;
}

std::deque<int>	PmergeMe::_sortDeque( std::deque<int> d )
{
	std::deque<int>				main;
	std::deque<int>				small;
	std::deque<int>				big;
	std::vector<size_t>			order;
	std::deque<int>::iterator	it;
	std::deque<int>::iterator	end;
	int							rest;
	bool						has_rest;
	size_t						size;
	size_t						index;

	size = d.size();
	if (size <= 1)
		return (d);
	has_rest = false;
	if (size % 2 != 0)
	{
		rest = d.back();
		d.pop_back();
		has_rest = true;
		--size;
	}
	for (size_t i = 0; i < size; i += 2)
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
	}
	main = _sortDeque(big);
	order = get_jacobsthal_order(small.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		index = order[i];
		end = std::find(main.begin(), main.end(), big[index]);
		it = std::lower_bound(main.begin(), end, small[index]);
		main.insert(it, small[index]);
	}
	if (has_rest)
	{
		it = std::lower_bound(main.begin(), main.end(), rest);
		main.insert(it, rest);
	}
	return (main);
}

/* ************************************************************************** */
/*                          NON MEMBER FUNCTIONS                               */
/* ************************************************************************** */

std::ostream	&operator<<( std::ostream &out, const PmergeMe &obj )
{
	(void)obj;
	obj.printVector();
	return (out);
}