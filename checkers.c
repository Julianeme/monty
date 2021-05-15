#include "monty.h"

/**
 * value_check - Checks the arguments of a function are valid (only ints)
 * @val: the string to be checked and turned into int if valid
 * Return: string turned into int if is a valid number or error message if not
 */

int value_check(char *val)
{
	int i = 1;

	if (val[0] == 45 || (val[0] >= 48 && val[0] <= 57))
	{
		while (val[i])
		{
			if (val[i] < 48 || val[i] > 57)
			{
				fprintf(stderr, "Error: L%u: usage: push integer\n", i);
				/*free(global.line_buf);*/
				/*fclose(global.fd);*/
				exit(EXIT_FAILURE);
			}
			i++;
		}
		return (atoi(val));
	}
	fprintf(stderr, "Error: L%u: usage: push integer\n", i);
	/*free(global.line_buf);*/
	/*fclose(global.fd);*/
	exit(EXIT_FAILURE);
}
