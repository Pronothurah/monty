#include "monty.h"

/**
 * get_opcodes - get an array of opcodes instruction_t
 *
 * Return: array of opcodes instruction_t
 */
instruction_t *get_opcodes()
{
	static instruction_t opcodes[] = {
		{"push", push_to_stack},
		{"pall", print_all_element_of_stack},
		{"pint", print_value_at_top},
		{"pop", pop_value_at_top},
		{"swap", swap_top_two_values},
		{"add", add_top_two_values},
		{"nop", do_nothing_on_stack},
		{"sub", subtract_top_from_second},
		{"div", divide_top_two_values},
		{"mul", multiply_top_and_second},
		{"mod", mod_top_by_second},
		{"pchar", print_char_at_top},
		{"pstr", pstr_top_of_stack},
		{"rotl", rotate_stack_to_top},
		{"rotr", rotate_stack_to_bottom},
		{NULL, NULL}};

	return (opcodes);
}

monty_t monty_instance = {NULL, 0, NULL, NULL, NULL};
