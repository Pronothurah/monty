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
	free_stack(globalStack);
	free(line);
	fclose(fp);
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
	free(line);
	free_stack(globalStack);
	fclose(fp);
	remove_any_digit(opcode);
	fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
	free(opcode);
	exit(EXIT_FAILURE);
}

/**
 * exit_unknown_push_command - exit on unknown push instruction error
 *
 * Return: void
 */
void exit_unknown_push_command(void)
{
	free(opcode);
	free(line);
	free_stack(globalStack);
	fclose(fp);
	fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
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
	free(line);
	free_stack(globalStack);
	fclose(fp);
	fprintf(stderr, message, lineNumber);
	exit(EXIT_FAILURE);
}
