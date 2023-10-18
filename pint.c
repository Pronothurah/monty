#include "monty.h"

/**
 * print_value_at_top - print stack top element
 * @stack: pointer to the list of stack_t
 * @line_number: line number from file
 *
 * Return: void
 */
void print_value_at_top(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
