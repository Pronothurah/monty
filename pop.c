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

	(void)line_number;
	if (*stack == NULL || stack == NULL)
		exit_cannot_action_on_stack("L%d: can't pop an empty stack\n");

	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
}
