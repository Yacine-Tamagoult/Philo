NAME = philo

SRCS = main.c tools.c init.c action.c parsing.c robocop.c action2.c
OBJS = ${SRCS:.c=.o}

CFLAGS = -g3 -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	cc -g3 ${CFLAGS} ${OBJS} -o ${NAME}
	
clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re : fclean all

.PHONY: clean fclean all re	
