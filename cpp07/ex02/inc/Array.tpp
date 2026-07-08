/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 11:48:04 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/22 11:48:04 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Develop a class template Array that contains elements of type T and that implements
// the following behavior and functions:
// • Construction with no parameter: Creates an empty array.
// • Construction with an unsigned int n as a parameter: Creates an array of n elements
// initialized by default.
// Tip: Try to compile int * a = new int(); then display *a.
// • Construction by copy and assignment operator. In both cases, modifying either the
// original array or its copy after copying musn’t affect the other array.
// • You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.
// • Elements can be accessed through the subscript operator: [ ].
// • When accessing an element with the [ ] operator, if its index is out of bounds, an
// std::exception is thrown.
// • A member function size() that returns the number of elements in the array.

/* ****************************************************************************	*/
/*								CONSTRUCTORS									*/
/* ****************************************************************************	*/
template <typename T>
Array<T>::Array( void ) : _size(0), _arr(0)
{
	//std::cout << "\033[90mDefault Array constructor called\033[0m" << std::endl;
	return ;
}

template <typename T>
Array<T>::Array( const unsigned int size ) : _size(size), _arr(0)
{
	//std::cout << "\033[90mUnsigned int Array constructor called\033[0m" << std::endl;
	if (_size)
		_arr = new T[_size]();
	return ;
}

template <typename T>
Array<T>::Array(Array<T> const &cpy) : _size(cpy._size), _arr(0)
{
	//std::cout << "\033[90mCopy Array constructor called\033[0m" << std::endl;
	if (_size)
	{
		_arr = new T[_size]();
		for (unsigned int i = 0; i < _size; ++i)
			_arr[i] = cpy._arr[i];
	}
}

/* ****************************************************************************	*/
/*								OPERATORS										*/
/* ****************************************************************************	*/
template <typename T>
Array<T>	&Array<T>::operator=(const Array &rhs)
{
	T	*copy = 0;

	if (this == &rhs)
		return (*this);
	if (rhs._size)
	{
		copy = new T[rhs._size]();
		for (unsigned int i = 0; i < rhs._size; ++i)
			copy[i] = rhs._arr[i];
	}
	delete [] _arr;
	_arr = copy;
	_size = rhs._size;
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return (_arr[index]);
}

template <typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::exception();
	return (_arr[index]);
}

/* ****************************************************************************	*/
/*								DESTRUCTOR				*/
/* ****************************************************************************	*/
template <typename T>
Array<T>::~Array( void )
{
	//std::cout << "\033[90mArray destructor called\033[0m" << std::endl;
	delete [] _arr;
	return ;
}

/* ****************************************************************************	*/
/*									GETERS				*/
/* ****************************************************************************	*/
template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}
