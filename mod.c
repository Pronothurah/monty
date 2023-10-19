#include "monty.h"

/**
* mod_top_by_second - computes the rest of the division
* of the second top element
* of the stack by the top element of the stack
* @stack: pointer to the list of stack_t
* @line_number: line number from file
*
* Return: void
*/
void mod_top_by_second(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *last = *stack;
	int len = 0;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		exit_cannot_action_on_stack("L%d: can't mod, stack too short\n");

	if ((*stack)->n == 0)
		exit_cannot_action_on_stack("L%d: division by zero\n");

	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	if (len < 2)
		exit_cannot_action_on_stack("L%d: can't mod, stack too short\n");

	len = last->next->n % last->n;

	pop_value_at_top(stack, line_number);
	pop_value_at_top(stack, line_number);
	push_to_stack(stack, len);
}
