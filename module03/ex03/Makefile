NAME = DiamondTrap

HEADER = ScavTrap.hpp

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp  DiamondTrap.cpp

OBJETS = ${SRCS:.c=.o}

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98 -Wshadow -Wno-shadow

./.build/%.o : %.c
	${CC} -I. -o $@ -c $? ${FLAGS}

${NAME}	 : ${OBJETS}
		${FT_PRINTF}
		${CC} -o ${NAME} ${OBJETS}

all: ${NAME}

clean :
	rm -rf .build

fclean : clean
	rm -f ${NAME}

re :  fclean all

PHONY = all clean fclean re