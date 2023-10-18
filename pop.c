#include "monty.h"

/**
 * pop_value_at_top - remove stack top element
 * @stack: pointer to the list of stack_t
 * @line_number: line number from file
 *
 * Return: void
 */
void pop_value_at_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
