#include "monty.h"

void get_number_from_line(size_t j, char *line, char *number)
{
	size_t k;

	k = 0;
	for (; j < strlen(line); j++)
	{
		if (isalpha(line[j]))
			break;

		if (isdigit(line[j]))
		{
			*(number + k) = line[j];
			k++;
		}
	}
}

int get_opcode_from_line(char *line, char *opcode)
{
	size_t i, j, k;

	for (i = 0; i < strlen(line); i++)
	{
		k = 0;
		if (strchr("psan", line[i]) != NULL)
		{
			for (j = i; j < (i + 4); j++)
			{
				*(opcode + k) = *(line + j);
				k++;
			}
			break;
		}
	}

	return (j);
}

void execute_by_line(char *line, stack_t **stack)
{
	char *opcode;
	char number[5] = "x";
	size_t j = 0, k = 0;
	int num = 0;
	instruction_t *opcodes = get_opcodes();

	opcode = (char *)malloc(5);
	if (opcode == NULL)
	{
		free_stack(*stack);
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	j = get_opcode_from_line(line, opcode);
	get_number_from_line(j, line, number);

	if (*number == 'x' && strcmp(opcode, "push") == 0)
	{
		free(opcode);
		free_stack(*stack);
		fprintf(stderr, "L<line_number>: usage: push integer");
		exit(EXIT_FAILURE);
	}

	num = atoi(number);
	k = 0;
	while (opcodes[k].opcode != NULL &&
		   strstr(opcodes[k].opcode, opcode) == NULL)
		k++;

	free(opcode);
	if (opcodes[k].opcode != NULL)
		opcodes[k].f(stack, (unsigned int)num);
}
