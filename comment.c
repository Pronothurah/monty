#include "monty.h"

/**
* is_comment_line - Check if the line starts with a comment character (#)
* @line: line to check
* Return: skips line
*/
bool is_comment_line(const char *line)
{

	return (line[0] == '#');
}
