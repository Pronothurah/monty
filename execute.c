#include "monty.h"

/**
 * get_number_from_line - get number from line
 * @j: index to start from line
 * @line: opcode to execute
 * @number: pointer to the new string
 *
 * Return: void
 */
void get_number_from_line(size_t j, char *line, char *number)
{
	size_t k;

	k = 0;
	for (; j < strlen(line); j++)
	{
		if (isalpha(line[j]))
			break;

		if (line[j] == '-' || isdigit(line[j]))
		{
			*(number + k) = line[j];
			k++;
		}
	}
}

/**
 * get_opcode_from_line - get opcode from line
 * @line: opcode to execute
 * @opcode: pointer to the new string
 *
 * Return: index of the last character of opcode
 */
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

/**
 * execute_by_line - execute line from file
 * @line: opcode to execute
 *
 * Return: void
 */
void execute_by_line(char *line)
{
	char number[5] = "x";
	size_t j = 0, k = 0;
	int num = 0;
	instruction_t *opcodes = get_opcodes();

	if (is_comment_line(line))
		return;

	if (strcmp(line, "") == 0)
		return;

	(monty_instance.line_number)++;
	monty_instance.opcode = (char *)malloc(5);
	if (monty_instance.opcode == NULL)
		exit_malloc();

	for (; j < 5; j++)
		monty_instance.opcode[j] = '\0';
	j = get_opcode_from_line(line, monty_instance.opcode);
	get_number_from_line(j, line, number);

	if (*number == 'x' && strcmp(monty_instance.opcode, "push") == 0)
		exit_unknown_push_command();

	num = atoi(number);
	k = 0;
	while (opcodes[k].opcode != NULL &&
		   strcmp(opcodes[k].opcode, monty_instance.opcode) != 0)
		k++;

	if (opcodes[k].opcode != NULL)
	{
		free(monty_instance.opcode);
		opcodes[k].f(&(monty_instance.global_stack), (unsigned int)num);
	}
	else
		exit_unknown_instruction();
}
