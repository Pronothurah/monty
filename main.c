#include "monty.h"

/**
 * main - check code
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *input;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	input = argv[1];
	parse_input(input);
	free_stack(globalStack);
	globalStack = NULL;

	return (0);
}
