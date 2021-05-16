#include "monty.h"

/**
 * value_check - Checks the arguments of a function are valid (only ints)
 * @stack: double linked list
 * @line_number: line in execution
 * @val: the string to be checked and turned into int if valid
 * Return: string turned into int if is a valid number or error message if not
 */

int value_check(stack_t *stack, char *val, unsigned int line_number)
{
	int i = 1;

	if (val[0] == 45 || (val[0] >= 48 && val[0] <= 57))
	{
		while (val[i])
		{
			if (val[i] < 48 || val[i] > 57)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				global_free(stack);
			}
			i++;
		}
		return (atoi(val));
	}
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	global_free(stack);
	return (1);
}
/**
 * batman - cheks for lines with only spaces and tabs in it
 * @line_buf: line to read
 * Return: 0 if not empty line, 1 otherwise
 */

int batman(char *line_buf)
{
	int i = 0;

	while (line_buf[i])
	{
		if (line_buf[i] != ' ' && line_buf[i] != '\t')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
