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
	(void)line_number;
	if (*stack == NULL || stack == NULL)
		exit_cannot_action_on_stack("L%d: can't pint, stack empty\n");

	printf("%d\n", (*stack)->n);
	fflush(stdout);
}
