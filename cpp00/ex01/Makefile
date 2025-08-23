#******************************************************************************#
#								COMPILER									   #
#******************************************************************************#
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98

#******************************************************************************#
#								SOURCES										   #
#******************************************************************************#
NAME		=	phonebook
FILES		=	phonebook.cpp
INCLUDES	=	phonebook.hpp
O			=	objs/
OBJS		=	$(FILES:%.cpp=$O%.o)

#******************************************************************************#
#								RULES										   #
#******************************************************************************#
all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$O%.o:		%.cpp
	@[ -d $O ] || mkdir -p $O
	@$(CXX) $(CXXFLAGS) -I $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $O

fclean:	clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
