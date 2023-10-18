#include "monty.h"

/**
 * push_to_stack - push new element at the top of stack
 * @stack: pointer to the list of stack_t
 * @line_number: line number from file
 *
 * Return: void
 */
void push_to_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return;
	new->n = line_number;
	new->next = NULL;
	new->prev = NULL;

	if (*stack == NULL || stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}
