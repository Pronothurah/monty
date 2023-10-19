#include "monty.h"

/**
* subtract_top_from_second - subtracts the top element of the
* stack from the second top element of the stack.
* @stack: pointer to the list of stack_t
* @line_number: line number from file
*
* Return: void
*/

void subtract_top_from_second(stack_t **stack, unsigned int line_number)
{
	size_t temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next->n - (*stack)->n;
	pop_value_at_top(stack, line_number);
	(*stack)->n = temp;
}

