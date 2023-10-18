#include "monty.h"

/**
 * get_fp_content - get file content line by line
 * @stack: pointer to the list of stack_t
 * @fp: file object
 *
 * Return: void
 */
void get_fp_content(FILE *fp, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0, i = 0, j;
	ssize_t read;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		j = 0;
		for (i = 0; line[i]; i++)
		{
			if (line[i] != ' ')
			{
				line[j] = line[i];
				j++;
			}
		}

		line[j - 1] = line[j - 1] == '\n' ? '\0' : line[j - 1];
		execute_by_line(line, stack);
	}

	free(line);
}

/**
 * parse_input - parse line from file
 * @stack: pointer to the list of stack_t
 * @value: line from file
 *
 * Return: NULL
 */
char **parse_input(char *value, stack_t **stack)
{
	FILE *fp;

	fp = fopen(value, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open %s\n", value);
		exit(EXIT_FAILURE);
	}

	get_fp_content(fp, stack);
	fclose(fp);

	return (NULL);
}
