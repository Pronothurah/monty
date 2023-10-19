#include "monty.h"

/**
 * remove_any_digit - remove digit from string
 * @fp: string input
 *
 * Return: void
 */
void remove_any_digit(char *str)
{
	int i, j;

	j = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[j] = str[i];
			j++;
		}
	}

	str[j] = '\0';
}

/**
 * get_fp_content - get file content line by line
 * @fp: file object
 *
 * Return: void
 */
void get_fp_content(FILE *fp)
{
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
		execute_by_line(line);
	}

	free(line);
}

/**
 * parse_input - parse line from file
 * @value: line from file
 *
 * Return: NULL
 */
char **parse_input(char *value)
{
	fp = fopen(value, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open %s\n", value);
		exit(EXIT_FAILURE);
	}

	get_fp_content(fp);
	fclose(fp);

	return (NULL);
}
