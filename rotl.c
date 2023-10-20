#include "monty.h"

/**
* rotate_stack_to_top - rotates stack to the top
* @stack: pointer to the list of stack_t
* @line_number: line number from file
*
* Return: void
*/

void rotate_stack_to_top(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (current->next != NULL)
			current = current->next;

		current->next = *stack;
		(*stack)->prev = current;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		current->next->next = NULL;
	}
}
