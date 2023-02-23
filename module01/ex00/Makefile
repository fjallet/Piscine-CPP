NAME = zombie

HEADER = Zombie.hpp

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJETS = ${SRCS:.c=.o}

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

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