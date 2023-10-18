#include "monty.h"

/**
 * free_stack - free stack elements
 * @head: pointer to the list of stack_t
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
