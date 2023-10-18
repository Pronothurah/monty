#include "monty.h"

void print_all_element_of_stack(
	stack_t **stack,
	unsigned int __attribute__((__unused__)) line_number)
{
	stack_t *last;

	last = *stack;

	while (last != NULL)
	{
		printf("%d\n", last->n);
		last = last->next;
	}
}
