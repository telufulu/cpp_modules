/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:00:17 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 09:00:18 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class   Animal
{
    public:
    	//Constructors
        Animal( void );
		Animal( const Animal &cpy );

		//Operators
		Animal  &operator=( const Animal &rhs );

		//Destructor
		virtual ~Animal( void );

		// Member functions
        virtual void	makeSound( void ) const;
        std::string		getType( void ) const;

    protected:
        std::string type;
};
#endif /* ANIMAL */