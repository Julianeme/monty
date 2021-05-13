#include "monty.h"

void get_op(char *s, stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		/*{"pint", pint},
		{"pop", pop},*/
		{"NULL", NULL}
	};
	int i = 0;

	while(ops[i].opcode)
	{
		if (strcmp(s, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
		}
		i++;
	}
}