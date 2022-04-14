CFLAGS=-Wall -Wextra -g

sh34:
	${CC} ${CFLAGS} main.c -lreadline rl_gets.c
