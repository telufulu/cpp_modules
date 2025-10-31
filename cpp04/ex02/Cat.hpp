/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telufulu <@student.42madrid.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:26:59 by telufulu          #+#    #+#             */
/*   Updated: 2025/10/15 09:04:36 by telufulu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class   Cat:    public AAnimal
{
    public:
        //Constructor
        Cat( void );
        Cat( const Cat &cpy );
		//Operators
		Cat  &operator=( const Cat &rhs );
        //Destructor
        ~Cat( void );
		//Member functions
		void	setIdea( std::string idea );
		const	std::string &getIdea( unsigned int i ) const;
        void	makeSound( void ) const;

	private:
        Brain   *_brain;
};
#endif /* CAT */
