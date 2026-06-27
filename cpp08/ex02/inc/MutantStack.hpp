/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:36:07 by telufulu          #+#    #+#             */
/*   Updated: 2026/06/27 17:36:08 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ***********************************************************
 * =====================  std::stack<T>  ====================
 *
 *   template <class T, class Container = std::deque<T> >
 *   class stack {
 *   public:
 *       typedef Container                      container_type; // = deque<T>
 *       typedef typename Container::value_type value_type;
 *       typedef typename Container::size_type  size_type;
 *
 *       // ---- Orthodox Canonical Form ----
 *       explicit stack(const Container& c = Container());  // default ctor
 *       stack(const stack& other);                         // copy constructor
 *       stack& operator=(const stack& other);              // copy assignment
 *       ~stack();                                          // destructor
 *       //  NOTE: the OCF here is mostly IMPLICIT. The compiler generates
 *       //  copy/assign/dtor that simply copy/destroy the member 'c'.
 *       //  When 'stack' is built, member 'c' is constructed AUTOMATICALLY
 *       //  (deque's own default ctor) BEFORE the ctor body runs.
 *
 *       // ---- public interface (LIFO) ----
 *       void       push(const T& value);  // -> c.push_back(value)
 *       void       pop();                 // -> c.pop_back()
 *       T&         top();                 // -> c.back()
 *       const T&   top() const;
 *       bool       empty() const;         // -> c.empty()
 *       size_type  size()  const;         // -> c.size()
 *
 *   protected:
 *       Container  c;   // <-- THE real storage (a deque by default).
 *                       //     Holds every element; this is what
 *                       //     MutantStack reaches to expose iterators.
 *   };
 *
 *  NOTE: stack has NO begin()/end(). They live in 'c', and 'c' is
 *        protected -> only a derived class (MutantStack) can reach it.
 *
 * ---------------------- member functions -------------------
 *
 *   void push(const T& value);
 *       Pushes 'value' onto the TOP of the stack.
 *
 *   void pop();
 *       Removes the top element. Returns NOTHING and
 *       must NOT be called on an empty stack.
 *
 *   T& top();  /  const T& top() const;
 *       Returns a REFERENCE to the top element.
 *
 *   bool empty() const;
 *       true if there are no elements; check it BEFORE pop()/top().
 *
 *   size_type size() const;
 *       Number of stored elements.
 * ***********************************************************/

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>        //cout

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
        // Iterators types (borrowed from std::deque)
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		// Constructors
		MutantStack( void );
		MutantStack( const MutantStack &cpy );

		// Arithmetic operators
		MutantStack &operator=( const MutantStack &rhs );

		// Destructor
		~MutantStack( void );

        // Member functions
        iterator   begin( void );
        iterator   end( void );
        const_iterator   begin( void ) const;
        const_iterator   end( void ) const;
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const MutantStack<T> &obj);

# include "MutantStack.tpp"
#endif
