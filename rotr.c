#include "monty.h"

/**
* rotate_stack_to_bottom - rotates the stack to the bottom
* @stack: pointer to the list of stack_t
* @line_number: line number from file
*
* Return: void
*/
void rotate_stack_to_bottom(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *last = *stack;
	int len = 0;

	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		while (current->next != NULL)
		{
			len++;
			current = current->next;
		}

		while (last->next != current)
		{
			last = last->next;
		}

		last->next = NULL;
		current->next = *stack;
		*stack = current;
	}
}
