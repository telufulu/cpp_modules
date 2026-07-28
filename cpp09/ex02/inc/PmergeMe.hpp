/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <telufulu@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:53:22 by telufulu          #+#    #+#             */
/*   Updated: 2026/07/28 14:53:25 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <iterator>
# include <ctime>
# include <climits>
# include <cctype>
# include <stdexcept>

class PmergeMe
{
	public:
		PmergeMe ( int argc, char **argv );
		PmergeMe( const PmergeMe &cpy );
		PmergeMe &operator=( const PmergeMe &rhs );
		~PmergeMe( void );

		void	solveVector( void );
		void	solveDeque( void );
		void	printVector( void ) const;

	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		PmergeMe( void );

		// Vector
		std::vector<int>	_sortVector( std::vector<int> v );
		
		// Deque
		std::deque<int>		_sortDeque( std::deque<int> d );

};

#endif
