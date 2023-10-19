#include "monty.h"

/**
* divide_top_two_values - divide the second top element by the top element
* @stack: pointer to the list of stack_t
* @line_number: line number from file
*
* Return: void
*/
void divide_top_two_values(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *last = *stack;
	int len = 0;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		exit_cannot_action_on_stack("L%d: can't div, stack too short\n");

	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	if (len < 2)
		exit_cannot_action_on_stack("L%d: can't div, stack too short\n");

	if (last->n == 0)
		exit_cannot_action_on_stack("L%d: division by zero\n");

	len = last->next->n / last->n;

	pop_value_at_top(stack, last->next->n);
	pop_value_at_top(stack, last->n);
	push_to_stack(stack, len);
}
