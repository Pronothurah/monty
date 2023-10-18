#include "monty.h"

/**
 * swap_top_two_values - swap stack top 2 elements
 * @stack: pointer to the list of stack_t
 * @line_number: line number from file
 *
 * Return: void
 */
void swap_top_two_values(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	stack_t *last = *stack;
	stack_t *current;
	int len = 0;

	if (*stack == NULL || stack == NULL)
	{
		free_stack(*stack);
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	current = last->next;
	current->prev = NULL;
	last->next = last->next->next;
	last->prev = current;
	current->next = last;
	*stack = current;
}
