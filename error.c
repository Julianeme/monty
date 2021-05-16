#include "monty.h"
/**
 * push_error -  xxx
 * @i: xxxx
 * Return: void
 */

void push_error(int i)
{
	fprintf(stderr, "L%u: usage: push integer\n", i);
	free(global.line_buf);
	exit(EXIT_FAILURE);
}
