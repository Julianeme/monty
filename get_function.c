#include "monty.h"

/**
 * get_op - picks the righ function according to the instruction given
 * @stack: a double pointer to the stack of the linked list
 * @line_number: file line number where the op was requested
 * @s: command string to be compared to the function pointer name
 * Return: nothing if succes, EXIT_FAILURE if it fails
 */

void get_op(char *s, stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}
	};
	int i = 0;
	while (ops[i].opcode != NULL)
	{
		if (strcmp(s, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
		}
		
		/*else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, s);
			free(global.line_buf);
			exit(EXIT_FAILURE);
		}*/
		i++;
	}
}
