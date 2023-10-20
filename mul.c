#include "monty.h"

/**
* multiply_top_and_second - multiplies the top element of the
* stack by second top element of the stack.
* @stack: pointer to the list of stack_t
* @line_number: line number from file
*
* Return: void
*/

void multiply_top_and_second(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *last = *stack;
	int len = 0;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		exit_cannot_action_on_stack("L%d: can't mul, stack too short\n");

	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	if (len < 2)
		exit_cannot_action_on_stack("L%d: can't mul, stack too short\n");


	len = last->next->n * last->n;

	pop_value_at_top(stack, last->next->n);
	pop_value_at_top(stack, last->n);
	push_to_stack(stack, len);
}
