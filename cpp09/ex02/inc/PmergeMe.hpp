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

	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		PmergeMe( void );

		void	_printVector( void ) const;

		std::vector<int>::iterator	_binaryVector( std::vector<int> &v, int n, std::vector<int>::iterator end );
		std::vector<int>			_sortVector( std::vector<int> v );
		void						_insertVector( std::vector<int> &main, std::vector<int> &small, std::vector<int> &big );
								
		std::deque<int>::iterator	_binaryDeque( std::deque<int> &d, int n, std::deque<int>::iterator end );
		std::deque<int>				_sortDeque( std::deque<int> d );
		void						_insertDeque( std::deque<int> &main, std::deque<int> &small, std::deque<int> &big );

};

#endif