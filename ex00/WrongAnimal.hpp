/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:00:17 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/14 09:00:18 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class   WrongAnimal
{
    public:
    	//Constructors
        WrongAnimal( void );
		WrongAnimal( const WrongAnimal &cpy );

		//Operators
		WrongAnimal  &operator=( const WrongAnimal &rhs );

		//Destructor
		~WrongAnimal( void );

		// Member functions
        void	makeSound( void ) const;
        std::string		getType( void ) const;

    protected:
        std::string type;
};
#endif /* WrongAnimal */