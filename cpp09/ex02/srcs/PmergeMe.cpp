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
#include <cstddef>		// deque
#include "PmergeMe.hpp"

/* ****************************************************************************	*/
/*								AUX FUNCTIONS									*/
/* ****************************************************************************	*/
static bool	is_number( char *s ) // instead of isdigit to check all chars
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

static int	to_int( char *s ) // instead of atoi throw specific errors
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

	if (argc < 2)
		throw std::runtime_error("not enough arguments");
	_vector.clear();
	_deque.clear();
	for (int i = 1; i < argc; ++i)
	{
		if (!is_number(argv[i]))
			throw std::runtime_error("all arguments must be numbers");
		n = to_int(argv[i]);
		_vector.push_back(n);
		_deque.push_back(n);
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

	std::cout << "Before:\t";
	printVector();
	start = clock();
	_vector = _sortVector(_vector);
	end = clock();
	vector_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After:\t";
	printVector();
	std::cout << "Time to process a range of " << _vector.size()
		<< " elements with std::vector\t: " << vector_time << " us" << std::endl;
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
		--size;
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

	// insert small numbers finding the start of the big vector
	std::vector<int>::iterator it;
	std::vector<int>::iterator end;
	
	for (size_t i = 0; i < small.size(); ++i)
    {
		// finds the position of the big number
        end = std::find(main.begin(), main.end(), big[i]);
        it = main.begin();
        while (it != end && small[i] > *it)
            ++it;
		// inserts the number before it
        main.insert(it, small[i]);
    }
    if (has_rest)
    {
		// simply inserts the remain number
        it = main.begin();
        while (it != main.end() && rest > *it)
            ++it;
        main.insert(it, rest);
    }
	return (main);
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

std::deque<int> PmergeMe::_sortDeque(std::deque<int> d)
{
    std::deque<int> main;
    std::deque<int> small;
    std::deque<int> big;
    int rest;
    bool has_rest;
    size_t size = d.size();

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

    std::deque<int>::iterator it;
    std::deque<int>::iterator end;
    for (size_t i = 0; i < small.size(); ++i)
    {
        end = std::find(main.begin(), main.end(), big[i]);
        it = main.begin();

        while (it != end && small[i] > *it)
            ++it;

        main.insert(it, small[i]);
    }
    if (has_rest)
    {
        it = main.begin();
        while (it != main.end() && rest > *it)
            ++it;
        main.insert(it, rest);
    }
    return (main);
}

/* ****************************************************************************	*/
/*							NON MEMBER FUNCTIONS				*/
/* ****************************************************************************	*/
std::ostream	&operator<<(std::ostream &out, const PmergeMe &obj)
{
	(void)obj;
	obj.printVector();
	return out;
}
