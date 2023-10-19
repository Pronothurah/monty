#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *globalStack;
extern int lineNumber;
extern char *opcode;
extern char *line;
extern FILE *fp;

instruction_t *get_opcodes();
char **parse_input(char *value);
void get_fp_content(FILE *fp);
void execute_by_line(char *line);
void remove_any_digit(char *str);
void push_to_stack(stack_t **stack, unsigned int line_number);
void print_all_element_of_stack(stack_t **stack, unsigned int line_number);
void print_value_at_top(stack_t **stack, unsigned int line_number);
void pop_value_at_top(stack_t **stack, unsigned int line_number);
void swap_top_two_values(stack_t **stack, unsigned int line_number);
void add_top_two_values(stack_t **stack, unsigned int line_number);
void do_nothing_on_stack(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *head);
void exit_malloc(void);
void exit_unknown_instruction(void);
void exit_unknown_push_command(void);
void exit_cannot_action_on_stack(char *message);

#endif /* MONTY_H */
