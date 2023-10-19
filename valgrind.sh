clear

gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -g -o monty
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./monty bytecodes/00.m