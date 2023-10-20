#include "monty.h"

/**
* pstr_top_of_stack - prints a string starting at the top of the stack
* @stack: pointer to the list of stack_t
* @line_number: line number from file
*
* Return: void
*/

void pstr_top_of_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int value;

	(void)line_number;

	while (current != NULL && current->n != 0)
	{
		value = current->n;

		if (value < 0 || value > 127)
			break;

		putchar(value);
		current = current->next;
	}

	putchar('\n');
}
