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

/**
 * exit_malloc - exit on malloc error
 *
 * Return: void
 */
void exit_malloc(void)
{
	free_stack(monty_instance.global_stack);
	free(monty_instance.line);
	fclose(monty_instance.fp);
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * exit_unknown_instruction - exit on unknown instruction error
 *
 * Return: void
 */
void exit_unknown_instruction(void)
{
	free(monty_instance.line);
	free_stack(monty_instance.global_stack);
	fclose(monty_instance.fp);
	remove_any_digit(monty_instance.opcode);
	fprintf(stderr, "L%d: unknown instruction %s\n",
			monty_instance.line_number,
			monty_instance.opcode);
	free(monty_instance.opcode);
	exit(EXIT_FAILURE);
}

/**
 * exit_unknown_push_command - exit on unknown push instruction error
 *
 * Return: void
 */
void exit_unknown_push_command(void)
{
	free(monty_instance.opcode);
	free(monty_instance.line);
	free_stack(monty_instance.global_stack);
	fclose(monty_instance.fp);
	fprintf(stderr, "L%d: usage: push integer\n", monty_instance.line_number);
	exit(EXIT_FAILURE);
}

/**
 * exit_cannot_action_on_stack - exit on action not possible on stack
 * @message: message to send to stderr
 *
 * Return: void
 */
void exit_cannot_action_on_stack(char *message)
{
	free(monty_instance.line);
	free_stack(monty_instance.global_stack);
	fclose(monty_instance.fp);
	fprintf(stderr, message, monty_instance.line_number);
	exit(EXIT_FAILURE);
}
