#include "monty.h"

/**
 * value_check - Checks the arguments of a function are valid (only ints)
 * @line_number: line in execution
 * @val: the string to be checked and turned into int if valid
 * Return: string turned into int if is a valid number or error message if not
 */

int value_check(char *val, unsigned int line_number)
{
	int i = 1;

	if (val[0] == 45 || (val[0] >= 48 && val[0] <= 57))
	{
		while (val[i])
		{
			if (val[i] < 48 || val[i] > 57)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				/*free(global.line_buf);*/
				/*fclose(global.fd);*/
				exit(EXIT_FAILURE);
			}
			i++;
		}
		return (atoi(val));
	}
	fprintf(stderr, "L%u: usage: push integer\n", line_number);
	/*free(global.line_buf);*/
	/*fclose(global.fd);*/
	exit(EXIT_FAILURE);
}
