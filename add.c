#include "monty.h"

/**
 * add_top_two_values - add stack top 2 elements
 * @stack: pointer to the list of stack_t
 * @line_number: line number from file
 *
 * Return: void
 */
void add_top_two_values(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *last = *stack;
	int len = 0;

	if (*stack == NULL || stack == NULL)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}

	if (len < 2)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	len = last->n;
	len += last->next->n;

	pop_value_at_top(stack, last->n);
	pop_value_at_top(stack, last->next->n);
	push_to_stack(stack, len);
}
