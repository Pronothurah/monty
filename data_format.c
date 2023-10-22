#include "monty.h"

/**
* stack_set_to_lifo - Pop the top element of the stack.
* @stack: Pointer to the list of stack_t.
* @line_number: Line number from the file.
* Return: void
*/
void stack_set_to_lifo(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (current == NULL)
	{
		exit_cannot_action_on_stack("L%d: can't pop an empty stack\n");
	}

	if (current->next != NULL)
	{
		current->next->prev = NULL;
	}

	*stack = current->next;
	free(current);
}

/**
* queue_set_to_fifo - Dequeue the top element of the stack (FIFO).
* @stack: Pointer to the list of stack_t.
* @line_number: Line number from the file.
* Return: void
*/
void queue_set_to_fifo(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;
	if (current == NULL)
	{
		exit_cannot_action_on_stack("L%d: can't dequeue an empty queue\n");
	}

	while (current->next != NULL)
	{
		current->n = current->next->n;
		current = current->next;
	}

	if (current->prev != NULL)
		current->prev->next = NULL;
	else
		*stack = NULL;

	free(current);
}
