#include "monty.h"

/**
 * print_all_element_of_stack - print stack elements from top
 * @stack: pointer to the list of stack_t
 * @line_number: line number from file
 *
 * Return: void
 */
void print_all_element_of_stack(
	stack_t **stack,
	unsigned int line_number)
{
	stack_t *last;
	(void)line_number;

	last = *stack;

	while (last != NULL)
	{
		printf("%d\n", last->n);
		fflush(stdout);
		last = last->next;
	}
}
