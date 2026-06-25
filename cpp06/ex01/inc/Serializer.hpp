#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>				// ostream

// Structs
struct	Data
{
	int	id;
	std::string	name;
};

class Serializer
{
	public:
		// Arithmetic operators
		Serializer &operator=( const Serializer &rhs );

		// Destructor
		~Serializer( void );

		// Member functions
		static uintptr_t	serialize( Data* ptr );
		static Data			*deserialize(uintptr_t raw);

	private:
		// Constructors
		Serializer( void );
		Serializer( const Serializer &cpy );

};

std::ostream &operator<<(std::ostream &out, const Serializer &obj);
#endif
