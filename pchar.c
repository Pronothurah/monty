#include "monty.h"

/**
* print_char_at_top - prints the char at the top of
* the stack, followed by a new line
* @stack: pointer to the list of stack_t
* @line_number: line number from file
*
* Return: void
*/

void print_char_at_top(stack_t **stack, unsigned int line_number)
{
	int value;

	(void)line_number;
	if (*stack == NULL)
	{
		exit_cannot_action_on_stack("L%u: can't pchar, stack empty\n");
	}
	value = (*stack)->n;
	if (!(value >= 0 && value <= 127))
	{
		exit_cannot_action_on_stack("L%u: can't pchar, value out of range");
	}
	putchar(value);
	putchar('\n');
}
